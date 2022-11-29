#pragma once
#include "stdafx.h"
#include "PlayerInfo.h"



class NETWOKR_SERVER
{
public:
private:
	int playerCount{ 0 }; //대기방 안의 클라이언트 플레이어 수
	PlayerInfo player[3];
	SOCKET listen;
};