#include <WinSock2.h>
#include <stdio.h>
#pragma comment(lib, "ws2_32.lib")

/* 22110670 김정운*/

int main(void) {
	WSADATA wsa;
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) {
		printf("Error in startup Winsock\n");
		return -1;
	}

	WSACleanup(); //소켓 라이브러리 사용

	SOCKET s = socket(AF_INET, SOCK_DGRAM, 0); //소켓 생성
	SOCKADDR_IN myAddress;
	ZeroMemory(&myAddress, sizeof(myAddress));
	myAddress.sin_family = AF_INET;
	myAddress.sin_port = 50000;
	inet_pton(AF_INET, "165.229.88.232", &(myAddress.sin_addr.s_addr));
	bind(s, (SOCKADDR*)&myAddress, sizeof(myAddress));//내 컴퓨터 ip주소 기입, 포트번호 50000기입
	closesocket(s);
	return 0; //소켓 종료
}