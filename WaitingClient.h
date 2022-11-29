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
	//클라이언트 대기실
	void sendReady(); //[클라이언트]서버에게 레디송신
	void receiveReady(int playerNumber); //다른 클라이언트가 ready
	void receiveStart(); //[클라이언트] 게임시작 신호 수신
	void stringAnalysis(char* command); //[클라이언트] 받은 문자열 구문을 분석하여 목적에 맞는 함수 실행
	SOCKET serverSock; //서버 연결 소켓
	void sendData(); //클라이언트 소켓버퍼 데이터 송신
	
private:
	int playerCount{ 0 }; //대기방 안의 클라이언트 플레이어 수
	int myNumber{ 0 }; //내 클라이언트 번호
	PlayerInfo player[3]; //클라이언트 플레이어 
	
};