#pragma once
#include "cImageManager.h"
#include "cTexture.h"
class cTexture;
class cFrame {
public :
	int NowFrame;
	int StartFrame;
	int EndFrame;
	unsigned long FrameDelay;
	unsigned long FrameSkip;

	bool Frame();
	void SetFrame(int start ,int end , unsigned long delay);
};
class cImageManager : public singleton<cImageManager>
{
private:
	HDC m_hdc;
	HWND m_hwnd;
	map<string , cTexture *> m_image;
public:
	cImageManager();
	virtual ~cImageManager();

	void Init();

	cTexture * AddImage(const string& key, const string& path, int count = 0);
	cTexture * FindImage(const string& key, int count = -1);

	//void PrintText(const string& str, Vec2 pos, float size, D3DCOLOR color, bool center = false);
	void Render(cTexture * texture, Point pos, bool center = false, UINT rgb = NULL);

	void InputHDC(HDC hdc) {
		m_hdc = hdc;
	}

	void InputHWND(HWND hwnd) {
		m_hwnd = hwnd;
	}
};

#define IMAGE cImageManager::GetInstance()
