#pragma once
#include "GameObject.h"
#include "Food.h"

#define FWPLAYER Snake::GetInstance()
typedef enum _Move {LEFT,RIGHT,UP,DOWN}MOVE;

class Snake :
	public GameObject
{
private:
	typedef struct Postion
	{
		int x, y;
	}Pos;
public:
	bool Update();
	void TailMove();
	static Snake* GetInstance();
public:
	void InitSnake();
	void FoodCheck();
	MOVE move;
	Pos Head;
	list<Pos*>Tail;
	int SleepPoint = 30;
public:
	Snake();
	~Snake();
};

