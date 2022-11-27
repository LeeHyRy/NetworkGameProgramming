#include "stdafx.h"
#include "WaitingClient.h"

DWORD WINAPI roomClientReceiveThread(LPVOID lpParam)
{
	/// <summary>
	/// Ŭ���̾�Ʈ�� �������� ���� �޽��� ����
	
	/// ���ӽ��� ��ȣ, �ٸ� ������ ����,���� ü����� �� ����
	/// �������� + ��������
	/// </summary>
	/// <returns></returns>
	WATING_CLIENT WC;
	int retval; //�ޱ� ���� ��
	char rcrBuf[2048]; //��������
	int rcrLen; // ���� ���� ������
	while (1)
	{
		//�������� �ޱ�
		retval = recv(WC.serverSock, (char*)&rcrLen, sizeof(int), 0);
		if (retval == SOCKET_ERROR) {
			// ���н� ���� ����
			return 0;
		}
		else if (retval == 0)
			break;

		//���� ������ �ޱ�
		retval = recv(WC.serverSock, rcrBuf, rcrLen, MSG_WAITALL);
		if (retval == SOCKET_ERROR) {
			// ���н� ��������
			return 0;
		}
		else if (retval == 0)
			break;
		
		WC.stringAnalysis(rcrBuf);
	}
}
DWORD WINAPI roomClientSendThread(LPVOID lpParam)
{
	/// <summary>
	/// Ŭ���̾�Ʈ���� �������� �޽��� �۽��ϴ� ������
	/// ����, ����, ������� �۽� 
	/// </summary>
	/// <param name="lpParam"></param>
	/// <returns></returns>
	int retval; //������ ���� ��
}
void WATING_CLIENT::sendReady()
{
#define bufSize 16
	char readyBuf[bufSize] = "RD";
	sprintf(readyBuf, "RD%d", myNumber); //RD+�� ��ȣ ->RD0, RD1, ...
	int retval = send(serverSock, readyBuf, sizeof(readyBuf), 0);
}
void WATING_CLIENT::receiveReady(int playerNumber)
{
	/// <summary>
	/// Ŭ���̾�Ʈ�� ready 
	/// ready ��ư ���� ������ isReady�� true, false�� ��ȯ
	/// </summary>
	/// <param name="playerNumber">�÷��̾� �ĺ���ȣ</param>
	player[playerNumber].SetIsReady(player[playerNumber].GetIsReady() ? false : true); //true�� false, false�� true ��ȯ.
}

void WATING_CLIENT::receiveStart()
{
}

void WATING_CLIENT::stringAnalysis(char* command)
{
	/// <summary>
	/// ���ڿ� �ؼ��ؼ� �´� �Լ� ����
	/// </summary>
	/// <param name="command">������ ���ڿ�</param>
	if (strcmp(command, "ST") == 0)
	{
		//ST: ���ӽ��� ��ȣ
		//���ӽ���
	}
	else if (strcmp(command, "ST") == 0)
	{
		//RJ: ���� ���� ���� ��ȣ
		//���� ������
	}
	else if (strncmp(command, "RD", 2) == 0)
	{
		//RD: ���� ��ȣ
		//RD0: 0�� �÷��̾� ����
		//RD1: 1�� �÷��̾� ���� ...
		receiveReady(command[2]);
	}
}
