#pragma comment(lib, "ws2_32.lib")
#include <WS2tcpip.h>
#include <stdio.h>
#define MAX_BUF 100000
#include <windows.h>

//22110670 ±èÁ¤¿î//

DWORD WINAPI thread_for_display(LPVOID pParam) {
    SOCKET s = (SOCKET)pParam;
    char chRxBuf[MAX_BUF] = { 0 };
    while (1) {
        int iLength = recv(s, chRxBuf, MAX_BUF - 1, 0);
        if (iLength == SOCKET_ERROR) {
            printf("Error in recv(), Error code : %d\n", WSAGetLastError());
            closesocket(s);
            return -1;
        }
        chRxBuf[iLength] = NULL;
        printf("Message received from the server: %s \n", chRxBuf);
    }
    closesocket(s);
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

    SOCKADDR_IN serverAddress;
    ZeroMemory(&serverAddress, sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(50000);
    inet_pton(AF_INET, "192.168.0.8", &(serverAddress.sin_addr.s_addr));

    if (connect(s, (SOCKADDR*)&serverAddress, sizeof(serverAddress)) == SOCKET_ERROR) {
        printf("Error in connect(), Error code : %d\n", WSAGetLastError());
        closesocket(s);
        WSACleanup();
        return -1;
    }

    CreateThread(NULL, 0, thread_for_display, (LPVOID)s, 0, NULL);

    while (1) {
        char chTxBuf[MAX_BUF] = { 0 };
        if (gets_s(chTxBuf, MAX_BUF - 1) != NULL) {
            if (send(s, chTxBuf, strlen(chTxBuf), 0) == SOCKET_ERROR) {
                printf("Error in send(), Error code: %d\n", WSAGetLastError());
                closesocket(s);
                WSACleanup();
                return -1;
            }
        }
        else {
            break;
        }
    }

    closesocket(s);
    WSACleanup();
    return 0;
}