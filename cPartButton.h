#pragma once
#include "cButton.h"

class cPartButton :
	public cButton
{
private:
	cTexture* m_Activate;
	cTexture* m_Lock;
	cTexture* m_Click;

	Point m_pos;
	RECT m_rt;

	bool b_Click;
	bool b_Lock;

public:
	cPartButton();
	cPartButton(int x, int y, const string& key);
	virtual ~cPartButton();

	bool Update();
	void Render();

	void ChangeImage(const string& key);
};

