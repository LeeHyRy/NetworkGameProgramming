#pragma once
#include "stdafx.h"
#include "PlayerInfo.h"



class NETWOKR_SERVER
{
public:
private:
	int playerCount{ 0 }; //���� ���� Ŭ���̾�Ʈ �÷��̾� ��
	PlayerInfo player[3];
	SOCKET listen;
};