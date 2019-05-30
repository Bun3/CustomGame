#pragma once
#include "cScene.h"

class cPuzzle :
	public cScene
{
private:
	Point m_BGPos;
public:
	cPuzzle();
	virtual ~cPuzzle();

	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
};

