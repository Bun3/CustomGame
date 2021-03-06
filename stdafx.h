// stdafx.h : 자주 사용하지만 자주 변경되지는 않는
// 표준 시스템 포함 파일 또는 프로젝트 관련 포함 파일이
// 들어 있는 포함 파일입니다.
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용은 Windows 헤더에서 제외합니다.
// Windows 헤더 파일:
#include <windows.h>

// C 런타임 헤더 파일입니다.

#include <iostream>
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <algorithm>
#include <time.h>
#include <timeapi.h>
#include <mmsystem.h>
#include <Digitalv.h>

using namespace std;

#define PURE = 0

#ifndef SAFE_DELETE
#define SAFE_DELETE(p)       { if (p) { delete (p);     (p)=NULL; } }
#endif    
#ifndef SAFE_DELETE_ARRAY
#define SAFE_DELETE_ARRAY(p) { if (p) { delete[] (p);   (p)=NULL; } }
#endif    
#ifndef SAFE_RELEASE
#define SAFE_RELEASE(p)      { if (p) { (p)->Release(); (p)=NULL; } }
#endif

#ifdef _DEBUG
#define DEBUG_LOG(log) cout << log << endl;
#else
#define DEBUG_LOG(log)
#endif // _DEBUG


const int WINSIZEX = 640;
const int WINSIZEY = 1000;

extern HWND g_hWnd;

struct Point
{
	int x;
	int y;
};

enum State { Lock, UnLock };

static int InGameMapNum;   //스테이지 넘버
static int Life;         //게임 목숨
static float fStartTime;   //게임 시작 시간
static float TimeLimit;      //게임 제한 시간
static int RightAnswer;      //현재 정답 수

// TODO: 프로그램에 필요한 추가 헤더는 여기에서 참조합니다.

//Manager
#include "cSceneManager.h"
#include "cImageManager.h"
#include "cInputManager.h"
#include "cSoundManger.h"
#include "CSound.h"
