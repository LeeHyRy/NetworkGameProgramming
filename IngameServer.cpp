#include "stdafx.h"
#include "IngameServer.h"
#include "GameFrame.h"

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
		retval = send(player[i].GetSock(), "END", sizeof("END"), 0);
		if (retval == SOCKET_ERROR) {
			printf("�������� ���������ȣ �۽� ����");
			break;
		}
	}
	
}

void INGAME_SERVER::stringAnalysis(char*)
{

}
