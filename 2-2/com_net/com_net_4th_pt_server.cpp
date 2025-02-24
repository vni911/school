#pragma comment(lib, "ws2_32.lib")
#include <WS2tcpip.h>
#include <stdio.h>
#include <windows.h>
#define MAX_BUF 100000

//22110670 김정운//

DWORD WINAPI thread_for_client(LPVOID pParam) {
    SOCKET t = (SOCKET)pParam;
    char chRxBuf[MAX_BUF] = { 0 };

    while (1) {
        int iLength = recv(t, chRxBuf, MAX_BUF, 0);
        if (iLength <= 0) {
            break; //예외처리
        }
        chRxBuf[iLength] = NULL;
        printf("Message received from the client: %s\n", chRxBuf);

        send(t, chRxBuf, iLength, 0);
    }

    closesocket(t);
    return 0;
}

int main(void) {
    WSADATA wsa;
    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) {
        printf("Error in starting up Winsock\n");
        return -1;
    }

    SOCKET s = socket(AF_INET, SOCK_STREAM, 0);
    if (s == INVALID_SOCKET) {
        printf("Error in socket(), Error code : %d\n", WSAGetLastError());
        WSACleanup();
        return -1;
    }

    SOCKADDR_IN myAddress;
    ZeroMemory(&myAddress, sizeof(myAddress));
    myAddress.sin_family = AF_INET;
    myAddress.sin_port = htons(50000);
    myAddress.sin_addr.s_addr = INADDR_ANY;

    if (bind(s, (SOCKADDR*)&myAddress, sizeof(myAddress)) == SOCKET_ERROR) {
        printf("Error in bind(), Error code : %d\n", WSAGetLastError());
        closesocket(s);
        WSACleanup();
        return -1;
    }

    if (listen(s, 5) == SOCKET_ERROR) {
        printf("Error in listen(), Error code : %d\n", WSAGetLastError());
        closesocket(s);
        WSACleanup();
        return -1;
    }

    printf("Server is waiting port 50000...\n");

    while (1) {
        SOCKADDR_IN clientAddress;
        int iAddressLength = sizeof(clientAddress);
        SOCKET t = accept(s, (SOCKADDR*)&clientAddress, &iAddressLength);
        if (t == INVALID_SOCKET) {
            printf("Error in accept(), Error code : %d\n", WSAGetLastError());
            continue;
        }

        const char chTxBuf[] = "Welcome to TCP Server";
        send(t, chTxBuf, strlen(chTxBuf), 0);

        LPVOID pParam = (LPVOID)t;
        CreateThread(NULL, 0, thread_for_client, pParam, 0, NULL);
    }

    closesocket(s);
    WSACleanup();
    return 0;
}