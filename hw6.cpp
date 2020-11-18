#include <iostream>
#include <cstring>
#include "stack.h"
#include <stdio.h> // POSIX headers
#include <termios.h>  // for tcxxxattr, ECHO, etc ..
#include <unistd.h>    // for STDIN_FILENO

using namespace std ;

int getch (void)
{
    int ch;
    struct termios oldt, newt;
 
    tcgetattr(STDIN_FILENO, &oldt);
    memcpy(&newt, &oldt, sizeof(newt));
    newt.c_lflag &= ~( ECHO | ICANON | ECHOE | ECHOK |
                       ECHONL | ECHOPRT | ECHOKE | ICRNL);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
 
    return ch;
}

int main()
{
	// string infix = "0123456789()+-*/";
	// int count = 0 ;
	// for(int i = 0 ; i < infix.length() ; i++)
	// 	printf("%d %c\n", infix[i] , infix[i]);
	int count = 0 ;
	while(1)
	{
		cout << count << endl ;
		count ++ ;
		int a = getch();
		if(a == 27)
			break ;
	}
	return 0 ;
}