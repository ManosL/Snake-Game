Snake_game: main.o Food.o Snake.o SnakeBody.o ready_functions.o
	g++ main.o Food.o Snake.o SnakeBody.o ready_functions.o -o Snake_game

main.o: main.cpp
	g++ -c main.cpp

Food.o: Food.cpp
	g++ -c Food.cpp

Snake.o: Snake.cpp
	g++ -c Snake.cpp

SnakeBody.o: SnakeBody.cpp
	g++ -c SnakeBody.cpp

ready_functions.o: ready_functions.cpp
	g++ -c ready_functions.cpp

.PHONY: clean

clean:
	rm -rf 	Snake_game main.o Food.o Snake.o SnakeBody.o ready_functions.o		