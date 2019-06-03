#pragma once
#include "cScene.h"

typedef enum _Cate
{
	Skin, Eye, Mouth, Cloth, Hair
}CTGY;

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

	cPartButton *m_PartButton[4];

	FILE* m_fp;

	bool b_Credit;
	int m_CategoryState;
	int m_key;
	int m_tmpKey;

public:
	cCustomGame();
	virtual ~cCustomGame();

	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;

	void SaveKey(int _key);
};

