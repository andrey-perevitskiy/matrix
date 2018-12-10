#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <signal.h>
#include <time.h>

#include <ncurses.h>

#include "ncurapi.h"
#include "matrix.h"

static void TimerFunc(union sigval sig);

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
    .sigev_notify_function = TimerFunc
  };
  
  struct itimerspec itspec =
  {
    .it_interval.tv_nsec = MATRIX_SPEED * 10000000,
    .it_value.tv_nsec = MATRIX_SPEED * 10000000
  };
  /* END */
  
  timer_t mtxtimer;
  
  initscr();
  
  if (has_colors() == false)
  {
    COLOR_SUPPORT = false;
    
    printw("Oops!\n");
    printw("Your terminal does not support colors.\n");
    printw("Nothing wrong.\n");
    printw("Just enjoy one-color animation. :)");
    
    getch();
  }
  else
  {
    COLOR_SUPPORT = true;
    
    start_color();
    
    init_pair(MASK_ROOT, COLOR_WHITE, COLOR_BLACK);
    init_pair(MASK_GOOD, COLOR_GREEN, COLOR_BLACK);
  }
  
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

static void TimerFunc(union sigval sig)
{
  matrix *mtx = sig.sival_ptr;

  MatrixClear(mtx);
  MatrixMove(mtx, 1);
  MatrixCheck(mtx);
  MatrixDraw(mtx);
  MatrixRandSym(mtx);
  
  refresh();
}
