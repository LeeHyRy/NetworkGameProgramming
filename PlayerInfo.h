#pragma once
#include "stdafx.h"
class PlayerInfo
{
public:
	PlayerInfo();
	~PlayerInfo();
	char* nickname; //�÷��̾� �г���
	bool isReady; //�÷��̾� ���� �غ� ����
	SOCKET sock; //�÷��̾� ����
	int num; //�÷��̾� �ĺ���ȣ
private:
};