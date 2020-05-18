#include "stdafx.h"
#include "cMainGame.h"

#include "cLoadScene.h"
#include "cCustomGame.h"
#include "cTitle.h"
#include "cPuzzle.h"

cMainGame::cMainGame()
{
}


cMainGame::~cMainGame()
{
}

void cMainGame::Init(HWND hWnd)
{
	m_hWnd = hWnd;

	m_hDC = GetDC(m_hWnd);

	SetTimer(m_hWnd, 0, 1000, NULL);

	IMAGE->Init();

	//Init 에서 Scene을 추가시켜준다 순서대로 이름, Scene 클래스
	SCENE->AddScene("Load", new cLoadScene);
	SCENE->AddScene("Custom_BG", new cCustomGame);
	SCENE->AddScene("Title_BG", new cTitle);
	SCENE->AddScene("Puzzle_BG", new cPuzzle);
	//처음으로 보여줄 씬으로 바꾼다
	SCENE->ChangeScene("Load");
	//SOUND.Play("S", true);

}

void cMainGame::Update()
{
	SOUND2->PlayBGM();
	SCENE->Update();
	INPUT->Update();
	Count++;
}

void cMainGame::Render()
{
	HDC m_MemDC;
	HBITMAP hBitmap;
	HBITMAP OldBitMap;

	RECT WindowRect;
	GetClientRect(m_hWnd, &WindowRect);

	m_MemDC = CreateCompatibleDC(m_hDC);
	hBitmap = CreateCompatibleBitmap(m_hDC, WindowRect.right, WindowRect.bottom);
	OldBitMap = (HBITMAP)SelectObject(m_MemDC, hBitmap);

	IMAGE->InputHDC(m_MemDC);
	SCENE->Render();

	BitBlt(m_hDC, 0, 0, WindowRect.right, WindowRect.bottom, m_MemDC, 0, 0, SRCCOPY);
	DeleteObject(SelectObject(m_MemDC, OldBitMap));
	DeleteDC(m_MemDC);

}

void cMainGame::Release()
{
	KillTimer(m_hWnd, 0);

	cSoundManger::ResetInstance();
	cImageManager::ResetInstance();
	cInputManager::ResetInstance();
	cSceneManager::ResetInstance();
}

void cMainGame::InputHDC(HDC hdc)
{
	m_hDC = hdc;
}

void cMainGame::InputHINSTANCE(HINSTANCE hinstance)
{
	m_hIns = hinstance;
}
