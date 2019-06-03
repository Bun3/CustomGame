#include "stdafx.h"
#include "cImageManager.h"

#include "cSingleTexture.h"
#include "cMultiTexture.h"

cImageManager::cImageManager()
{
}


cImageManager::~cImageManager()
{
	for (auto iter : m_image)
		SAFE_DELETE(iter.second);
	m_image.clear();
}

void cImageManager::Init()
{

}

cTexture * cImageManager::AddImage(const string & key, const string & path, int count)
{
	auto find = m_image.find(key);
	if (find == m_image.end()) {
		cTexture * ret;

		if (count == 0)
			ret = new cSingleTexture;
		else
			ret = new cMultiTexture;

		ret->AddImage(path, count);
		m_image.insert(make_pair(key, ret));

		return ret;
	}
	return nullptr;
}

cTexture * cImageManager::FindImage(const string & key, int count)
{
	auto find = m_image.find(key);
	if (find != m_image.end()) {
		return find->second->FindImage(count);
	}
	return nullptr;
}

void cImageManager::Render(cTexture * texture, Point pos, bool center, UINT rgb)
{
	HDC m_MemDC;
	HBITMAP OldBitMap;

	m_MemDC = CreateCompatibleDC(m_hdc);
	OldBitMap = (HBITMAP)SelectObject(m_MemDC, texture->m_image);

	//BitBlt(m_hdc, pos.x, pos.y, texture->m_info->bmWidth, 
	//	texture->m_info->bmHeight, m_MemDC, 0, 0, SRCCOPY);

	if (!center) {
		TransparentBlt(m_hdc, pos.x, pos.y,
			texture->m_info->bmWidth, texture->m_info->bmHeight, m_MemDC, 0, 0,
			texture->m_info->bmWidth, texture->m_info->bmHeight, rgb);
	}
	else {
		TransparentBlt(m_hdc, pos.x  - texture->m_info->bmWidth / 2, pos.y - texture->m_info->bmHeight / 2,
			texture->m_info->bmWidth, texture->m_info->bmHeight, m_MemDC, 0, 0,
			texture->m_info->bmWidth, texture->m_info->bmHeight, rgb);
	}

	//if (x != 0 && y != 0 && str != 0)
	//{
	//	SetTextAlign(m_MemDC, TA_CENTER);
	//	SetTextColor(m_MemDC, RGB(255, 0, 255));
	//	SetBkMode(m_MemDC, TRANSPARENT);
	//	TextOut(m_MemDC, x, y, str, lstrlenW(str));
	//	BitBlt(m_hdc, x, y, 0, 0, m_MemDC, 0, 0, SRCCOPY);
	//}

	SelectObject(m_MemDC, OldBitMap);
	DeleteDC(m_MemDC);
	DeleteObject(OldBitMap);
}

void cImageManager::TextRender(cTexture * texture, wchar_t* str, int x, int y, COLORREF rgb, int fontSize)
{
	HDC hdc;
	HDC m_MemDC;
	HBITMAP tmpBitMap;
	HFONT font, oldfont;
	//AddFontResource(L"./Font/BMJUA_ttf.ttf");

	m_MemDC = CreateCompatibleDC(m_hdc);
	tmpBitMap = (HBITMAP)SelectObject(m_MemDC, texture->m_image);

	font = CreateFont(fontSize, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 0, 0, 0, 0, L"배달의민족 주아");
	oldfont = (HFONT)SelectObject(m_MemDC, font);

	SetTextAlign(m_MemDC, TA_CENTER);
	SetTextColor(m_MemDC, rgb);
	SetBkMode(m_MemDC, TRANSPARENT);
	TextOut(m_MemDC, x, y, str, lstrlenW(str));

	SelectObject(m_MemDC, oldfont);
	DeleteObject(font);
	SelectObject(m_MemDC, tmpBitMap);
	//DeleteObject(tmpBitMap);
	//DeleteDC(m_MemDC);
}

bool cFrame::Frame()
{
	if (FrameSkip <= timeGetTime()) {
		if (NowFrame == EndFrame)
			NowFrame = StartFrame;
		else
			NowFrame++;

		FrameSkip = FrameDelay + timeGetTime();

		return true;
	}
	return false;
}

void cFrame::SetFrame(int start, int end, unsigned long delay)
{
	NowFrame = StartFrame = start;
	EndFrame = end;
	FrameDelay = delay;
	FrameSkip = FrameDelay + timeGetTime();
}
