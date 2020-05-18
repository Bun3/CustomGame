#pragma once

class cOX
{
private :
	cTexture * m_Image;
	cFrame * m_Frame;
	Point m_Pos;
public:
	cOX(Point pos, cTexture * image, unsigned long end , unsigned long delay);
	~cOX();

	void Update();
	void Render();
};
