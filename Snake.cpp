#include "pch.h"
#include "Snake.h"



Snake::Snake()
{
	//snake 초기화
	Head.x = 20;
	Head.y = 10;
	move = LEFT;
	//Test

	Pos* MainTail = new Pos;
	MainTail->x = 22;
	MainTail->y = 10;
	Tail.push_back(MainTail);

	
}


Snake::~Snake()
{
}

bool Snake::Update()
{
	FoodCheck();
	//캐릭터이동
		switch (move)
		{
		case LEFT: 
			if (Head.x > 2){
				TailMove();
			Head.x -= 2;
		}
			break;
		case RIGHT: 
			if (Head.x < 116) {
				TailMove();
				Head.x += 2;			
			}
			break;
		case UP: 
			if (Head.y >= 2) {
				TailMove();
				Head.y -= 1;
			}//118 28
			break;
		case DOWN: 
			if (Head.y  <= 26) {
				TailMove();
				Head.y += 1;
			}
			break;
		}

		for (auto a : Tail)
		{
			if (a->x == Head.x && a->y == Head.y || Head.y == 27|| Head.x ==2 ||Head.x == 116 || Head.y == 1)
				return false;
		}
		return true;
}


void Snake::TailMove()
{
	
	Pos SpendData;
	Pos SaveData;

	SaveData.x = Head.x;
	SaveData.y = Head.y;

	for (auto a : Tail)
	{
		SpendData.x = a->x;
		SpendData.y = a->y;

		a->x = SaveData.x;
		a->y = SaveData.y;


		swap(SpendData, SaveData);
	}
}


Snake * Snake::GetInstance()
{
	static Snake i;
	return &i;
}

void Snake::InitSnake()
{
	Tail.clear();

	//snake 초기화
	Head.x = 20;
	Head.y = 10;
	move = LEFT;

	Pos* InitTail = new Pos;
	InitTail->x = 22;
	InitTail->y = 10;
	Tail.push_back(InitTail);
}

void Snake::FoodCheck()
{
	
	if (Head.x == FooD->FoodPositon.x && Head.y == FooD->FoodPositon.y)
	{
		SleepPoint += 1;

		FooD->RendomSpawn();
		Pos* NewTail = new Pos;
		
		if (move == LEFT)
		{
			NewTail->x = Tail.back()->x + 2;
			NewTail->y = Tail.back()->y;
			Tail.push_back(NewTail);
		}
		if (move == RIGHT)
		{
			NewTail->x = Tail.back()->x - 2;
			NewTail->y = Tail.back()->y;
			Tail.push_back(NewTail);
		}
		if (move == UP)
		{
			NewTail->x = Tail.back()->x;
			NewTail->y = Tail.back()->y + 1;
			Tail.push_back(NewTail);
		}
		if (move == DOWN)
		{
			NewTail->x = Tail.back()->x;
			NewTail->y = Tail.back()->y - 1;
			Tail.push_back(NewTail);
		}

	}
}



