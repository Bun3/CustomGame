#include "stdafx.h"
#include "cSingleTexture.h"


cSingleTexture::cSingleTexture()
{
}


cSingleTexture::~cSingleTexture()
{
	SAFE_DELETE(m_info);
	SAFE_DELETE(m_Oldimage);
}

cTexture * cSingleTexture::AddImage(const string & path, int count)
{
	m_str = wstring(path.begin(), path.end());
	m_info = new BITMAP;

	m_image = (HBITMAP)LoadImage(NULL, m_str.c_str(), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	
	if (m_image == nullptr) {
		DEBUG_LOG("이미지 오류" << " " << path.c_str() << " " << "로드 실패");
	}

	GetObject(m_image, sizeof(BITMAP), m_info);
	
	return this;
}

cTexture * cSingleTexture::FindImage(int count)
{
	return this;
}

