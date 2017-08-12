#include <iostream>

#include "snake.h"
#include "SnakeBody.h"
#include "Food.h"

using namespace std;

Snake::Snake(int width,int height){
	head = new Snake_Body(width,height);
	tail = head;
	size = 1;
}

void Snake::Snake_Move(){  /*Moves the whole snake one time*/
	Snake_Body* current = tail; 
	Snake_Body** nodes = new Snake_Body*[size];

	for(int i=0;i<size && current != NULL;i++){
		nodes[i] = current;
		current = current->SnakeBody_getNext();
	}

	for(int i = size-1;i >= 0;i--){
		nodes[i]->SnakeBody_Move();
	}

	delete[] nodes;
}

void Snake::Snake_ChangeDirection(sDir dir){
	head->SnakeBody_ChangeDirection((sDir) dir);
}

void Snake::Snake_Extend(){
	Snake_Body* new_node;

	new_node = new Snake_Body(tail);
	tail = new_node;
	size++;
}

int Snake::Snake_Crashed(int width,int height){
	Snake_Body* current = tail;

	while(current != head){
		if((head->SnakeBody_getX() == current->SnakeBody_getX()) && (head->SnakeBody_getY() == current->SnakeBody_getY()))
			return 1;
		else
			current = current->SnakeBody_getNext();
	}

	if((head->SnakeBody_getX() == width) || (head->SnakeBody_getX() == -1))
		return 1;
	else if((head->SnakeBody_getY() == height) || (head->SnakeBody_getY() == -1))
		return 1;
	else
		return 0;
}

int Snake::Snake_EatFood(Food* food){
	return ((head->SnakeBody_getX() == food->Food_getX()) && (head->SnakeBody_getY() == food->Food_getY())); 
}

int Snake::Snake_Search(int x,int y){
	Snake_Body* current = tail;

	while(current != NULL){
		if(current->SnakeBody_getX() == x && current->SnakeBody_getY() == y)
			return 1;
		else
			current = current->SnakeBody_getNext();
	}

	return 0;
}

Snake::~Snake(){
	Snake_Body *temp1,*temp2;
	temp1 = tail;

	while(temp1 != NULL){
		temp2 = temp1;
		temp1 = temp1->SnakeBody_getNext();
		delete temp2;
	}
}