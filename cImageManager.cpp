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

void cImageManager::Render(cTexture * texture, Point pos, bool center , UINT rgb)
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

	SelectObject(m_MemDC, OldBitMap);
	DeleteDC(m_MemDC);
	DeleteObject(OldBitMap);
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
