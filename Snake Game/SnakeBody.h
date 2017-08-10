#ifndef __SNAKEBODY__
#define __SNAKEBODY__

enum sDir{UP = 0, DOWN = 1,LEFT = 2,RIGHT = 3};

class Snake_Body{
private:
	sDir direction;
	int x,y;
	Snake_Body* next;

public:
	Snake_Body(){};

	Snake_Body(int,int);     /*constructor if I create only the head*/

	Snake_Body(Snake_Body*); /*constructor if snake has length >= 1 boxes*/

	void SnakeBody_Move();  /*Moves each snake's box one time*/

	void SnakeBody_ChangeDirection(sDir);

	Snake_Body* SnakeBody_getNext(){return next;};
	sDir SnakeBody_getDirection(){return (sDir) direction;};
	int SnakeBody_getX(){return x;};
	int SnakeBody_getY(){return y;}; 	

	~Snake_Body(){}
};

#endif