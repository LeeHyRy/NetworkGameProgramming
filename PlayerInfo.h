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
	SOCKET playerSock; //�÷��̾� ����
	SOCKET GetSock();
	void SetSock(SOCKET sock);
	void CloseSock();
	int GetNum();
	void SetNum(int num); 
private:
	char* playerNickname; //�÷��̾� �г���
	bool playerIsReady; //�÷��̾� ���� �غ� ����
	int playerNum; //�÷��̾� �ĺ���ȣ
};