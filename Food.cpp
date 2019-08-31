#include "pch.h"
#include "Food.h"


Food::Food()
{
}


Food::~Food()
{
}

void Food::RendomSpawn()
{
		
		srand((unsigned int)time(NULL));
		int x = (rand() % 46) + 6;
		int y = (rand() % 20) + 4;
		FoodPositon.x = x * 2;
		FoodPositon.y = y;
}

Food * Food::GetInstance()
{
	static Food i;
	return &i;
}
