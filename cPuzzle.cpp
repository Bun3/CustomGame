#include "stdafx.h"
#include "cPuzzle.h"


cPuzzle::cPuzzle()
{
}


cPuzzle::~cPuzzle()
{
}

void cPuzzle::Init()
{
	m_BGPos.x = 0;
	m_BGPos.y = 0;
}

void cPuzzle::Update()
{
}

void cPuzzle::Render()
{
	IMAGE->Render(IMAGE->FindImage("Puzzle_BG"), m_BGPos, false);
}

void cPuzzle::Release()
{
}
