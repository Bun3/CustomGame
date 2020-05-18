#include "stdafx.h"
#include "cInputManager.h"

cInputManager::cInputManager()
{
}

cInputManager::~cInputManager()
{
}

bool cInputManager::MouseLPress()
{
	return (NowMouse[0] == true && OldMouse[0] == true);
}

bool cInputManager::MouseLUp()
{
	return (NowMouse[0] == false && OldMouse[0] == true);
}

bool cInputManager::MouseLDown()
{
	return (NowMouse[0] == true && OldMouse[0] == false);
}

bool cInputManager::MouseRPress()
{
	return (NowMouse[1] == true && OldMouse[1] == true);
}

bool cInputManager::MouseRUp()
{
	return (NowMouse[1] == false && OldMouse[1] == true);
}

bool cInputManager::MouseRDown()
{
	return (NowMouse[1] == true && OldMouse[1] == false);
}

bool cInputManager::KeyPress(int key)
{
	return (NowInput[key] == true && OldInput[key] == true);
}

bool cInputManager::KeyUp(int key)
{
	return (NowInput[key] == false && OldInput[key] == true);
}

bool cInputManager::KeyDown(int key)
{
	return (NowInput[key] == true && OldInput[key] == false);
}


void cInputManager::Init(HWND hwnd)
{
	m_hwnd = hwnd;
}

void cInputManager::Update()
{
	for (int i = 0; i < 2; i++) {
		OldMouse[i] = NowMouse[i];
	}
	for (int i = 0; i < 256; i++) {
		OldInput[i] = NowInput[i];
	}

	for (int i = 0; i < 256; i++) {
		if (GetAsyncKeyState(i)) {
			NowInput[i] = true;
		}
		else
			NowInput[i] = false;
	}

	if (GetAsyncKeyState(VK_LBUTTON)) {
		NowMouse[0] = true;
	}
	else
		NowMouse[0] = false;

	if (GetAsyncKeyState(VK_RBUTTON)) {
		NowMouse[1] = true;
	}
	else
		NowMouse[1] = false;
}
