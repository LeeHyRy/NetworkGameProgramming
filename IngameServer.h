#pragma once
#include "stdafx.h"
#include "PlayerInfo.h"

enum class NetworkWaitInfo {
	NICKNAME,
	READY,
	REJECT,
	START
};
class INGAME_SERVER
{
public:
	//�ΰ���
	void receivePress(); //[����] Ŭ���̾�Ʈ �Է� �� ����
	void inputManagement(); //[����] Ŭ���̾�Ʈ �Է°� ó��
	void objectInteract(); //[����] ������Ʈ �浹ó��
	void sendState(); //[����] �÷��̾� ����, ������Ʈ ������ �۽��ϴ� �Լ�
	void Render(); //[����, Ŭ���̾�Ʈ] ���� ȭ�� ���
	void sendEnd(); //[����] ���� ���� ��ȣ �۽�
	void stringAnalysis(char*); //���� ���ڿ� ������ �м��Ͽ� ������ �´� �Լ� ����
private:
	int playerCount{ 0 }; //���� ���� Ŭ���̾�Ʈ �÷��̾� ��
	PlayerInfo player[3];
	SOCKET listen;
};