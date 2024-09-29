#pragma comment(lib, "ws2_32.lib");
#include <WinSock2.h>
#include <stdio.h>
#define MAX_BUF 100000


//22110670 ±èÁ¤¿î//

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

	SOCKADDR_IN serverAddress;
	ZeroMemory(&serverAddress, sizeof(serverAddress));
	serverAddress.sin_family = AF_INET;
	serverAddress.sin_port = htons(50000);
	inet_pton(AF_INET, "172.29.8.70", &(serverAddress.sin_addr.s_addr));

	const char sendTo_sv[MAX_BUF] = "Hello, UDP server!";
	char sendTo_cl[MAX_BUF] = {0};
	int iLength = sendto(s, sendTo_sv, strlen(sendTo_sv), 0, (SOCKADDR*)&serverAddress, sizeof(serverAddress));

	if (iLength == SOCKET_ERROR) {
		printf("Error in sendto(), Error code : %d\n", WSAGetLastError());
		WSACleanup();
		return -1;
	}
	printf("Message send to the server : %s \n", sendTo_sv);

	int jlen = sizeof(serverAddress);
	int jLength = recvfrom(s, sendTo_cl, MAX_BUF, 0, (SOCKADDR*)&serverAddress, &jlen);

	if (jLength == SOCKET_ERROR) {
		printf("Error in recvfrom(), Error code: %d\n", WSAGetLastError());
		closesocket(s);
		WSACleanup();
		return -1;
	}

	printf("Message receive from the server : %s \n", sendTo_cl);
	
	closesocket(s);
	WSACleanup();
	return 0;
	}