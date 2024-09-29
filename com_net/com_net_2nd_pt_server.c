#pragma comment(lib, "ws2_32.lib");
#include <WinSock2.h>
#include <stdio.h>
#define MAX_BUF 100000

//22110670 김정운//

int main(void) {
	WSADATA wsa;
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) {
		printf("Error in starting up Winsock\n");
		return -1;
	}

	SOCKET s = socket(AF_INET, SOCK_DGRAM, 0);
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

	SOCKADDR_IN clientAddress;
	int iAddressLength = sizeof(clientAddress);
	char sendTo_sv[MAX_BUF] = { 0 };
	char sendTo_cl[MAX_BUF] = "Hi, Client. This is a UDP server.";

	while (1) {
		printf("대기중...\n");
		int iLength = recvfrom(s, sendTo_sv, MAX_BUF, 0, (SOCKADDR*)&clientAddress, &iAddressLength);
		if (iLength == SOCKET_ERROR) {
			printf("Error in recvfrom(), Error code : %d\n", WSAGetLastError());
			closesocket(s);
			WSACleanup();
			return -1;
		}
		printf("Message receive from the client: %s\n", sendTo_sv);

		int jLength = sendto(s, sendTo_cl, strlen(sendTo_cl), 0, (SOCKADDR*)&clientAddress, sizeof(clientAddress));


		if (jLength == SOCKET_ERROR) {
			printf("Error in sendto(), Error code: %d\n", WSAGetLastError());
			closesocket(s);
			WSACleanup();
			return -1;
		}
		printf("Message send to the Client: %s\n", sendTo_cl);
	}

	closesocket(s);
	WSACleanup();
	return 0;
}