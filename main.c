#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <signal.h>
#include <time.h>

#include <ncurses.h>

#include "ncurapi.h"
#include "matrix.h"

void Timer(union sigval sig);

int main(void)
{
  srand(time(NULL));
  
  matrix mtx;
  
  MatrixInit(&mtx);
  
  /* BEGIN setting timer */
  struct sigevent sigev =
  {
    .sigev_notify = SIGEV_THREAD,
    .sigev_value.sival_ptr = &mtx,
    .sigev_notify_function = Timer
  };
  
  struct itimerspec itspec =
  {
    .it_interval.tv_nsec = 50000000,
    .it_value.tv_nsec = 50000000
  };
  /* END */
  
  timer_t mtxtimer;
  
  initscr();
  
  HideCursor(true);
  
  MatrixGen(&mtx);
  
  timer_create(CLOCK_REALTIME, &sigev, &mtxtimer);
  timer_settime(mtxtimer, 0, &itspec, NULL);
  
  getch();
  
  HideCursor(false);
  
  endwin();
  
  timer_delete(mtxtimer);
  
  MatrixFree(&mtx);
  
  return 0;
}

void Timer(union sigval sig)
{
  matrix *mtx = sig.sival_ptr;

  MatrixClear(mtx);
  MatrixMove(mtx, 1);
  MatrixCheck(mtx);
  MatrixDraw(mtx);
  MatrixRandSym(mtx);
}
