#include <iostream>
#include <stdio.h> // important to use getchar()
#include <cstdlib>
#include <ctime>
#include <termios.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/ioctl.h>
#include <stropts.h>

int kbhit(){  /*I took it ready,helps the game for not waiting the user input*/
	static const int STDIN = 0;
	static bool initialized = false;

	if(!initialized){
		termios term;
		tcgetattr(STDIN,&term);
		term.c_lflag &= ~ICANON;
		tcsetattr(STDIN,TCSANOW,&term);
		setbuf(stdin,NULL);
		//initialized = true;
	}

	int bytesWaiting;
	ioctl(STDIN,FIONREAD,&bytesWaiting);
	return bytesWaiting;
}

char getch(){   /*I took it ready*/
	char buf = 0;
	struct termios old = {0};
	fflush(stdout);
	if(tcgetattr(0,&old)<0)
		perror("tcsetattr()");
	old.c_lflag &= ~ICANON;
	old.c_lflag &= ~ECHO;
	old.c_cc[VMIN] = 1;
	old.c_cc[VTIME] = 0;
	if(tcsetattr(0,TCSANOW,&old) < 0)
		perror("tcsetattr ICANON");
	if(read(0,&buf,1)<0)
		perror("read()");
	old.c_lflag |= ICANON;
	old.c_lflag |= ECHO;
	if(tcsetattr(0,TCSADRAIN,&old)<0)
		perror("tcsetattr ~ICANON");

	return buf;
}

int getchar_silent(){  /*I took it ready*/
	int ch;
	struct termios oldt,newt;

	tcgetattr(STDIN_FILENO,&oldt);

	newt = oldt;
	newt.c_lflag &= ~( ICANON | ECHO );

	tcsetattr(STDIN_FILENO,TCSANOW,&newt);

	ch = getchar();
	tcsetattr(STDIN_FILENO,TCSANOW,&oldt);

	return ch;	
}