#ifndef __SNAKE__
#define __SNAKE__

#include "SnakeBody.h"
#include "Food.h"

class Food;

class Snake{
	Snake_Body* head;
	Snake_Body* tail; /*tail = the last box but first node of snake's body*/
	int size;  /*I need this because when size = width x length the game terminates*/

public:
	Snake(int,int);
	void Snake_Move();  /*Moves the whole snake one time*/
	void Snake_ChangeDirection(sDir);
	void Snake_Extend();
	int Snake_Crashed(int,int);
	int Snake_EatFood(Food*);
	int Snake_Search(int,int);

	inline int Snake_getSize(){return size;}
	sDir Snake_getDir(){return head->SnakeBody_getDirection();}

	~Snake();
};

#endif