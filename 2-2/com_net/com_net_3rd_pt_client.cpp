#pragma comment(lib, "ws2_32.lib");
#include <WS2tcpip.h>
#include <stdio.h>
#define MAX_BUF 100000


//22110670 김정운//
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
	char chRxBuf[MAX_BUF] = { 0 };
	recv(s, chRxBuf, MAX_BUF, 0);

	const char chTxBuf[MAX_BUF] = "Hello, TCP server!";
	send(s, chTxBuf, strlen(chTxBuf), 0);

	int iLength = send(s, chTxBuf, strlen(chTxBuf), 0);
	if (iLength == SOCKET_ERROR) {
		printf("Error in send(), Error code : %d\n", WSAGetLastError());
		WSACleanup();
		return -1;
	}
	printf("Message send to the server : %s \n", chTxBuf);

	int jLength = recv(s, chRxBuf, MAX_BUF, 0);
	if (jLength == SOCKET_ERROR) {
		printf("Error in recv(), Error code: %d\n", WSAGetLastError());
		closesocket(s);
		WSACleanup();
		return -1;
	}
	printf("Message receive from the server : %s \n", chRxBuf);

	closesocket(s);
	WSACleanup();
	return 0;
}