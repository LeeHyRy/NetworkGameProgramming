#pragma once
#include "stdafx.h"
class PlayerInfo
{
public:
	PlayerInfo();
	~PlayerInfo();
	char* GetNick();
	void SetNick(char* name);
	bool GetIsReady();
	void SetIsReady(bool ready);
	SOCKET GetSock();
	void SetSock(SOCKET sock);
	int GetNum();
	void SetNum(int num); 
private:
	char* playerNickname; //�÷��̾� �г���
	bool playerIsReady; //�÷��̾� ���� �غ� ����
	SOCKET playerSock; //�÷��̾� ����
	int playerNum; //�÷��̾� �ĺ���ȣ
};