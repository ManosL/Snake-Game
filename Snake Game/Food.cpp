#include <iostream>
#include <cstdlib>
#include "snake.h"
#include "Food.h"

using namespace std;

Food::Food(Snake* snake,int width,int length){
	x = rand() % width;
	y = rand() % length;

	while(snake->Snake_Search(x,y) == 1){
		x = rand() % width;
		y = rand() % length;
	}	
}