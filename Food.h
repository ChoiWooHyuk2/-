#pragma once
#include "Snake.h"
#define FooD Food::GetInstance()
class Food
{
public:
	Food();
	~Food();
public:
	void RendomSpawn();
public:
	typedef struct Position {
		int x = 70, y = 10;
	}Pos;
	int Score =  0;
	Pos FoodPositon;
	static Food* GetInstance();
};

