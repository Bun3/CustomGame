#pragma once
#include "cScene.h"
class cIngameScene : public cScene
{
private:
	cFrame * m_PlayerFrame;
	Point Pos;
	bool b_Move;
public:
	cIngameScene();
	virtual ~cIngameScene();

	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
};

