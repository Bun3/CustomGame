#include "stdafx.h"

#include "cCustomGame.h"

#include "cPuzzle.h"
#include "cButton.h"
#include "cOX.h"

const int RectRadius = 27;

RECTINFO* RectInfo[4][4] = { NULL };

cPuzzle::cPuzzle()
{
}


cPuzzle::~cPuzzle()
{
}

void cPuzzle::Init()
{

	srand((unsigned int)time(NULL));
	InGameMapNum = rand() % 4;

	//스테이지에 따른 렉트 생성
	switch (InGameMapNum) {
	case 0: {
		RectInfo[InGameMapNum][0] = InitRect({ 315,36 });	//머리 위 꽃
		RectInfo[InGameMapNum][1] = InitRect({ 603,29 });  // CCTV
		RectInfo[InGameMapNum][3] = InitRect({ 93,379 });  // 괴물
		RectInfo[InGameMapNum][2] = InitRect({ 340,104 }); // 입
		break;
	}
	case 1: {
		RectInfo[InGameMapNum][0] = InitRect({ 331,48 });  // 머리
		RectInfo[InGameMapNum][1] = InitRect({ 603,29 });  // CCTV
		RectInfo[InGameMapNum][2] = InitRect({ 340,104 }); // 입
		RectInfo[InGameMapNum][3] = InitRect({ 93,379 });  // 괴물
		break;
	}
	case 2: {
		RectInfo[InGameMapNum][0] = InitRect({ 305,42 });  // 꽃
		RectInfo[InGameMapNum][1] = InitRect({ 603,29 });  // CCTV
		RectInfo[InGameMapNum][2] = InitRect({ 337,72 });  // 눈
		RectInfo[InGameMapNum][3] = InitRect({ 336,145 }); // 옷
		break;
	}
	case 3: {
		RectInfo[InGameMapNum][0] = InitRect({ 315,36 });	//머리 위 꽃
		RectInfo[InGameMapNum][1] = InitRect({ 603,29 });  // CCTV
		RectInfo[InGameMapNum][2] = InitRect({ 340,104 }); // 입
		RectInfo[InGameMapNum][3] = InitRect({ 93,379 });  // 괴물
		break;
	}
	}


	//이미지 pos 설정
	{
		m_BGPos = { 0,0 };
		for (int i = 0; i < 3; i++)
		{
			m_LifePos[i] = { i * 47 + 380, 483 };
		}
		m_ResultPos = { 320, 460 };
	}

	//전역 변수 초기화
	{
		Life = 3;				//목숨 3개
		RightAnswer = 0;		//정답 수

		//시간 설정
		fStartTime = (float)timeGetTime();
		TimeLimit = 15;
	}

	m_GotoMainButton = new cButton(460, 630, "GotoMainButton");
	b_Result = false; //결과창 비활성화
}

void cPuzzle::Update()
{
	if (!b_Result) {
		if (INPUT->MouseLDown()) {
			m_MousePos = INPUT->GetMousePos();
			ScreenToClient(g_hWnd, &m_MousePos);
			RectCheck(m_MousePos);
		}

		//시간 초기화, 제한 시간 업데이트
		float NowTime = (float)timeGetTime();
		if (NowTime - fStartTime >= 100)
		{
			TimeLimit -= 0.1;
			//DEBUG_LOG(TimeLimit);
			fStartTime = NowTime;
		}
	}

	if (m_GotoMainButton->Update()) {
		cCustomGame::nPlayerKey += RightAnswer;
		SCENE->ChangeScene("Custom_BG");
	}


	for (auto iter : m_OX) {
		iter->Update();
	}

	if (RightAnswer >= 4 || TimeLimit <= 0 || Life <= 0) { b_Result = true; }

}

void cPuzzle::Render()
{
	//스테이지에 따른 배경 출력
	switch (InGameMapNum)
	{
	case 0: IMAGE->Render(IMAGE->FindImage("Puzzle_BG1"), m_BGPos, false);  break;
	case 1: IMAGE->Render(IMAGE->FindImage("Puzzle_BG2"), m_BGPos, false);  break;
	case 2: IMAGE->Render(IMAGE->FindImage("Puzzle_BG3"), m_BGPos, false);  break;
	case 3: IMAGE->Render(IMAGE->FindImage("Puzzle_BG4"), m_BGPos, false);  break;
	case 4: IMAGE->Render(IMAGE->FindImage("Puzzle_BG5"), m_BGPos, false);  break;
	}

	for (auto iter : m_OX) {
		(*iter).Render();
	}

	//이미지
	{
		if (Life > 2)IMAGE->Render(IMAGE->FindImage("Life1"), m_LifePos[0], true, RGB(255, 0, 255));
		if (Life > 1)IMAGE->Render(IMAGE->FindImage("Life2"), m_LifePos[1], true, RGB(255, 0, 255));
		if (Life > 0)IMAGE->Render(IMAGE->FindImage("Life3"), m_LifePos[2], true, RGB(255, 0, 255));
	}

	//텍스트
	{
		char time[1024] = "";
		sprintf(time, "%.1f", TimeLimit);
		IMAGE->TextRender(time, 230, 468, RGB(0, 0, 0), 40);
		char timesec[1024] = "";
		sprintf(timesec, "sec");
		IMAGE->TextRender(timesec, 302, 468, RGB(0, 0, 0), 40);
		char anwser[1024] = "";
		sprintf(anwser, "%d/4", RightAnswer);
		IMAGE->TextRender(anwser, 157, 468, RGB(0, 0, 0), 40);
	}


	if (b_Result) {
		IMAGE->Render(IMAGE->FindImage("Result"), m_ResultPos, true, RGB(255, 0, 255));
		//남은 하트
		char resultLife[1024] = "";
		sprintf(resultLife, "%d/3", Life);
		IMAGE->TextRender(resultLife, 400, 350, RGB(0, 0, 0), 50);
		//남은 시간
		char resultTime[1024] = "";
		sprintf(resultTime, "%.0f", abs(TimeLimit));
		IMAGE->TextRender(resultTime, 355, 520, RGB(0, 0, 0), 50);
		//남은 시간
		char resultTimeSec[1024] = "";
		sprintf(resultTimeSec, "sec", TimeLimit);
		IMAGE->TextRender(resultTimeSec, 410, 520, RGB(0, 0, 0), 50);
		//정답 수
		char resultAnwser[1024] = "";
		sprintf(resultAnwser, "%d/4", RightAnswer);
		IMAGE->TextRender(resultAnwser, 400, 435, RGB(0, 0, 0), 50);
		//획득 열쇠 수
		sprintf(resultAnwser, "+%d", RightAnswer);
		IMAGE->TextRender(resultAnwser, 215, 610, RGB(0, 0, 0), 50);
		m_GotoMainButton->Render(RGB(255, 0, 255));
	}
}

void cPuzzle::Release()
{
	//생성된 구조체 5개 초기화
	for (int i = 0; i < 4; i++)
	{
		free(RectInfo[InGameMapNum][i]);
	}
	SAFE_DELETE(m_GotoMainButton);

	for (auto iter : m_OX) {
		SAFE_DELETE(iter);
	}
	m_OX.clear();
}

//클릭 시 렉트와 충돌 체크 후 액션
bool cPuzzle::RectCheck(POINT MousePt)
{
	for (int i = 0; i < 4; i++)
	{
		if (PtInRect(&RectInfo[InGameMapNum][i]->RoofRect, MousePt) || PtInRect(&RectInfo[InGameMapNum][i]->BottomRect, MousePt)) 
		{
			if (RectInfo[InGameMapNum][i]->RectActive) 
			{
				RectInfo[InGameMapNum][i]->RectActive = false;
				m_OX.push_back(new cOX({ RectInfo[InGameMapNum][i]->Center.x, RectInfo[InGameMapNum][i]->Center.y }, IMAGE->FindImage("Correct"), 7, 30));
				m_OX.push_back(new cOX({ RectInfo[InGameMapNum][i]->Center.x, RectInfo[InGameMapNum][i]->Center.y + 490 }, IMAGE->FindImage("Correct"), 7, 30));
				RightAnswer++;
				return true;
			}
		}
	}
	if (MousePt.y > 500) {
		m_OX.push_back(new cOX({ MousePt.x, MousePt.y }, IMAGE->FindImage("Wrong"), 7, 30));
		m_OX.push_back(new cOX({ MousePt.x, MousePt.y - 490 }, IMAGE->FindImage("Wrong"), 7, 30));
	}
	else {
		m_OX.push_back(new cOX({ MousePt.x, MousePt.y }, IMAGE->FindImage("Wrong"), 7, 30));
		m_OX.push_back(new cOX({ MousePt.x, MousePt.y + 490 }, IMAGE->FindImage("Wrong"), 7, 30));
	}
	Life--;
	return false;
}

RECTINFO* InitRect(POINT pos) {	//스테이지에 맞는 렉트 4쌍을 생성함

	RECTINFO* temp;
	temp = (RECTINFO*)malloc(sizeof(RECTINFO));

	temp->Center = { pos };
	temp->RoofRect.left = pos.x - RectRadius; temp->RoofRect.right = pos.x + RectRadius;
	temp->RoofRect.top = pos.y - RectRadius; temp->RoofRect.bottom = pos.y + RectRadius;
	temp->BottomRect.left = pos.x - RectRadius; temp->BottomRect.right = pos.x + RectRadius;
	temp->BottomRect.top = pos.y - RectRadius + 490; temp->BottomRect.bottom = pos.y + RectRadius + 490;
	temp->RectActive = true;

	return temp;
}