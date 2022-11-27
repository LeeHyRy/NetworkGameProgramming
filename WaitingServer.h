#pragma once
#include "stdafx.h"
#include "PlayerInfo.h"

enum class NetworkWaitInfo {
	NICKNAME,
	READY,
	REJECT,
	START
};
class WATING_SERVER
{
public:
	//���� ����
	bool checkReduplication(char* name); //�г��� �ߺ�üũ
	bool checkAllReady(); //Ŭ���̾�Ʈ���� ���� üũ
	bool checkJoin(HANDLE handle); //�������� �������� �˻�
	void pressStart(); // ������ ���� ���� �õ�
	void receiveReady(int playerNumber); //Ŭ���̾�Ʈ�� ready
	void sendData(); //Ŭ���̾�Ʈ ���Ϲ��� ������ ����
	void receiveData(); //Ŭ���̾�Ʈ ���Ϲ��� ������ �۽�
	void refuseEnter(SOCKET consock); // ����ź� ��ȣ �۽�(������)
	void sendStart(); //���ӽ��� ��ȣ �۽�
	void stringAnalysis(char* command); //���� ���ڿ� ������ �м��Ͽ� ������ �´� �Լ� ����
private:
	int playerCount{ 0 }; //���� ���� Ŭ���̾�Ʈ �÷��̾� ��
	PlayerInfo player[3];
	SOCKET listen;
};