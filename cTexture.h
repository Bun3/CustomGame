#pragma once
class cTexture abstract
{
public:
	HBITMAP m_image;
	HBITMAP * m_Oldimage;

	BITMAP * m_info;

	HDC m_MemDC;

	wstring m_str;
public:
	cTexture();
	virtual ~cTexture();
	
	virtual cTexture * AddImage (const string& path , int count = 0) PURE;
	virtual cTexture * FindImage(int count = -1) PURE;
};

 