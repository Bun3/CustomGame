#include "stdafx.h"
#include "cButton.h"


cButton::cButton()
{
}

cButton::cButton(int x, int y, const string& key) //영찬 구현 패스 키를 받아 각 이미지를 찾아 변수 저장
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

bool cButton::Update() //마우스 관련이벤트 업데이트
{
	POINT pt;
	GetCursorPos(&pt);
	ScreenToClient(g_hWnd, &pt);

	if (b_Click)
		if (INPUT->MouseLUp())
			return true;

	if (PtInRect(&m_rt, pt)) 
	{
		b_OnCursor = true;
		if (INPUT->MouseLDown())	b_Click = true;
	}
	else
	{
		b_OnCursor = false;
		b_Click = false;
	}
	return false;
}

void cButton::Render(COLORREF rgb) //버튼 상태에 따라 이미지 렌더
{
	if (b_Click)IMAGE->Render(m_Click, m_pos, true, rgb);
	else if (b_OnCursor) IMAGE->Render(m_OnCursor, m_pos, true, rgb);
	else			IMAGE->Render(m_Normal, m_pos, true, rgb);
}	

