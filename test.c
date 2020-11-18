#include <curses.h>
int main(void)
{
  WINDOW *w = initscr();
  // cbreak();
  // nodelay(w,false);
  int c = getch();
  endwin();
  printw("%dn",c);
  return 0;
}