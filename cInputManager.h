#pragma once
#include "singleton.h"
class cInputManager : public singleton<cInputManager>
{
private:
	HWND m_hwnd;

	bool NowMouse[2];
	bool OldMouse[2];

	bool NowInput[256];
	bool OldInput[256];
public:
	cInputManager();
	virtual ~cInputManager();

	bool MouseLPress();
	bool MouseLUp();
	bool MouseLDown();

	bool MouseRPress();
	bool MouseRUp();
	bool MouseRDown();

	bool KeyPress(int key);
	bool KeyUp(int key);
	bool KeyDown(int key);

	void Init(HWND hwnd);
	void Update();

	POINT GetMousePos() {
		POINT pt;
		GetCursorPos(&pt);
		ScreenToClient(m_hwnd, &pt);
	
		return pt;
	}
};
#define INPUT cInputManager::GetInstance()