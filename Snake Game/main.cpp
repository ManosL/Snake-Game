#include <iostream>
#include <stdio.h> // important to use getchar()
#include <cstdlib>
#include <ctime>
#include <unistd.h>

#include "ready_functions.h"
#include "Food.h"
#include "snake.h"
#include "SnakeBody.h"

using namespace std;

class GameManager{
private: 
	Food* food;
	Snake* snake;
	char up,down,left,right;
	char quit;
	int score,width,length;

public:
	GameManager(int w,int l){
		up = 'w'; down = 's' ; 
		left = 'a'; right = 'd';
		quit = 'q';
		width = w;
		length = l;
		snake = new Snake(width,length);
		food = new Food(snake,width,length);		
		score = 0;
	}

	void Run(){
		int c;

		cout<<"Welcome to my snake game\nPress p to start\n";
		Draw();
		while( getchar_silent() != 'p'){}
		
		while(0!=1){

			if(kbhit()){
				switch(c=getch()){
					case 'w':
						snake->Snake_ChangeDirection((sDir) UP);
						snake->Snake_Move();
						break;
					case 'a':
						snake->Snake_ChangeDirection((sDir) LEFT);
						snake->Snake_Move();
						break;
					case 's':
						snake->Snake_ChangeDirection((sDir) DOWN);
						snake->Snake_Move();
						break;
					case 'd': 
						snake->Snake_ChangeDirection((sDir) RIGHT);
						snake->Snake_Move();
						break;
					case 'q':
						cout<<"Thanks for playing"<<endl;
						cout<<"Score = "<<score<<endl;
						return;
					default:
						snake->Snake_Move();
						break;	
				}
			}
			else{
				snake->Snake_Move();
			}

			if(snake->Snake_Crashed(width,length)){
				cout<<"Game Over"<<endl<<"Thanks for playing"<<endl;
				cout<<"Score = "<<score<<endl;
				return;
			}

			if(snake->Snake_EatFood(food)){
				score += 10;
				snake->Snake_Extend();

				if(snake->Snake_getSize() == width*length){
					cout<<"You are amazing! You finished the game"<<endl;
					cout<<"Score = "<<score;
					return;
				}

				delete food;
				food = new Food(snake,width,length); 
			}			

			printf("\033[2J\033[1;1H"); //clear();
			Draw();

			usleep(130*1000); /*I pass the sleeping time to microseconds*/
		}	
	}

	void Draw(){

		for(int i=0;i<width+2;i++){
			cout<<"#";
		}

		cout<<endl;

		for(int i=0;i<length;i++){
			cout<<"#";
			for(int j=0;j<width;j++){
				if(food->Food_getX() == j && food->Food_getY() == i){
					cout<<"F";
				}
				else if(snake->Snake_Search(j,i)){
					cout<<"ꔷ";
				}
				else
					cout<<" ";
			}
			cout<<"#"<<endl;
		}

		for(int i = 0;i<width+2;i++){
			cout<<"#";
		}
		cout<<endl;

		return;
	}

	~GameManager(){
		delete food;
		delete snake;
	}	
};

int main(){
	GameManager* snake_game;

	srand(time(NULL));

	snake_game = new GameManager(20,20);
	snake_game->Run();

	delete snake_game;

	return 0;
}