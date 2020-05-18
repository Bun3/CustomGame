#pragma once
#include "singleton.h"

//이거 영찬이가 만듬
class cSoundManger :
	public singleton<cSoundManger>
{
private:
	MCI_OPEN_PARMSW m_MciOpen;
	MCI_PLAY_PARMS m_MciPlay;
	MCI_STATUS_PARMS m_MciState;

	UINT wID = 0;
	UINT m_BGM;
public:
	cSoundManger();
	virtual ~cSoundManger();

	DWORD LoadBGM(HWND hWnd, wstring lpszMP3);
	void PlayBGM(UINT BGM = 0);

};

#define SOUND2 cSoundManger::GetInstance()

