#include "stdafx.h"
#include "cTitle.h"

#include "cButton.h"

cTitle::cTitle()
{
}


cTitle::~cTitle()
{
}

void cTitle::Init()
{
	m_BGPos.x = 0;
	m_BGPos.y = 0;

	m_TeamLogoPos.x = 520;
	m_TeamLogoPos.y = 30;

	m_LogoPos.x = 320;
	m_LogoPos.y = 300;

	m_IllustPos.x = 320;
	m_IllustPos.y = 500;

	m_StartGuideButton = new cButton(320, 600, "SGButton");
}

void cTitle::Update()
{
	if (m_StartGuideButton->Update()) { SCENE->ChangeScene("Custom_BG"); }
}

void cTitle::Render()
{
	IMAGE->Render(IMAGE->FindImage("Title_BG"), m_BGPos, false);
	IMAGE->Render(IMAGE->FindImage("TitleTeamLogo"), m_TeamLogoPos, true, RGB(255, 255, 255));
	IMAGE->Render(IMAGE->FindImage("TitleIllust"), m_IllustPos, true, RGB(0, 0, 0));
	IMAGE->Render(IMAGE->FindImage("TitleLogo"), m_LogoPos, true, RGB(239, 228, 176));
	m_StartGuideButton->Render();
}

void cTitle::Release()
{
	SAFE_DELETE(m_StartGuideButton);
}
