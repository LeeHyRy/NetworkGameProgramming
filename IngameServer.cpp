#include "stdafx.h"
#include "IngameServer.h"
#include "GameFrame.h"
DWORD WINAPI ingameServerReceiveThread(LPVOID lpParam)
{
	/// <summary>
	/// �ΰ��ӿ��� ������ Ŭ���̾�Ʈ�κ��� �޽��� �޴� ������
	/// </summary>
	/// <param name="lpParam"></param>
	/// <returns></returns>
	INGAME_SERVER IS;
	int sockPlayerNum = (int)lpParam; //�� �����忡�� �������� Ŭ���̾�Ʈ�� ��ȣ
	int retval; //�ޱ� ���� ��
	char rcrBuf[2048]; //��������
	int rcrLen; // ���� ���� ������
	while (1)
	{
		//�������� �ޱ�
		retval = recv(IS.getPlayer(sockPlayerNum).playerSock, (char*)&rcrLen, sizeof(int), 0);
		if (retval == SOCKET_ERROR) {
			// ���н� ���� ����
			return 0;
		}
		else if (retval == 0)
			break;

		//���� ������ �ޱ�
		retval = recv(IS.getPlayer(sockPlayerNum).playerSock, rcrBuf, rcrLen, MSG_WAITALL);
		if (retval == SOCKET_ERROR) {
			// ���н� ��������
			return 0;
		}
		else if (retval == 0)
			break;

		IS.stringAnalysis(rcrBuf);
	}
}
void INGAME_SERVER::receivePress()
{
}

void INGAME_SERVER::inputManagement()
{
}

void INGAME_SERVER::objectInteract()
{
}

void INGAME_SERVER::sendState()
{
	/// <summary>
	/// [����] �÷��̾� ����, ������Ʈ ������ �۽��ϴ� �Լ�
	/// </summary>
	
}

void INGAME_SERVER::Render()
{
}

void INGAME_SERVER::sendEnd()
{
	/// <summary>
	/// ���� ���� ��ȣ �۽�
	/// </summary>
	int retval;
	for (int i = 0; i < playerCount; ++i)
	{
		retval = send(player[i].playerSock, "END", sizeof("END"), 0);
		if (retval == SOCKET_ERROR) {
			printf("�������� ���������ȣ �۽� ����");
			break;
		}
	}
	
}

void INGAME_SERVER::stringAnalysis(char*)
{

}

PlayerInfo INGAME_SERVER::getPlayer(int num)
{
	/// <summary>
	/// �ش� ��ȣ�� �÷��̾� ������ ��� �Լ�
	/// </summary>
	/// <param name="num">�� �÷��̾��� ��ȣ</param>
	/// <returns></returns>
	return player[num];
}
