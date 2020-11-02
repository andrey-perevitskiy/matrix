#include <time.h>
#include <signal.h>
#include <ncurses.h>
#include "matrix.h"

static void timer_cb (union sigval sig);

int
main (void)
{
    struct mtx * m;
    struct sigevent sigev = {
        .sigev_notify = SIGEV_THREAD,
        .sigev_notify_function = timer_cb
    };
    struct itimerspec itspec = {
        .it_interval.tv_nsec = 50000000,
        .it_value.tv_nsec = 50000000
    };
    timer_t timer;

    /* Curse the program. */
    initscr();
    if (has_colors()) {
        start_color();
        init_pair(1, COLOR_GREEN, COLOR_BLACK);
        init_pair(2, COLOR_WHITE, COLOR_BLACK);
    }
    else {
        printw("Your terminal does not support the colors.\n");
        getch();
    }
    curs_set(0);
    srand(time(NULL));

    sigev.sigev_value.sival_ptr = m = mtx_init();
    mtx_gen(m);
    timer_create(CLOCK_REALTIME, &sigev, &timer);
    timer_settime(timer, 0, &itspec, NULL);

    getch();
    timer_delete(timer);
    mtx_free(m);
    curs_set(2);
    endwin();

    return 0;
}

static void
timer_cb (union sigval sig)
{
    struct mtx * m = sig.sival_ptr;

    mtx_clear(m);
    mtx_move(m, 1);
    mtx_check(m);
    mtx_draw(m);
    mtx_rand_sym(m);
    refresh();
}
