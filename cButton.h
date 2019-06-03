#pragma once
class cButton
{
private:
	cTexture * m_Normal;
	cTexture * m_OnCursor;
	cTexture * m_Click;

	Point m_pos;
	RECT m_rt;

	bool b_OnCursor;
	bool b_Click;
public:
	cButton();
	cButton(int x, int y, const string& key);
	virtual ~cButton();

	bool Update();
	void Render();
};

