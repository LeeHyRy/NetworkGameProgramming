#include "Network.h"

WAITING_ROOM::WAITING_ROOM()
{
	for (int i{}; i < 3; ++i) {
		player[i].nickname[0] = "\0";
		player[i].isReady = false;
		player[i].sock = NULL; // CreateThread() ������ ��쵵 NULL
		player[i].num = 0; // 0 - �÷��̾� �̽ĺ�
	}

	listen = (HANDLE)-1; // listen() ������ ��쵵 -1
}

