#include "stdafx.h"
#include "cLoadScene.h"

cLoadScene::cLoadScene()
{

}

cLoadScene::~cLoadScene()
{
}

void cLoadScene::Init()
{
	m_NowLoad = 0;

#pragma region Load

	//BackGroundImage
	{
		Load("Title_BG", "./Image/TitleScene/Title_BackGround.bmp");
		Load("Custom_BG", "./Image/CustomScene/Main_BackGround.bmp");
		Load("Puzzle_BG", "./Image/PuzzleScene/Puzzle_BackGround.bmp");
	}

	//CustomSceneImage
	{
		Load("KeyDisplay", "./Image/CustomScene/Key_Display.bmp");
		Load("CategoryBack", "./Image/CustomScene/Category/Category_BackGround.bmp");
		Load("CreditPopUP", "./Image/CustomScene/Credit_PopUp.bmp");
		Load("PartBack", "./Image/CustomScene/Part/Part_BackGround.bmp");

		Load("SaveButton_Normal", "./Image/CustomScene/Save_Button.bmp");
		Load("SaveButton_OnCursor", "./Image/CustomScene/Save_Button.bmp");
		Load("SaveButton_Click", "./Image/CustomScene/Save_Button.bmp");

		Load("CreditButton_Normal", "./Image/CustomScene/Credit_Button.bmp");
		Load("CreditButton_OnCursor", "./Image/CustomScene/Credit_Button.bmp");
		Load("CreditButton_Click", "./Image/CustomScene/Credit_Button.bmp");

		Load("ResetButton_Normal", "./Image/CustomScene/Reset_Button.bmp");
		Load("ResetButton_OnCursor", "./Image/CustomScene/Reset_Button.bmp");
		Load("ResetButton_Click", "./Image/CustomScene/Reset_Button.bmp");

		Load("GameStartButton_Normal", "./Image/CustomScene/Game_Start_Button.bmp");
		Load("GameStartButton_OnCursor", "./Image/CustomScene/Game_Start_Button.bmp");
		Load("GameStartButton_Click", "./Image/CustomScene/Game_Start_Button.bmp");

		Load("CreditBack_Normal", "./Image/CustomScene/Credit_BackButton.bmp");
		Load("CreditBack_OnCursor", "./Image/CustomScene/Credit_BackButton.bmp");
		Load("CreditBack_Click", "./Image/CustomScene/Credit_BackButton.bmp");

		//Category
		{
			Load("Skin_Normal", "./Image/CustomScene/Category/Category_Skin.bmp");
			Load("Skin_OnCursor", "./Image/CustomScene/Category/Category_Skin.bmp");
			Load("Skin_Click", "./Image/CustomScene/Category/Category_Skin.bmp");

			Load("Eye_Normal", "./Image/CustomScene/Category/Category_Eye.bmp");
			Load("Eye_OnCursor", "./Image/CustomScene/Category/Category_Eye.bmp");
			Load("Eye_Click", "./Image/CustomScene/Category/Category_Eye.bmp");

			Load("Mouth_Normal", "./Image/CustomScene/Category/Category_Mouth.bmp");
			Load("Mouth_OnCursor", "./Image/CustomScene/Category/Category_Mouth.bmp");
			Load("Mouth_Click", "./Image/CustomScene/Category/Category_Mouth.bmp");

			Load("Cloth_Normal", "./Image/CustomScene/Category/Category_Cloth.bmp");
			Load("Cloth_OnCursor", "./Image/CustomScene/Category/Category_Cloth.bmp");
			Load("Cloth_Click", "./Image/CustomScene/Category/Category_Cloth.bmp");

			Load("Hair_Normal", "./Image/CustomScene/Category/Category_Hair.bmp");
			Load("Hair_OnCursor", "./Image/CustomScene/Category/Category_Hair.bmp");
			Load("Hair_Click", "./Image/CustomScene/Category/Category_Hair.bmp");
		}

		//Part
		{
			for (size_t i = 1; i < 5; i++)
			{
				Load(string("PartSkin_") + to_string(i) + "_Active",
					string("./Image/CustomScene/Part/Part_Skin_") + to_string(i) + ".bmp");
				Load(string("PartSkin_") + to_string(i) + "_Lock",
					string("./Image/CustomScene/Part/Part_Skin_") + to_string(i) + ".bmp");
				Load(string("PartSkin_") + to_string(i) + "_Click",
					string("./Image/CustomScene/Part/Part_Skin_") + to_string(i) + ".bmp");

				Load(string("PartEye_") + to_string(i) + "_Active",
					string("./Image/CustomScene/Part/Part_Eye_") + to_string(i) + ".bmp");
				Load(string("PartEye_") + to_string(i) + "_Lock",
					string("./Image/CustomScene/Part/Part_Eye_") + to_string(i) + ".bmp");
				Load(string("PartEye_") + to_string(i) + "_Click",
					string("./Image/CustomScene/Part/Part_Eye_") + to_string(i) + ".bmp");
				
				Load(string("PartMouth_") + to_string(i) + "_Active",
					string("./Image/CustomScene/Part/Part_Mouth_") + to_string(i) + ".bmp");
				Load(string("PartMouth_") + to_string(i) + "_Lock",
					string("./Image/CustomScene/Part/Part_Mouth_") + to_string(i) + ".bmp");
				Load(string("PartMouth_") + to_string(i) + "_Click",
					string("./Image/CustomScene/Part/Part_Mouth_") + to_string(i) + ".bmp");

				Load(string("PartCloth_") + to_string(i) + "_Active",
					string("./Image/CustomScene/Part/Part_Cloth_") + to_string(i) + ".bmp");
				Load(string("PartCloth_") + to_string(i) + "_Lock",
					string("./Image/CustomScene/Part/Part_Cloth_") + to_string(i) + ".bmp");
				Load(string("PartCloth_") + to_string(i) + "_Click",
					string("./Image/CustomScene/Part/Part_Cloth_") + to_string(i) + ".bmp");

				Load(string("PartHair_") + to_string(i) + "_Active",
					string("./Image/CustomScene/Part/Part_Hair_") + to_string(i) + ".bmp");
				Load(string("PartHair_") + to_string(i) + "_Lock",
					string("./Image/CustomScene/Part/Part_Hair_") + to_string(i) + ".bmp");
				Load(string("PartHair_") + to_string(i) + "_Click",
					string("./Image/CustomScene/Part/Part_Hair_") + to_string(i) + ".bmp");
			}
		}
	}

	//TitleSceneImage
	{
		Load("TitleTeamLogo", "./Image/TitleScene/Title_TeamLogo.bmp");
		Load("TitleLogo", "./Image/TitleScene/Title_Logo.bmp");
		Load("TitleIllust", "./Image/TitleScene/Title_Illust.bmp");

		Load("SGButton_Normal", "./Image/TitleScene/Start_Guide_Button.bmp");
		Load("SGButton_OnCursor", "./Image/TitleScene/Start_Guide_Button.bmp");
		Load("SGButton_Click", "./Image/TitleScene/Start_Guide_Button.bmp");
	}

#pragma endregion

	m_MaxLoad = m_Load.size();
}

void cLoadScene::Update()
{
	if (m_NowLoad != m_MaxLoad) 
	{
		IMAGE->AddImage
		(
			m_Load[m_NowLoad].key,
			m_Load[m_NowLoad].path,
			m_Load[m_NowLoad].count
		);
		m_NowLoad++;
	}
	else SCENE->ChangeScene("Title_BG");
}

void cLoadScene::Render()
{
}

void cLoadScene::Release()
{
}
