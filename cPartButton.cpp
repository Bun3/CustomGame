#include "stdafx.h"
#include "cPartButton.h"

cPartButton::cPartButton()
{
}

cPartButton::cPartButton(int x, int y, const string& key)
{
	m_pos.x = x;
	m_pos.y = y;

	m_Activate = IMAGE->FindImage(key + "_Active");
	m_Lock = IMAGE->FindImage(key + "_Lock");
	m_Click = IMAGE->FindImage(key + "_Click");

	SetRect(&m_rt,
		m_pos.x - m_Activate->m_info->bmWidth / 2,
		m_pos.y - m_Activate->m_info->bmHeight / 2,
		m_pos.x + m_Activate->m_info->bmWidth / 2,
		m_pos.y + m_Activate->m_info->bmHeight / 2
	);

	b_Click = false;
	b_Lock = false;
}


cPartButton::~cPartButton()
{
}

bool cPartButton::Update()
{
	POINT pt;
	GetCursorPos(&pt);

	ScreenToClient(g_hWnd, &pt);

	if (b_Click && !b_Lock)
		if (INPUT->MouseLUp()) return true;

	if (PtInRect(&m_rt, pt))
	{
		if (INPUT->MouseLPress()) b_Click = true;
		else b_Click = false;
	}

	return false;
}

void cPartButton::Render()
{
	if (b_Lock) IMAGE->Render(m_Lock, m_pos, true, RGB(1, 1, 1));
	else if (!b_Lock && b_Click) IMAGE->Render(m_Click, m_pos, true, RGB(1, 1, 1));
	else IMAGE->Render(m_Activate, m_pos, true, RGB(1, 1, 1));
}

void cPartButton::ChangeImage(const string & key)
{
	m_Activate = IMAGE->FindImage(key + "_Active");
	m_Lock = IMAGE->FindImage(key + "_Lock");
	m_Click = IMAGE->FindImage(key + "_Click");
}
