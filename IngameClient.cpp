#include "stdafx.h"
#include "IngameClient.h"

void INGAME_CLIENT::sendPress()
{
}

void INGAME_CLIENT::receiveState()
{
}

void INGAME_CLIENT::Render()
{
}

void INGAME_CLIENT::receiveEnd()
{
	/// <summary>
	/// ���� ���� ��ɾ� ����
	/// </summary>
	//���� ���� �Լ�
}

void INGAME_CLIENT::stringAnalysis(char* command)
{
	//��ɾ� ���ڿ� �ؼ�
	if (strcmp(command, "END") == 0)
	{
		receiveEnd();
	}
}
