#pragma once
#include "cScene.h"

class cOX;
class cButton;
class cPuzzle :
	public cScene
{
private:
	Point m_BGPos;
	Point m_UIPos;
	Point m_LifePos[3];
	POINT m_MousePos;
	Point m_ResultPos;
	bool b_Result;

	cButton *m_GotoMainButton;

	vector<cOX *> m_OX;

	bool RectCheck(POINT MousePt);

public:


	cPuzzle();
	virtual ~cPuzzle();

	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
};

#pragma once

#define LWALK	10000
#define LTURN   10010
#define RWALK	10001
#define RTURN	10011

typedef struct RECTINFO {

	POINT Center;
	RECT RoofRect;
	RECT BottomRect;

	bool RectActive;

}RECTINFO;

RECTINFO* InitRect(POINT pos);