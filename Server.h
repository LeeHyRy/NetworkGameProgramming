#define _CRT_SECURE_NO_WARNINGS // ���� C �Լ� ��� �� ��� ����
#define _WINSOCK_DEPRECATED_NO_WARNINGS // ���� ���� API ��� �� ��� ����

#include <winsock2.h> // ����2 ���� ���
#include <ws2tcpip.h> // ����2 Ȯ�� ���
#include <stdio.h> // printf(), ...

#pragma comment(lib, "ws2_32") // ws2_32.lib ��ũ

#define SERVERPORT 9000
#define NICKBUFSIZE 20

DWORD WINAPI roomServerThread(LPVOID arg);

struct SERVERINFO {
	SOCKET listenSock;
};

class WAITING_ROOM
{
private:

protected:
	WSADATA wsa;
	SOCKET listen_sock;
	struct sockaddr_in serveraddr;


public:
	WAITING_ROOM();
	~WAITING_ROOM();
	int MAKE_ROOM();


};