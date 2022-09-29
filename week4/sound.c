/*
https://stackoverflow.com/questions/37292474/how-to-do-nonblocking-input-from-stdin-in-c

This blocks

#include <ncurses.h>

int main()
{
    initscr();
    printw( "Press a key:\n" );
    int c = getch();
    endwin();
}

yuanli$ gcc sound.c -o c -lcurses
*/

#include <ncurses.h>

int main()
{
    initscr();
    printw( "Press e to exit.\n" );
    while (1) {
      printf("\a");
      nodelay( stdscr, TRUE );
      int c = getch();
      if (c == 'e' || c == 'E')
      	break;
    }
    endwin();

    return 0;
}