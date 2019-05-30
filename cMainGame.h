#pragma once
class cMainGame
{
private: 
	HDC							m_hDC;
	HWND						m_hWnd;

	HINSTANCE					m_hIns;

	int Count;
public:
	cMainGame();
	~cMainGame();

	int a = 0;

	void Init(HWND hWnd);
	void Update();
	void Render();
	void Release();

	void InputHDC(HDC hdc);
	void InputHINSTANCE(HINSTANCE hinstance);

	void InputCount(int a) { Count = a; }
	int GetCount() { return Count; }
};

