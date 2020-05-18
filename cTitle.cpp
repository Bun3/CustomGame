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

	rect = { 0,0,640,960 };
}

void cTitle::Update()
{
	ptMouse = INPUT->GetMousePos();
	ScreenToClient(g_hWnd, &ptMouse);
	if (PtInRect(&rect, ptMouse))
	{
		if (INPUT->MouseLDown())
		{
			SCENE->ChangeScene("Custom_BG");
		}
	}
}

void cTitle::Render()
{
	IMAGE->Render(IMAGE->FindImage("Title_BG"), m_BGPos, false);
}

void cTitle::Release()
{
}
