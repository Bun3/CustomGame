#include "stdafx.h"
#include "cPartButton.h"

cPartButton::cPartButton()
{
}

cPartButton::cPartButton(int x, int y, const string& key, State _state) //그냥 버튼이랑 달리 파츠 전용으로 이미지 더 많음
{
	m_pos.x = x;
	m_pos.y = y;

	m_Normal = IMAGE->FindImage(key + "_Normal");
	m_Click = IMAGE->FindImage(key + "_Click");
	m_Equip = IMAGE->FindImage(key + "_Equip");
	m_OnCursor = IMAGE->FindImage(key + "_OnCursor");
	if (_state == Lock)
		m_Lock = IMAGE->FindImage(key + "_Lock");

	SetRect(&m_rt,
		m_pos.x - m_Normal->m_info->bmWidth / 2,
		m_pos.y - m_Normal->m_info->bmHeight / 2,
		m_pos.x + m_Normal->m_info->bmWidth / 2,
		m_pos.y + m_Normal->m_info->bmHeight / 2
	);

	b_Click = false;
	b_Equip = false;
	s_State = _state;
}


cPartButton::~cPartButton()
{
}

bool cPartButton::Update(int &_keyVal) //기존 버튼에서 Lock state 추가
{
	POINT pt;
	GetCursorPos(&pt);
	ScreenToClient(g_hWnd, &pt);

	if (b_Click && s_State == UnLock)
		if (INPUT->MouseLUp())
		{
			return true;
		}

	if (PtInRect(&m_rt, pt))
	{
		if (INPUT->MouseLDown() && s_State == Lock && _keyVal >= 5)
		{
			s_State = UnLock;
			_keyVal -= 5;
			return false;
		}
		if (s_State == UnLock)
		{
			b_OnCursor = true;
			if (INPUT->MouseLDown())
			{
				b_OnCursor = false;
				b_Click = true;
			}
		}
	}
	else
	{
		b_OnCursor = false;
		b_Click = false;
	}

	return false;
}

void cPartButton::Render()
{
	if (s_State == Lock)						IMAGE->Render(m_Lock, m_pos, true, RGB(255, 0, 255));
	else if (s_State == UnLock && b_Equip)		IMAGE->Render(m_Equip, m_pos, true, RGB(255, 0, 255));
	else if (s_State == UnLock && b_Click)		IMAGE->Render(m_Click, m_pos, true, RGB(255, 0, 255));
	else if (s_State == UnLock && b_OnCursor)	IMAGE->Render(m_OnCursor, m_pos, true, RGB(255, 0, 255));
	else										IMAGE->Render(m_Normal, m_pos, true, RGB(255, 0, 255));
}

void cPartButton::ChangeImage(const string & key) //각 파츠 별 5개 버튼의 이미지에 맞게 바꿔 주는 것
{
	m_Normal =		IMAGE->FindImage(key + "_Normal");
	m_Click =		IMAGE->FindImage(key + "_Click");
	m_Equip =		IMAGE->FindImage(key + "_Equip");
	m_OnCursor =	IMAGE->FindImage(key + "_OnCursor");
	if (s_State == Lock)
		m_Lock =	IMAGE->FindImage(key + "_Lock");
}
