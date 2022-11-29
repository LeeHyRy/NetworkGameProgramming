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
	//서버 대기실
	bool checkReduplication(char* name); //닉네임 중복체크
	bool checkAllReady(); //클라이언트들의 레디 체크
	bool checkJoin(HANDLE handle); //정상적인 접속인지 검사
	void pressStart(); // 방장이 게임 시작 시도
	void receiveReady(int playerNumber); //클라이언트가 ready
	void sendData();
	void receiveData(); //클라이언트 소켓버퍼 데이터 수신
	void refuseEnter(SOCKET consock); // 입장거부 신호 송신(보내기)
	void sendStart(); //게임시작 신호 송신
	void stringAnalysis(char* command); //받은 문자열 구문을 분석하여 목적에 맞는 함수 실행
private:
	int playerCount{ 0 }; //대기방 안의 클라이언트 플레이어 수
	PlayerInfo player[3];
	SOCKET listen;
};