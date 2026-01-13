#include<ncurses.h>

int main(){
  initscr(); // Initialize curses mode
  raw(); // Disable line buffering
  keypad(stdscr, TRUE); // Access to F1, F2, ..., array keys, etc.
  noecho(); // Don't echo when doing getch

  printw("Type any character to see it in bold\n");
  int ch = getch();

  if(ch == KEY_F(1))
    printw("F1 key pressed\n");
  else {
    printw("The key pressed is ");
    attron(A_BOLD);
    printw("%c\n", ch);
    attroff(A_BOLD);
  }

  refresh(); // Put everything to the stdscr buffer for actually displaying
  getch(); // Wait for user input
  endwin(); // Free resources & end curses mode
  
  return 0;
}
