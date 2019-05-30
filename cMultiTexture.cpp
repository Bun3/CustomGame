#include "stdafx.h"
#include "cMultiTexture.h"
#include "cSingleTexture.h"


cMultiTexture::cMultiTexture()
{
}


cMultiTexture::~cMultiTexture()
{
	for (auto iter : m_VecTex)
		SAFE_DELETE(iter);
}

cTexture * cMultiTexture::AddImage(const string & path, int count)
{
	char sz[128] = "";
	for (int i = 0; i <= count; i++) {
		sprintf_s(sz, path.c_str(), i);
		cTexture * pTex = new cSingleTexture;
		pTex->AddImage(sz);
		m_VecTex.push_back(pTex);
	}
	return this;
}

cTexture * cMultiTexture::FindImage(int count)
{
	if (count == -1)
		return this;
	else
		return m_VecTex[count];
}

