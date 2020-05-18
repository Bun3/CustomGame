#include "stdafx.h"
#include "CSound.h"

CSound::CSound(DWORD _DeviceID)
	: m_DeviceID(_DeviceID)
{
}

CSound::~CSound()
{
	mciSendCommand(m_DeviceID, MCI_CLOSE, 0, NULL);
}
