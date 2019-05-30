#include "stdafx.h"
#include "cButton.h"


cButton::cButton(int x, int y, const string& key)
{
	m_pos.x = x;
	m_pos.y = y;

	m_Normal = IMAGE->FindImage(key + "_Normal");
	m_OnCursor = IMAGE->FindImage(key + "_OnCursor");
	m_Click = IMAGE->FindImage(key + "_Click");

	SetRect(&m_rt,
		m_pos.x - m_Normal->m_info->bmWidth / 2,
		m_pos.y - m_Normal->m_info->bmHeight / 2,
		m_pos.x + m_Normal->m_info->bmWidth / 2,
		m_pos.y + m_Normal->m_info->bmHeight / 2
		);
	b_Click = false;
	b_OnCursor = false;
}


cButton::~cButton()
{

}

bool cButton::Update()
{
	POINT pt;
	GetCursorPos(&pt);
	ScreenToClient(g_hWnd, &pt);

	if (b_Click) 
		if (INPUT->MouseLUp()) return true;

	if (PtInRect(&m_rt, pt)) 
	{
		b_OnCursor = true;
		if (INPUT->MouseLPress())	b_Click = true;
		else						b_Click = false;
	}
	else b_OnCursor = false;

	return false;
}

void cButton::Render()
{
	if(b_Click)IMAGE->Render(m_Click, m_pos, true, RGB(255, 255, 255));
	else if (b_OnCursor) IMAGE->Render(m_OnCursor, m_pos, true, RGB(255, 255, 255));
	else			IMAGE->Render(m_Normal, m_pos, true, RGB(255, 255, 255));
}	

