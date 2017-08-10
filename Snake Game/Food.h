#ifndef __FOOD__
#define __FOOD__

class Snake;

class Food{
private:
	int x,y;

public:
	Food(Snake*,int,int);

	int Food_getX(){return x;};
	int Food_getY(){return y;};

	~Food(){};	
};

#endif