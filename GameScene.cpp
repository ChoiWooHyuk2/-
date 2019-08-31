#include "pch.h"
#include "GameScene.h"


void GameScene::Render()
{
	doubleBuffer.ClearBuffer();
	//¸Ê»ý¼º
	PrintMap();
	//¹ì ¸Ó¸®
	doubleBuffer.WriteBuffer(FWPLAYER->Head.x,FWPLAYER->Head.y,"¡Ü");
	//¸ÔÀÌ
	doubleBuffer.WriteBuffer(FooD->FoodPositon.x, FooD->FoodPositon.y, "¢¾");
	//¹ì ²¿¸®
	for (auto a : FWPLAYER->Tail)
	{
		doubleBuffer.WriteBuffer(a->x, a->y, "¡Ý");
	}
	doubleBuffer.FlippingBuffer();
}

void GameScene::PrintMap()
{
	if (First) {
		for (int i = 0; i <= 59; i++) {
			for (int j = 0; j <= 28; j++)
			{
				if (i == 59 || j == 28 || i == 0 || j == 0)
				{
					doubleBuffer.WriteBuffer(i * 2, j, "¡á");
				}
			}
		}
	}

	if (Second) {
		for (int i = 0; i <= 59; i++) {
			for (int j = 0; j <= 28; j++)
			{
				if (i == 59 || j == 28 || i == 0 || j == 0)
				{
					doubleBuffer.WriteBuffer(i * 2, j, "¡á");
				}

				if (i == 7 && j == 8)
					doubleBuffer.WriteBuffer(i * 2, j, "Àç¿íÂ¯»ç¶ûÇØ..ÀÌ°Ç µÎ¹øÂ° ¸ÊÀÌ¾ß");
			}
		}
	}

	if (three) {
		for (int i = 0; i <= 59; i++) {
			for (int j = 0; j <= 28; j++)
			{
				if (i == 59 || j == 28 || i == 0 || j == 0)
				{
					doubleBuffer.WriteBuffer(i * 2, j, "¡á");
				}

				if (i == 7 && j ==8)
					doubleBuffer.WriteBuffer(i * 2, j, "Àç¿íÂ¯ÁÁ¾ÆÇØ...ÀÌ°Ç ¼¼¹øÂ° ¸ÊÀÌ¾ß");
			}
		}
	}
}



GameScene::GameScene()
{
	doubleBuffer.CreateBuffer(1280,720);
}


GameScene::~GameScene()
{
	doubleBuffer.DestoryBuffer();
}

void GameScene::gotoxy(int x, int y)
{
		COORD pos = { x,y };

		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);

}

GameScene * GameScene::GetInstance()
{
	static GameScene i;
	return &i;
}
