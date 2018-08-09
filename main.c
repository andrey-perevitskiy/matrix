#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <ncurses.h>

#include "ncurapi.h"
#include "matrix.h"

int main(void)
{
  srand(time(NULL));
  
  initscr();
  
  /* BEGIN generate random matroid */
  matroid mtr = 
  {
    .sym = malloc(sizeof(symbol) * SYMBOLS_MAX)
  };
  
  MatroidGen(&mtr, 5, 15);
  /* END */
  
  MatroidDraw(&mtr);
  
  getch();
  
  endwin();
  
  return 0;
}
