#pragma once
#include "stdafx.h"
#include "TextureManager.h"

#include "Animation.h"
#include "AnimationClip.h"
#include "Global.h"
#include "Effect.h"
class UI 
{
public:
	UI(); //�׳� UI ������
	UI(const POINT& pt); //��ġ�� �μ��� �� ��� �� ��ġ�� �����Ǵ� ������
	~UI(); //�Ҹ���
private:
	POINT ui_PT{ 0 }; //ui��ġ
	SIZE ui_Size{ 100,100 }; //uiũ��
	SIZE ui_ClickSize{ 100,100 }; //ui ��ġ �ν� ũ��
	string ui_tag{ }; //ui �±�
public:
	POINT GetUiPT() const;
	SIZE GetUiSize() const;
	RECT GetUiRC() const;
	SIZE GetUiClickSize() const;
	RECT GetUiClickRC() const;

	void Update(float deltaTime); //������Ʈ �Լ�, �������� ������Ʈ
	void Render(HDC destDC); //�����Լ�

	bool Save(FILE* fp);
	bool Load(FILE* fp);
};