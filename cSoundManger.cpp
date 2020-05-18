#include "stdafx.h"
#include "cSoundManger.h"


cSoundManger::cSoundManger()
{
}

cSoundManger::~cSoundManger()
{
	mciSendCommand(1, MCI_CLOSE, 0, (DWORD)(LPVOID)NULL);
}

DWORD cSoundManger::LoadBGM(HWND hWnd, wstring lpszMP3) //MP3 파일 uint 변수에 담고 함수로 실행
{
	DWORD result;

	m_MciOpen.lpstrDeviceType = L"mpegvideo";
	m_MciOpen.lpstrElementName = lpszMP3.c_str();
	m_MciOpen.lpstrAlias = NULL;
	m_MciOpen.wDeviceID = 0;

	result = mciSendCommandW(wID, MCI_OPEN, MCI_OPEN_TYPE | MCI_OPEN_ELEMENT, (DWORD)(LPVOID)&m_MciOpen);

	if (result)
	{
		m_BGM = result;
		return m_BGM;
	}

	wID = m_MciOpen.wDeviceID;

	m_MciPlay.dwCallback = (DWORD)hWnd;

	if (result)
	{
		m_BGM = result;
		return m_BGM;
	}

	return 0;
}

void cSoundManger::PlayBGM(UINT BGM)
{
	m_BGM = mciSendCommand(wID, MCI_PLAY, MCI_DGV_PLAY_REPEAT, (DWORD)(LPVOID)&m_MciPlay);
}
