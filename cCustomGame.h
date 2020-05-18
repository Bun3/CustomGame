#pragma once
#include "cScene.h"

typedef enum _Cate
{
	Skin, Eye, Mouth, Cloth, Hair
}CTGY;

typedef enum _Image
{
	FIRST = 1, SECOND, THIRD, FOURTH
}IMAGENUM;

class cButton;
class cPartButton;
class cCustomGame : public cScene
{
private:
	Point m_BGPos;
	Point m_KeyPos;
	Point m_CategoryBack_Pos;
	Point m_PartBack_Pos;
	Point m_CategoryPos[5];
	Point m_PartPos[4];
	Point m_CreditPopUpPos;
	Point m_KeyValPos;
	Point m_ImagePos;
	Point m_CTGY_EnablePos;

	cButton *m_SaveButton;
	cButton *m_CreditButton;
	cButton *m_ResetButton;
	cButton *m_GMSButton;
	cButton *m_CreditBackButton;

	cButton *m_CTGY_Skin;
	cButton *m_CTGY_Eye;
	cButton *m_CTGY_Mouth;
	cButton *m_CTGY_Cloth;
	cButton *m_CTGY_Hair;

	cPartButton *m_PartButton[5][4];

	FILE* m_fp;

	bool b_PartVisible[5]; //Skin ~ Hair 
	bool b_Credit;
	bool b_LoadOnce = true;
	bool b_InitOnce = true;
	int m_CategoryState;
	int m_ImageNum[5];

public:
	static int nPlayerKey;

public:
	cCustomGame();
	virtual ~cCustomGame();

	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;

	void SaveKey();
	void LoadKey();

	void SaveCloth();
	void LoadCloth();

	void SaveUnLock();
	void LoadUnLock();

	void SaveEquip();
	void LoadEquip();
	void Capture(HDC _HDC, int w, int h);
	BITMAPINFO CreateDIB(int w, int h);
	BITMAPFILEHEADER CreateDIBHeader(BITMAPINFO dib);

	inline void SetPlayerKey(int i) { nPlayerKey = i; };
	inline int GetPlayerKey() { return nPlayerKey; };
};

