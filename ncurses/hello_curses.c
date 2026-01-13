#include<ncurses.h>

int main(){
  /*
    Initialize the screen
    This allocates the required memory for the relevant data structures
   */
  initscr();

  /*
    printw is similar to printf except it prints to stdscr
    It starts printing at the postion (y, x)
    Since coordinates have not been set, it is (0, 0) for now
   */
  printw("Hello, world");

  /*
    This actually writes to the buffer corresponding to the stdscr
    Refresh also checks the screen and only updates the portion that has changed
   */
  refresh();

  /*
    The flow is interrupted until a character is input
   */
  getch();

  /*
    This is required to free the resources taken up by ncurses
    If this is not used, the terminal might have undefined behavior after the program quits
   */
  endwin();
  
  return 0;
}
