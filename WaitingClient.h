#pragma once
#include "stdafx.h"
#include "PlayerInfo.h"

enum class NetworkWaitInfo {
	NICKNAME,
	READY,
	REJECT,
	START
};
class WATING_CLIENT
{
public:
	//Ŭ���̾�Ʈ ����
	void sendReady(); //[Ŭ���̾�Ʈ]�������� ����۽�
	void receiveStart(); //[Ŭ���̾�Ʈ] ���ӽ��� ��ȣ ����
	void stringAnalysis(char*); //[Ŭ���̾�Ʈ] ���� ���ڿ� ������ �м��Ͽ� ������ �´� �Լ� ����
	
private:
	int playerCount{ 0 }; //���� ���� Ŭ���̾�Ʈ �÷��̾� ��
	int myNumber{ 0 }; //�� Ŭ���̾�Ʈ ��ȣ
	PlayerInfo player[3];
};