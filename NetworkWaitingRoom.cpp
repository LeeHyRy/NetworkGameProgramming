#include "stdafx.h"
#include "Network.h"

DWORD WINAPI roomServerThread(LPVOID lpParam)
{
	/// <summary>
	/// ����->Ŭ���̾�Ʈ
	///	Ŭ���̾�Ʈ ���Ϲ��� ������ ����(�г���, ����, ����, ������� ��ȣ ���)
	///	����ź� ��ȣ, ���ӽ��� ��ȣ �۽�
	/// </summary>
	/// <param name="lpParam"></param>
	/// <returns></returns>

}
DWORD WINAPI roomClientThread(LPVOID lpParam)
{
	/// <summary>
	/// Ŭ���̾�Ʈ -> ����
	/// ����, ����, ������� �۽� 
	/// ���ӽ��� ��ȣ ����
	/// </summary>
	/// <returns></returns>
	int retval; //������ ���� ��
	SOCKET server_sock = (SOCKET)lpParam; //���� ���� ��
	while (1)
	{
		retval = send(server_sock, (char*)&len, sizeof(int), 0);
	}
}
DWORD WINAPI roomDataProcessingThread(LPVOID lpParam)
{
	/// <summary>
	/// ���� ��Ʈ��ũ �����͸� ó���ϴ� ������
	/// Ŭ���̾�Ʈ ���� ó��(�г���, ��������)
	/// ���� ���� ȭ�� ���
	/// ���� ���� ����
	/// </summary>
	/// <param name="lpParam"></param>
	/// <returns></returns>

}
DWORD WINAPI WaitFiveSecAndStart(LPVOID lpParam)
{
	/// <summary>
	/// ���� ���� �� 5�� ��ٸ��� �����ϴ� ������
	/// </summary>
	/// <param name="lpParam"></param>
	/// <returns></returns>
	WAITING_ROOM* ppNetInfo = (WAITING_ROOM*)lpParam;
	Sleep(5000);
	if (ppNetInfo->checkAllReady() == true) {
		ppNetInfo->sendStart();
	}
}

//*************************************THREAD*************************************//

WAITING_ROOM::WAITING_ROOM()
{
	/// <summary>
	/// ���� Ŭ������ ����� �Լ�
	/// </summary>
	/// <param name="lpParam"></param>
	/// <returns></returns>
	for (int i{}; i < playerCount; ++i)
	{
		strcpy(player[i].nickname, "\0");
		player[i].isReady = false;
		player[i].sock = NULL; // CreateThread() ������ ��쵵 NULL
		player[i].num = 0; // 0 - �÷��̾� ���� �������

		sock[i] = (SOCKET)-1; // accept() ������ ��쵵 -1
	}

	listen = (SOCKET)-1; // listen() ������ ��쵵 -1
}

WAITING_ROOM::~WAITING_ROOM()
{
	/// <summary>
	/// ���� ����� ���� �� �ҷ��� ���������� ������ ��� �����ϰ� �ڵ��� �ݾ��ִ� ������ ����
	/// </summary>
	for (int i{}; i < playerCount; ++i)
	{
		closesocket(player[i].sock);
		//�߰�����
	}

}

bool WAITING_ROOM::checkReduplication(char* name)
{
	/// <summary>
	/// �г��� �ߺ� üũ
	/// </summary>
	/// <param name="name"></param>
	/// <returns>���� �г��� �� �� true �ߺ��� false</returns>
	for (int i{}; i < playerCount; ++i) {
		if (strcmp(player[i].nickname, name) == 0)
			return false;
	}
	return true;
}

bool WAITING_ROOM::checkAllReady()
{
	/// <summary>
	/// Ŭ���̾�Ʈ���� isReady ���� 
	/// </summary>
	/// <returns>üũ ��� Ŭ���̾�Ʈ�� Ready�� true �ƴϸ� false</returns>
	for (int i = 0; i < playerCount; ++i)
	{
		if (player[i].isReady == false)
			return false;
	}
	return true;

}

bool WAITING_ROOM::checkJoin(HANDLE handle)
{
	/// <summary>
	/// �������� ���ӽõ����� �˻�
	/// </summary>
	/// <param name="">�����Ϸ��� Ŭ���̾�Ʈ�� �ڵ鰪</param>
	/// <returns>�г��� �ߺ� �� false ��ȯ �� �� ���� ����ó�� �� true ��ȯ</returns>
	for (int i = 0; i < playerCount; ++i)
	{
		if (strcmp(player[i].nickname, (char*)handle) == 0)
		{
			return false;
		}
	}
	return true;
}

void WAITING_ROOM::pressStart()
{
	/// <summary>
	/// ������ ���� ���� �õ�
	/// </summary>
	if (this->checkAllReady() == true) {
		HANDLE hthr = CreateThread(NULL, 0, WaitFiveSecAndStart, NULL, 0, NULL);
		CloseHandle(hthr);
	}
}

void WAITING_ROOM::pressReady(int playerNumber)
{
	/// <summary>
	/// Ŭ���̾�Ʈ�� ready 
	/// ready ��ư ���� ������ isReady�� true, false�� ��ȯ
	/// </summary>
	/// <param name="playerNumber">�÷��̾� �ĺ���ȣ</param>
	player[playerNumber].isReady = player[playerNumber].isReady ? false : true; //true�� false, false�� true ��ȯ.
}

void WAITING_ROOM::receiveData()
{

}

void WAITING_ROOM::refuseEnter()
{
	/// <summary>
	/// ����ź� ��ȣ �۽�(������)
	/// </summary>
}
void WAITING_ROOM::sendStart()
{
	/// <summary>
	/// �÷��̾� ����, ������Ʈ ������ �۽�(������)
	/// </summary>
}

void WAITING_ROOM::stringAnalysis(char*)
{
	/// <summary>
	/// ���� ���ڿ� ������ �м��Ͽ� ������ �´� �Լ� ����
	/// </summary>
	/// <param name="">�ؼ��� ���ڿ�</param>
}
