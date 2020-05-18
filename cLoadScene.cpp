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

	SOUND2->LoadBGM(g_hWnd, L"./Sound/BGM.wav");
	//SOUND.AyddSound("S","./Sound/BGM.wav");
	//sndPlaySound(L"./Sound/BGM.wav", SND_LOOP);
	//BackGroundImage
	{
		Load("Title_BG", "./Image/TitleScene/Title_BackGround.bmp");
		Load("Custom_BG", "./Image/CustomScene/Main_BackGround.bmp");
		Load("Puzzle_BG1", "./Image/PuzzleScene/InGame_Background1.bmp");
		Load("Puzzle_BG2", "./Image/PuzzleScene/InGame_Background2.bmp");
		Load("Puzzle_BG3", "./Image/PuzzleScene/InGame_Background3.bmp");
		Load("Puzzle_BG4", "./Image/PuzzleScene/InGame_Background4.bmp");
	}

	//CustomSceneImage
	{
		Load("KeyDisplay", "./Image/CustomScene/Key_Display.bmp");
		Load("KeyBack", "./Image/CustomScene/KeyValBack.bmp");
		Load("CategoryBack", "./Image/CustomScene/Category/Category_BackGround.bmp");
		Load("CreditPopUP", "./Image/CustomScene/Credit_PopUp.bmp");

		Load("SaveButton_Normal", "./Image/CustomScene/Save_Button.bmp");
		Load("SaveButton_OnCursor", "./Image/CustomScene/Save_Button_OnCursor.bmp");
		Load("SaveButton_Click", "./Image/CustomScene/Save_Button_Click.bmp");

		Load("CreditButton_Normal", "./Image/CustomScene/Credit_Button.bmp");
		Load("CreditButton_OnCursor", "./Image/CustomScene/Credit_Button_OnCursor.bmp");
		Load("CreditButton_Click", "./Image/CustomScene/Credit_Button_Click.bmp");

		Load("ResetButton_Normal", "./Image/CustomScene/Reset_Button.bmp");
		Load("ResetButton_OnCursor", "./Image/CustomScene/Reset_Button_OnCursor.bmp");
		Load("ResetButton_Click", "./Image/CustomScene/Reset_Button_Click.bmp");

		Load("GameStartButton_Normal", "./Image/CustomScene/Game_Start_Button.bmp");
		Load("GameStartButton_OnCursor", "./Image/CustomScene/Game_Start_Button_OnCursor.bmp");
		Load("GameStartButton_Click", "./Image/CustomScene/Game_Start_Button_Click.bmp");

		Load("CreditBack_Normal", "./Image/CustomScene/Credit_BackButton.bmp");
		Load("CreditBack_OnCursor", "./Image/CustomScene/Credit_BackButton_OnCursor.bmp");
		Load("CreditBack_Click", "./Image/CustomScene/Credit_BackButton_Click.bmp");

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

			Load("CategoryEnable", "./Image/CustomScene/Category/Category_Enable.bmp");
		}

		//Part
		{
			for (size_t i = 1; i < 5; i++)
			{
				{
					Load(string("PartSkin_") + to_string(i) + "_Equip",
						string("./Image/CustomScene/Part/Button/Part_Skin_") + to_string(i) + "_Equip" + ".bmp");
					if (i >= 3)
					{
						Load(string("PartSkin_") + to_string(i) + "_Lock",
							string("./Image/CustomScene/Part/Button/Part_Skin_") + to_string(i) + "_Lock" + ".bmp");
					}
					Load(string("PartSkin_") + to_string(i) + "_Click",
						string("./Image/CustomScene/Part/Button/Part_Skin_") + to_string(i) + "_Click" + ".bmp");
					Load(string("PartSkin_") + to_string(i) + "_OnCursor",
						string("./Image/CustomScene/Part/Button/Part_Skin_") + to_string(i) + "_OnCursor" + ".bmp");
					Load(string("PartSkin_") + to_string(i) + "_Normal",
						string("./Image/CustomScene/Part/Button/Part_Skin_") + to_string(i) + ".bmp");
				}

				{
					Load(string("PartCloth_") + to_string(i) + "_Equip",
						string("./Image/CustomScene/Part/Button/Part_Cloth_") + to_string(i) + "_Equip" + ".bmp");
					if (i >= 3)
					{
						Load(string("PartCloth_") + to_string(i) + "_Lock",
							string("./Image/CustomScene/Part/Button/Part_Cloth_") + to_string(i) + "_Lock" + ".bmp");
					}
					Load(string("PartCloth_") + to_string(i) + "_Click",
						string("./Image/CustomScene/Part/Button/Part_Cloth_") + to_string(i) + "_Click" + ".bmp");
					Load(string("PartCloth_") + to_string(i) + "_OnCursor",
						string("./Image/CustomScene/Part/Button/Part_Cloth_") + to_string(i) + "_OnCursor" + ".bmp");
					Load(string("PartCloth_") + to_string(i) + "_Normal",
						string("./Image/CustomScene/Part/Button/Part_Cloth_") + to_string(i) + ".bmp");
				}

				{
					Load(string("PartMouth_") + to_string(i) + "_Equip",
						string("./Image/CustomScene/Part/Button/Part_Mouth_") + to_string(i) + "_Equip" + ".bmp");
					if (i >= 3)
					{
						Load(string("PartMouth_") + to_string(i) + "_Lock",
							string("./Image/CustomScene/Part/Button/Part_Mouth_") + to_string(i) + "_Lock" + ".bmp");
					}
					Load(string("PartMouth_") + to_string(i) + "_Click",
						string("./Image/CustomScene/Part/Button/Part_Mouth_") + to_string(i) + "_Click" + ".bmp");
					Load(string("PartMouth_") + to_string(i) + "_OnCursor",
						string("./Image/CustomScene/Part/Button/Part_Mouth_") + to_string(i) + "_OnCursor" + ".bmp");
					Load(string("PartMouth_") + to_string(i) + "_Normal",
						string("./Image/CustomScene/Part/Button/Part_Mouth_") + to_string(i) + ".bmp");
				}

				{
					Load(string("PartEye_") + to_string(i) + "_Equip",
						string("./Image/CustomScene/Part/Button/Part_Eye_") + to_string(i) + "_Equip" + ".bmp");
					if (i >= 3)
					{
						Load(string("PartEye_") + to_string(i) + "_Lock",
							string("./Image/CustomScene/Part/Button/Part_Eye_") + to_string(i) + "_Lock" + ".bmp");
					}
					Load(string("PartEye_") + to_string(i) + "_Click",
						string("./Image/CustomScene/Part/Button/Part_Eye_") + to_string(i) + "_Click" + ".bmp");
					Load(string("PartEye_") + to_string(i) + "_OnCursor",
						string("./Image/CustomScene/Part/Button/Part_Eye_") + to_string(i) + "_OnCursor" + ".bmp");
					Load(string("PartEye_") + to_string(i) + "_Normal",
						string("./Image/CustomScene/Part/Button/Part_Eye_") + to_string(i) + ".bmp");
				}

				{
					Load(string("PartHair_") + to_string(i) + "_Equip",
						string("./Image/CustomScene/Part/Button/Part_Hair_") + to_string(i) + "_Equip" + ".bmp");
					if (i >= 3)
					{
						Load(string("PartHair_") + to_string(i) + "_Lock",
							string("./Image/CustomScene/Part/Button/Part_Hair_") + to_string(i) + "_Lock" + ".bmp");
					}
					Load(string("PartHair_") + to_string(i) + "_Click",
						string("./Image/CustomScene/Part/Button/Part_Hair_") + to_string(i) + "_Click" + ".bmp");
					Load(string("PartHair_") + to_string(i) + "_OnCursor",
						string("./Image/CustomScene/Part/Button/Part_Hair_") + to_string(i) + "_OnCursor" + ".bmp");
					Load(string("PartHair_") + to_string(i) + "_Normal",
						string("./Image/CustomScene/Part/Button/Part_Hair_") + to_string(i) + ".bmp");
				}
			}
		}

		//PartImage
		{
			for (size_t i = 1; i < 5; i++)
			{
				Load(string("SkinImage_") + to_string(i),
					string("./Image/CustomScene/Part/Image/Skin_") + to_string(i) + ".bmp");

				Load(string("EyeImage_") + to_string(i),
					string("./Image/CustomScene/Part/Image/Eye_") + to_string(i) + ".bmp");

				Load(string("MouthImage_") + to_string(i),
					string("./Image/CustomScene/Part/Image/Mouth_") + to_string(i) + ".bmp");

				Load(string("ClothImage_") + to_string(i),
					string("./Image/CustomScene/Part/Image/Cloth_") + to_string(i) + ".bmp");

				Load(string("HairImage_") + to_string(i),
					string("./Image/CustomScene/Part/Image/Hair_") + to_string(i) + ".bmp");
			}
		}
	}

	//PuzzleSceneImage
	{
	Load("Life1", "./Image/PuzzleScene/Life_Display1.bmp");
	Load("Life2", "./Image/PuzzleScene/Life_Display2.bmp");
	Load("Life3", "./Image/PuzzleScene/Life_Display3.bmp");
	Load("Correct", "./Image/PuzzleScene/Correct_Animation_%d.bmp", 7); //0 부터
	Load("Wrong", "./Image/PuzzleScene/Wrong_Animation_%d.bmp", 7); //0 부터
	Load("GotoMainButton_Normal", "./Image/PuzzleScene/Reward_GotoMain_Button.bmp");
	Load("GotoMainButton_OnCursor", "./Image/PuzzleScene/Reward_GotoMain_Button_Mouse_On.bmp");
	Load("GotoMainButton_Click", "./Image/PuzzleScene/Reward_GotoMain_Button_Mouse_Click.bmp");
	Load("Result", "./Image/PuzzleScene/Result_Background.bmp");
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
	else
		SCENE->ChangeScene("Title_BG");
}

void cLoadScene::Render()
{
}

void cLoadScene::Release()
{
}
