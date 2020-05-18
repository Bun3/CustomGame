#include "stdafx.h"
#include "cOX.h"

cOX::cOX(Point pos, cTexture * image, unsigned long end, unsigned long delay)
	: m_Image(image) , m_Pos(pos)
{
	m_Frame = new cFrame();
	m_Frame->SetFrame(0 ,end, delay );
}

cOX::~cOX()
{
	SAFE_DELETE(m_Frame);
}

void cOX::Update()
{
	if (m_Frame->NowFrame != m_Frame->EndFrame)
		m_Frame->Frame();
}

void cOX::Render()
{
	IMAGE->Render(m_Image->FindImage(m_Frame->NowFrame), m_Pos, true, RGB(255, 0, 255));
}