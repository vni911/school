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

	SOCKADDR_IN myAddress;
	ZeroMemory(&myAddress, sizeof(myAddress));
	myAddress.sin_family = AF_INET;
	myAddress.sin_port = htons(50000);
	myAddress.sin_addr.s_addr = INADDR_ANY;

	bind(s, (SOCKADDR*)&myAddress, sizeof(myAddress));


	listen(s, 5);
	if (listen(s, 5) == SOCKET_ERROR) {
		printf("listen(), Error code : %d\n", WSAGetLastError());
		closesocket(s);
		WSACleanup();
		return -1;
	}

	printf("Server is listening on port 50000...\n");


	while (1) {
		SOCKADDR_IN clientAddress;
		int iAddressLength = sizeof(clientAddress);

		SOCKET t = accept(s, (SOCKADDR*)&clientAddress, &iAddressLength);

		const char chTxBuf[MAX_BUF] = "Hi, TCP Client! This is a TCP server.";
		send(t, chTxBuf, strlen(chTxBuf), 0);

		char chRxBuf[MAX_BUF] = { 0 };
		int iLnegth = recv(t, chRxBuf, MAX_BUF, 0);

		closesocket(t);
		printf("Message receive from the client : %s \n", chRxBuf);
	}


	closesocket(s);
	WSACleanup();
	return 0;
}