#pragma once
#include "cButton.h"

class cPartButton :
	public cButton
{
private:
	cTexture* m_Normal;
	cTexture* m_Lock;
	cTexture* m_Click;
	cTexture* m_Equip;
	cTexture* m_OnCursor;

	Point m_pos;
	RECT m_rt;

	bool b_Click;
	bool b_OnCursor;
	bool b_Equip;
	int s_State;

public:
	cPartButton();
	cPartButton(int x, int y, const string& key, State _state);
	virtual ~cPartButton();

	bool Update(int &_keyVal);
	void Render();

	int GetState() { return s_State; }
	void SetState(int state) { s_State = state; }

	bool GetEquip() { return b_Equip; }
	void SetEquip(bool _Equip) { b_Equip = _Equip; }

	void ChangeImage(const string& key);
};

