#pragma once

#include "cScene.h"
#include "cButton.h"

class cTitle : public cScene
{
private:
	Point m_BGPos;
	Point m_TeamLogoPos;
	Point m_LogoPos;
	Point m_IllustPos;

	cButton* m_StartGuideButton;

public:
	cTitle();
	~cTitle();

	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
};

