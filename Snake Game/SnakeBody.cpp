#include <iostream>
#include "SnakeBody.h"

using namespace std;

Snake_Body::Snake_Body(int width,int length){ /*constructor if I create only the head*/
	next = NULL;
	direction = UP;
	x = width / 2;
	y = length / 2;	
}

Snake_Body::Snake_Body(Snake_Body* tail){  /*constructor if snake has length >= 1 boxes*/
	next = tail;
	direction = tail->direction;

	switch(tail->direction){
		case UP:
			x = (tail->x);
			y = (tail->y) + 1;
			direction = UP;
			break;
		case DOWN:
			x = (tail->x);
			y = (tail->y) - 1;
			direction = DOWN;
			break;
		case LEFT:
			x = (tail->x) + 1;
			y = (tail->y);
			direction = LEFT;
			break;
		case RIGHT:
			x = (tail->x) - 1;
			y = (tail->y);
			direction = RIGHT;
			break;

		default:
			cout<<"Something wrong here"<<endl;
			break;	 
	}
}

void Snake_Body::SnakeBody_Move(){  /*Moves each snake's box one time*/
	if(next == NULL){
		switch(direction){
			case UP:
				y--;
				break;
			case DOWN:
				y++;
				break;
			case LEFT:
				x--;
				break;
			case RIGHT:
				x++;
				break;
			default:
				cout<<"something wrong"<<endl;
				break;			
		}
	}
	else{
		switch(direction){
			case UP:
				if((y - 2) == next->y){
					y--;
					direction = UP;
				}
				else if((y-1) == next->y && (x-1) == next->x){
					y--;
					direction = LEFT;
				}
				else if((y-1) == next->y && (x+1) == next->x){
					y--;
					direction = RIGHT;
				}
				else{
					cout<<"Something wrong 81"<<direction<<endl;
				}
				break;
			case DOWN:
				if((y + 2) == next->y){
					y++;
					direction = DOWN;
				}
				else if((y+1) == next->y && (x-1) == next->x){
					y++;
					direction = LEFT;
				}
				else if((y+1) == next->y && (x+1) == next->x){
					y++;
					direction = RIGHT;
				}
				else{
					cout<<"Something wrong 98"<<direction<<endl;
				}
				break;				
			case LEFT:
				if((x - 2) == next->x){
					x--;
					direction = LEFT;
				}
				else if((x-1) == next->x && (y-1) == next->y){
					x--;
					direction = UP;
				}
				else if((x-1) == next->x && (y+1) == next->y){
					x--;
					direction = DOWN;
				}
				else{
					cout<<"Something wrong 115"<<direction<<endl;
				}
				break;
			case RIGHT:
				if((x + 2) == next->x){
					x++;
					direction = RIGHT;
				}
				else if((x+1) == next->x && (y-1) == next->y){
					x++;
					direction = UP;
				}
				else if((x+1) == next->x && (y+1) == next->y){
					x++;
					direction = DOWN;
				}
				else{
					cout<<"Something wrong 132"<<direction<<endl;
				}
				break;						
		}
	}
}

void Snake_Body::SnakeBody_ChangeDirection(sDir dir){
	if(dir == UP && direction != DOWN)
		direction = UP;
	else
		if(dir == DOWN && direction != UP)
			direction = DOWN;
	else
		if(dir == RIGHT && direction != LEFT)
			direction = RIGHT;
	else
		if(dir == LEFT && direction !=RIGHT)
			direction = LEFT;	
}
