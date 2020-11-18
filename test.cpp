/*
gcc -Wall -std=gnu99 -o esc_ex esc_ex.c -lpdcurses
*/
#include <curses.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define CTRLC '\003'  // Code for CTRL-C might be different on other systems

void do_endwin(void) {endwin();}

int main(void)
{
	// Start curses mode
	if (initscr() == NULL) {
		fprintf(stderr, "Could not initialize screen\n");
		exit(EXIT_FAILURE);
	}
	atexit(do_endwin);
	keypad(stdscr, TRUE);		// raw mode ON
	noecho();					// echo mode OFF
	scrollok(stdscr, TRUE);		// scrolling mode ON
	
	// Read each character into key and print its description
	int key;
	printw("Press some keys on the keyboard to see their keycodes. ESC to exit.\n");
	refresh();
	while ((key = getch()) != '\e') {
		switch(key) {
		case '\n':
			printw("Enter");
			break;
		case CTRLC:
			printw("Ctrl-C");
			break;
		case KEY_F(1): 
			printw("F1");
			break;
		case KEY_F(2): 
			printw("F2");
			break;
		case KEY_LEFT:
			printw("Left");
			break;
		case KEY_RIGHT:
			printw("Right");
			break;
		case KEY_UP:
			printw("Up");
			break;
		case KEY_DOWN:
			printw("Down");
			break;
		default:
			if (isprint(key))
				printw("key with printable character '%c'", key);
			else
				printw("key with nonprintable code %d", key);
			break;
		}
		printw("\n");	
		refresh();
	}
	printw("You pressed ESC. Ending...\n\n");
	refresh();
		
	// Print message and wait for user to press a key
	printw("Press any key to end the program...");
	refresh();
	getch();
	exit(EXIT_SUCCESS);	
}