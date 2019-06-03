#include "stdafx.h"
#include "cCustomGame.h"

#include "cButton.h"
#include "cPartButton.h"

cCustomGame::cCustomGame()
{
}

cCustomGame::~cCustomGame()
{
}

void cCustomGame::Init()
{
	m_BGPos.x = 0;
	m_BGPos.y = 0;

	m_KeyPos.x = 0; 
	m_KeyPos.y = 0;

	m_CategoryBack_Pos.x = 320;
	m_CategoryBack_Pos.y = 650;
	m_PartBack_Pos.x = 320;
	m_PartBack_Pos.y = 850;

	for (int i = 0; i < 5; i++)
	{
		m_CategoryPos[i].x = i * 108 + 90;
		m_CategoryPos[i].y = 650;
	}

	m_CreditPopUpPos.x = 320;
	m_CreditPopUpPos.y = 450;

	for (int i = 0; i < 4; i++)
	{
		m_PartPos[i].x = i * 160 + 70;
		m_PartPos[i].y = 810;
	}

	b_Credit = false;
	m_CategoryState = Skin;

	m_SaveButton = new cButton(40, 400, "SaveButton");
	m_CreditButton = new cButton(40, 480, "CreditButton");
	m_ResetButton = new cButton(40, 560, "ResetButton");
	m_GMSButton = new cButton(560, 560, "GameStartButton");
	m_CreditBackButton = new cButton(450, 750, "CreditBack");

	m_CTGY_Skin  = new cButton(m_CategoryPos[Skin].x, m_CategoryPos[Skin].y,"Skin");
	m_CTGY_Eye	 = new cButton(m_CategoryPos[Eye].x, m_CategoryPos[Eye].y,"Eye");
	m_CTGY_Mouth = new cButton(m_CategoryPos[Mouth].x, m_CategoryPos[Mouth].y,"Mouth");
	m_CTGY_Cloth = new cButton(m_CategoryPos[Cloth].x, m_CategoryPos[Cloth].y,"Cloth");
	m_CTGY_Hair	 = new cButton(m_CategoryPos[Hair].x, m_CategoryPos[Hair].y,"Hair");

	for (size_t i = 0; i < 4; i++)
		m_PartButton[i] = new cPartButton(m_PartPos[i].x, m_PartPos[i].y, string("PartSkin_") + to_string(i + 1));

	m_key = 0;
	m_tmpKey = 0;

	fopen_s(&m_fp, "DataFile.txt", "r");
	fscanf_s(m_fp, "%d", &m_key);
	fclose(m_fp);
	DEBUG_LOG(m_key);
}

void cCustomGame::Update()
{
	if (m_SaveButton->Update()) { SaveKey(m_key); };
	if (INPUT->MouseRUp()) m_key--;
	if (m_CreditButton->Update()) { b_Credit = true; }
	if (m_CreditBackButton->Update() && b_Credit) { b_Credit = false; }
	if (m_ResetButton->Update()) {}
	if (m_GMSButton->Update()) { SCENE->ChangeScene("Puzzle_BG"); }
	if (m_CTGY_Skin->Update()) { m_CategoryState = Skin; }
	if (m_CTGY_Eye->Update()) { m_CategoryState = Eye; }
	if (m_CTGY_Mouth->Update()) { m_CategoryState = Mouth; }
	if (m_CTGY_Cloth->Update()) { m_CategoryState = Cloth; }
	if (m_CTGY_Hair->Update()) { m_CategoryState = Hair; }
	switch (m_CategoryState)
	{
	case Skin: 
		for (int i = 0; i < 4; i++)
			m_PartButton[i]->ChangeImage(string("PartSkin_") + to_string(i + 1));	break;
	case Eye:
		for (int i = 0; i < 4; i++)
			m_PartButton[i]->ChangeImage(string("PartEye_") + to_string(i + 1));	break;
	case Mouth:
		for (int i = 0; i < 4; i++)
			m_PartButton[i]->ChangeImage(string("PartMouth_") + to_string(i + 1));	break;
	case Cloth:
		for (int i = 0; i < 4; i++)
			m_PartButton[i]->ChangeImage(string("PartCloth_") + to_string(i + 1));	break;
	case Hair:
		for (int i = 0; i < 4; i++)
			m_PartButton[i]->ChangeImage(string("PartHair_") + to_string(i + 1));	break;
	}
}

void cCustomGame::Render()
{
	wchar_t str[1024] = L"";
	wsprintf(str, L"%d", m_key);

	IMAGE->Render(IMAGE->FindImage("Custom_BG"), m_BGPos, false);
	IMAGE->Render(IMAGE->FindImage("KeyDisplay"), m_KeyPos, false, RGB(255, 255, 255));
	IMAGE->TextRender(IMAGE->FindImage("KeyDisplay"), str, 100, 15, RGB(0, 0, 0), 25);
	IMAGE->Render(IMAGE->FindImage("CategoryBack"), m_CategoryBack_Pos, true);
	IMAGE->Render(IMAGE->FindImage("PartBack"), m_PartBack_Pos, true);
	m_SaveButton->Render();
	m_CreditButton->Render();
	m_ResetButton->Render();
	m_GMSButton->Render();
	m_CTGY_Skin->Render();
	m_CTGY_Eye->Render();
	m_CTGY_Mouth->Render();
	m_CTGY_Cloth->Render();
	m_CTGY_Hair->Render();

	for (int i = 0; i < 4; i++)
	{
		m_PartButton[i]->Render();
	}

	if (b_Credit)
	{
		IMAGE->Render(IMAGE->FindImage("CreditPopUP"), m_CreditPopUpPos, true);
		m_CreditBackButton->Render();
	}
}

void cCustomGame::Release()
{
	for (int i = 3; i >= 0; --i)
	{
		SAFE_DELETE(m_PartButton[i]);
	}
	SAFE_DELETE(m_CTGY_Hair);
	SAFE_DELETE(m_CTGY_Cloth);
	SAFE_DELETE(m_CTGY_Mouth);
	SAFE_DELETE(m_CTGY_Eye);
	SAFE_DELETE(m_CTGY_Skin);
	SAFE_DELETE(m_CreditBackButton);
	SAFE_DELETE(m_GMSButton);
	SAFE_DELETE(m_ResetButton);
	SAFE_DELETE(m_CreditButton);  
	SAFE_DELETE(m_SaveButton);
}

void cCustomGame::SaveKey(int _key)
{
	m_tmpKey = _key;
	fopen_s(&m_fp, "DataFile.txt", "w");
	fprintf_s(m_fp, "%d", m_tmpKey);
	fclose(m_fp);
}
