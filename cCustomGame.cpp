#include "stdafx.h"
#include "cCustomGame.h"

#include "cButton.h"
#include "cPartButton.h"

int cCustomGame::nPlayerKey = 0;

cCustomGame::cCustomGame()
{
	for (int i = 0; i < 5; i++)
	{
		b_PartVisible[i] = true;
	}
}

cCustomGame::~cCustomGame()
{
	b_LoadOnce = true;
}

void cCustomGame::Init()
{
	m_BGPos.x = -10;
	m_BGPos.y = 0;

	m_KeyPos.x = 0; 
	m_KeyPos.y = 0;

	m_KeyValPos.x = 0;
	m_KeyValPos.y = 0;

	m_CategoryBack_Pos.x = 320;
	m_CategoryBack_Pos.y = 650;
	m_PartBack_Pos.x = 320;
	m_PartBack_Pos.y = 850;

	{
		m_CategoryPos[0].x = 53;
		m_CategoryPos[1].x = 177;
		m_CategoryPos[2].x = 312;
		m_CategoryPos[3].x = 440;
		m_CategoryPos[4].x = 567;
	}

	for (int i = 0; i < 5; i++)
		m_CategoryPos[i].y = 729;

	m_CreditPopUpPos.x = 320;
	m_CreditPopUpPos.y = 450;

	for (int i = 0; i < 4; i++)
	{
		m_PartPos[i].x = (i * 150) + 85;
		m_PartPos[i].y = 869;
	}

	m_ImagePos = { 0,0 };

	m_CTGY_EnablePos = m_CategoryPos[Skin];

	b_Credit = false;
	b_PartVisible[Skin] = true;
	m_CategoryState = Skin;

	m_SaveButton = new cButton(40, 480, "SaveButton");
	m_CreditButton = new cButton(40, 560, "CreditButton");
	m_ResetButton = new cButton(40, 640, "ResetButton");
	m_GMSButton = new cButton(565, 625, "GameStartButton");
	m_CreditBackButton = new cButton(480, 640, "CreditBack");

	m_CTGY_Skin = new cButton(m_CategoryPos[Skin].x, m_CategoryPos[Skin].y, "Skin");
	m_CTGY_Eye = new cButton(m_CategoryPos[Eye].x, m_CategoryPos[Eye].y, "Eye");
	m_CTGY_Mouth = new cButton(m_CategoryPos[Mouth].x, m_CategoryPos[Mouth].y, "Mouth");
	m_CTGY_Cloth = new cButton(m_CategoryPos[Cloth].x, m_CategoryPos[Cloth].y, "Cloth");
	m_CTGY_Hair = new cButton(m_CategoryPos[Hair].x, m_CategoryPos[Hair].y, "Hair");

	for (size_t i = 0; i < 4; i++)
	{
		m_PartButton[Skin][i] =
			new cPartButton(m_PartPos[i].x, m_PartPos[i].y, string("PartSkin_") + to_string(i + 1), i + 1 < 3 ? UnLock : Lock);
		m_PartButton[Mouth][i] =
			new cPartButton(m_PartPos[i].x, m_PartPos[i].y, string("PartMouth_") + to_string(i + 1), i + 1 < 3 ? UnLock : Lock);
		m_PartButton[Eye][i] =
			new cPartButton(m_PartPos[i].x, m_PartPos[i].y, string("PartEye_") + to_string(i + 1), i + 1 < 3 ? UnLock : Lock);
		m_PartButton[Cloth][i] =
			new cPartButton(m_PartPos[i].x, m_PartPos[i].y, string("PartCloth_") + to_string(i + 1), i + 1 < 3 ? UnLock : Lock);
		m_PartButton[Hair][i] =
			new cPartButton(m_PartPos[i].x, m_PartPos[i].y, string("PartHair_") + to_string(i + 1), i + 1 < 3 ? UnLock : Lock);
	}

	if (b_LoadOnce)
	{
		b_LoadOnce = false;
		LoadKey();
		LoadCloth();
		LoadUnLock();
		LoadEquip();
	}
	LoadUnLock();
	LoadEquip();
	//SOUND->LoadBGM(g_hWnd, L"./Sound/BGM.mp3");
	//DEBUG_LOG(nPlayerKey);
}

void cCustomGame::Update()
{

	if (!b_Credit)
	{
		if (m_SaveButton->Update()) 
		{
			SaveKey();
			SaveCloth();
			SaveEquip();
			Capture(GetDC(g_hWnd), WINSIZEX - 20, WINSIZEY - 40);
		}
		if (INPUT->MouseRUp()) nPlayerKey++;
		if (m_ResetButton->Update()) 
		{
			for (int i = 1; i < 5; i++)
			{
				b_PartVisible[i] = false;
				m_ImageNum[Skin] = 1;
			}

			for (int a = 0; a < 5; a++)
				for (int i = 0; i < 4; i++)
					m_PartButton[a][i]->SetEquip(false);

			m_PartButton[Skin][0]->SetEquip(true);
		}

		if (m_CTGY_Skin->Update()) 
		{ 
			m_CTGY_EnablePos = m_CategoryPos[Skin];
			m_CategoryState = Skin;
		}
		if (m_CTGY_Eye->Update()) 
		{ 
			m_CTGY_EnablePos = m_CategoryPos[Eye]; 
			m_CategoryState = Eye; 
		}
		if (m_CTGY_Mouth->Update()) 
		{ 
			m_CTGY_EnablePos = m_CategoryPos[Mouth];
			m_CategoryState = Mouth;
		}
		if (m_CTGY_Cloth->Update()) 
		{
			m_CTGY_EnablePos = m_CategoryPos[Cloth];
			m_CategoryState = Cloth; 
		}
		if (m_CTGY_Hair->Update()) 
		{ 
			m_CTGY_EnablePos = m_CategoryPos[Hair];
			m_CategoryState = Hair; 
		}

		if (m_CreditButton->Update()) { b_Credit = true; }
		if (m_GMSButton->Update()) { SCENE->ChangeScene("Puzzle_BG"); }

		for (int i = 0; i < 4; i++)
		{
			if (m_PartButton[m_CategoryState][i]->Update(nPlayerKey))
			{
				for (int z = 0; z < 4; z++)
					m_PartButton[m_CategoryState][z]->SetEquip(false);

				m_PartButton[m_CategoryState][i]->SetEquip(true);

				m_ImageNum[m_CategoryState] = i + 1;
				b_PartVisible[m_CategoryState] = true;
			}
		}

		switch (m_CategoryState)
		{
		case Skin:
			for (int i = 0; i < 4; i++)
				m_PartButton[m_CategoryState][i]->ChangeImage(string("PartSkin_") + to_string(i + 1));
			break;
		case Eye:
			for (int i = 0; i < 4; i++)
				m_PartButton[m_CategoryState][i]->ChangeImage(string("PartEye_") + to_string(i + 1));
			break;
		case Mouth:
			for (int i = 0; i < 4; i++)
				m_PartButton[m_CategoryState][i]->ChangeImage(string("PartMouth_") + to_string(i + 1));
			break;
		case Cloth:
			for (int i = 0; i < 4; i++)
				m_PartButton[m_CategoryState][i]->ChangeImage(string("PartCloth_") + to_string(i + 1));
			break;
		case Hair:
			for (int i = 0; i < 4; i++)
				m_PartButton[m_CategoryState][i]->ChangeImage(string("PartHair_") + to_string(i + 1));
			break;
		}
	}

	if (m_CreditBackButton->Update() && b_Credit) { b_Credit = false; }

	if (nPlayerKey >= 99)
		nPlayerKey = 99;
}

void cCustomGame::Render()
{
	char str[128] = "";
	sprintf_s(str, "%d", nPlayerKey);

	IMAGE->Render(IMAGE->FindImage("Custom_BG"), m_BGPos, false);

	IMAGE->Render(IMAGE->FindImage("SkinImage_" + to_string(m_ImageNum[Skin])), m_ImagePos, false, RGB(255, 0, 255));
	if (b_PartVisible[Hair])
		IMAGE->Render(IMAGE->FindImage("HairImage_" + to_string(m_ImageNum[Hair])), m_ImagePos, false, RGB(255, 0, 255));
	if (b_PartVisible[Eye])
		IMAGE->Render(IMAGE->FindImage("EyeImage_" + to_string(m_ImageNum[Eye])), m_ImagePos, false, RGB(255, 0, 255));
	if (b_PartVisible[Mouth])
		IMAGE->Render(IMAGE->FindImage("MouthImage_" + to_string(m_ImageNum[Mouth])), m_ImagePos, false, RGB(255, 0, 255));
	if (b_PartVisible[Cloth])
		IMAGE->Render(IMAGE->FindImage("ClothImage_" + to_string(m_ImageNum[Cloth])), m_ImagePos, false, RGB(255, 0, 255));

	IMAGE->TextRender(str, 80, 30, RGB(255, 255, 255), 50);

	IMAGE->Render(IMAGE->FindImage("CategoryEnable"), m_CTGY_EnablePos, true, RGB(255, 0, 242));

	m_SaveButton->Render();
	m_CreditButton->Render();
	m_ResetButton->Render();	
	m_GMSButton->Render();

	for (int j = 0; j < 4; j++)
		m_PartButton[m_CategoryState][j]->Render();

	if (b_Credit)
	{
		IMAGE->Render(IMAGE->FindImage("CreditPopUP"), m_CreditPopUpPos, true, RGB(255, 0, 242));
		m_CreditBackButton->Render();
	}
}

void cCustomGame::Release()
{
	SaveUnLock();
	for (int i = 0; i < 5; i++)
	{
		for (int j = 3; j >= 0; --j)
			SAFE_DELETE(m_PartButton[i][j]);
	}
	SAFE_DELETE(m_CTGY_Hair);
	SAFE_DELETE(m_CTGY_Cloth);
	SAFE_DELETE(m_CTGY_Mouth);
	SAFE_DELETE(m_CTGY_Eye);
	SAFE_DELETE(m_CTGY_Skin);
	SAFE_DELETE(m_CreditBackButton);
	SAFE_DELETE(m_GMSButton);
	SAFE_DELETE(m_ResetButton);
	SAFE_DELETE(m_CreditButton);  
	SAFE_DELETE(m_SaveButton);
}

void cCustomGame::SaveKey() //Key 값 저장
{
	fopen_s(&m_fp, "./Data/KeyDataFile.txt", "w");
	fprintf_s(m_fp, "%d\n", nPlayerKey);
	std::fclose(m_fp);
}

void cCustomGame::LoadKey() //Key 값 로드
{
	fopen_s(&m_fp, "./Data/KeyDataFile.txt", "r");
	fscanf_s(m_fp, "%d\n", &nPlayerKey);
	std::fclose(m_fp);
}

void cCustomGame::SaveCloth() // 옷 저장
{
	fopen_s(&m_fp, "./Data/ClothDataFile.txt", "w");
	for (int i = 0; i < 5; i++)
	{
		fprintf_s(m_fp, "%d\n", m_ImageNum[i]);
		fprintf_s(m_fp, "%d\n", b_PartVisible[i]);
	}
	std::fclose(m_fp);
}

void cCustomGame::LoadCloth() // 옷 로드
{
	fopen_s(&m_fp, "./Data/ClothDataFile.txt", "r");
	for (int i = 0; i < 5; i++)
	{
		fscanf_s(m_fp, "%d\n", &m_ImageNum[i]);
		fscanf_s(m_fp, "%d\n", &b_PartVisible[i]);
	}
	std::fclose(m_fp);
}

void cCustomGame::SaveUnLock() // 파츠의 언락 상태 저장
{
	fopen_s(&m_fp, "./Data/UnLockDataFile.txt", "w");
	for (int state = 0; state < 5; state++)
	{
		fprintf_s(m_fp, "%d\n%d\n", m_PartButton[state][2]->GetState(), m_PartButton[state][3]->GetState());
	}
	std::fclose(m_fp);
}

void cCustomGame::LoadUnLock() // 파츠 언락 상태 로드
{
	fopen_s(&m_fp, "./Data/UnLockDataFile.txt", "r");
	for (int state = 0; state < 5; state++)
	{
		int tmp1, tmp2 = 0;
		fscanf_s(m_fp, "%d\n%d\n", &tmp1, &tmp2);
		m_PartButton[state][2]->SetState(tmp1);
		m_PartButton[state][3]->SetState(tmp2);
	}
	std::fclose(m_fp);
}

void cCustomGame::SaveEquip() // 장착한 상태 저장
{
	fopen_s(&m_fp, "./Data/EquipDataFile.txt", "w");
	for (int state = 0; state < 5; state++)
		for (int i = 0; i < 4; i++)
			fprintf_s(m_fp, "%d\n", m_PartButton[state][i]->GetEquip());
	std::fclose(m_fp);
}

void cCustomGame::LoadEquip() // 장착한 상태 로드
{
	fopen_s(&m_fp, "./Data/EquipDataFile.txt", "r");
	for (int state = 0; state < 5; state++)
	{
		for (int i = 0; i < 4; i++)
		{
			int tmp = 0;
			fscanf_s(m_fp, "%d\n", &tmp);
			m_PartButton[state][i]->SetEquip(tmp);
		}
	}
	std::fclose(m_fp);
}

void cCustomGame::Capture(HDC _HDC, int w, int h) //캡처 피드맵 하나 만들고 dib 비트맵을 ddb 비트맵으로 변환
{
	SYSTEMTIME systime;

	BITMAPINFO dib = CreateDIB(w, h);
	BITMAPFILEHEADER dibLayOut = CreateDIBHeader(dib);

	BYTE *pImgData = NULL;
	HBITMAP hBmp = CreateDIBSection(_HDC, &dib, DIB_RGB_COLORS, (void**)&pImgData, 0, 0);

	HDC MemDC = CreateCompatibleDC(_HDC);
	HBITMAP hOldbmp = (HBITMAP)SelectObject(MemDC, hBmp);

	BitBlt(MemDC, 0, 0, w, h, _HDC, 0, 0, SRCCOPY);

	SelectObject(MemDC, hOldbmp);

	GetLocalTime(&systime);
	string savestr = "./Capture/" + to_string(systime.wYear) + "_" + to_string(systime.wMonth) + "_" + to_string(systime.wDay)
		+ "_" + to_string(systime.wHour) + "_" + to_string(systime.wMinute) + "_" + to_string(systime.wSecond)
		+ "_" + to_string(systime.wMilliseconds / 100) + ".bmp";

	FILE *pCapFile;
	fopen_s(&pCapFile, savestr.c_str(), "w+b");

	if (pCapFile)
	{
		fwrite(&dibLayOut, 1, sizeof(BITMAPFILEHEADER), pCapFile);
		fwrite(&dib, 1, sizeof(BITMAPINFOHEADER), pCapFile);
		fwrite(pImgData, 1, dib.bmiHeader.biSizeImage, pCapFile);
		std::fclose(pCapFile);
	}

	if (hBmp)
		DeleteObject(hBmp);

	DeleteDC(MemDC);
}

BITMAPINFO cCustomGame::CreateDIB(int w, int h) // DIB 방식 비트맵 정의 후 리턴
{
	BITMAPINFO dib; //BITMAPINFOHEADER를 가지고 있는 구조체

	dib.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
	dib.bmiHeader.biWidth = w;
	dib.bmiHeader.biHeight = h;
	dib.bmiHeader.biPlanes = 1;
	dib.bmiHeader.biBitCount = 24;
	dib.bmiHeader.biCompression = BI_RGB;
	dib.bmiHeader.biSizeImage = (((w * 24 + 31) & ~31) >> 3) * h;
	dib.bmiHeader.biXPelsPerMeter = 0;
	dib.bmiHeader.biYPelsPerMeter = 0;
	dib.bmiHeader.biClrImportant = 0;
	dib.bmiHeader.biClrUsed = 0;

	return dib;
}

BITMAPFILEHEADER cCustomGame::CreateDIBHeader(BITMAPINFO dib) //DIB 비트맵의 방식과 바이트 사이즈 계산 후 리턴
{
	BITMAPFILEHEADER dibLayOut;
	ZeroMemory(&dibLayOut, sizeof(BITMAPFILEHEADER));
	dibLayOut.bfType = *(WORD*)"BM";
	dibLayOut.bfSize = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER) + dib.bmiHeader.biSizeImage;
	dibLayOut.bfOffBits = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);

	return dibLayOut;
}
