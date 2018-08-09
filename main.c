#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>

#include <ncurses.h>

#include "ncurapi.h"
#include "matrix.h"

void MatroidMoveTimer(union sigval sig);

int main(void)
{
  srand(time(NULL));
  
  matroid mtr = 
  {
    .sym = malloc(sizeof(symbol) * SYMBOLS_MAX)
  };
  
  /* BEGIN setting timer */
  union sigval sig =
  {
    .sival_ptr = &mtr
  };
  
  struct sigevent sigev =
  {
    .sigev_notify = SIGEV_THREAD,
    .sigev_value = sig,
    .sigev_notify_function = MatroidMoveTimer
  };
  
  struct itimerspec itspec =
  {
    .it_interval.tv_sec = 2,
    .it_value.tv_sec = 2
  };
  /* END */
  
  timer_t drawtimer;
  
  initscr();
  
  timer_create(CLOCK_REALTIME, &sigev, &drawtimer);
  timer_settime(drawtimer, 0, &itspec, NULL);
  
  MatroidGen(&mtr, 5, 10);
  MatroidDraw(&mtr);
  
  getch();
  
  endwin();
  
  timer_delete(drawtimer);
  
  return 0;
}

void MatroidMoveTimer(union sigval sig)
{
  matroid *mtr = sig.sival_ptr;
  
  MatroidMove(mtr, ++mtr->sym[0].pos.x, mtr->sym[0].pos.y);
}
