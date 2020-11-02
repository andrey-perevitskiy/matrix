#include "matroid.h"

void
mtr_draw (struct mtr * mtr)
{
    int i;

    for (i = 0; i < SYM_MAX; i++) {
        attron(COLOR_PAIR(i < SYM_MAX - 1 ? 1 : 2));
        mvaddch(mtr->sym[i].y, mtr->sym[i].x, mtr->sym[i].c);
    }
}

void
mtr_rand (struct mtr * mtr)
{
    int i;

    for (i = 0; i < SYM_MAX; i++) {
        mtr->sym[i].x = random(0, WIN_SIZE_X);
        mtr->sym[i].y = random(0, WIN_SIZE_Y);
        mtr->sym[i].c = random('a', 'z');
    }
}

void
mtr_rand_sym (struct mtr * mtr)
{
    int i;

    for (i = 0; i < SYM_MAX; i++)
        mtr->sym[i].c = random('a', 'z');
}

void
mtr_align (struct mtr * mtr, int x, int y)
{
    int i;

    for (i = 0; i < SYM_MAX; i++) {
        mtr->sym[i].x = x;
        mtr->sym[i].y = i + y;
    }
}

void
mtr_move (struct mtr * mtr, int y)
{
    int i;

    for (i = 0; i < SYM_MAX; i++)
        mtr->sym[i].y += y;
}

void
mtr_clear (struct mtr * mtr)
{
    int i;

    for (i = 0; i < SYM_MAX; i++)
        mvaddch(mtr->sym[i].y, mtr->sym[i].x, ' ');
}

void
mtr_check (struct mtr * mtr)
{
    int i;

    for (i = 0; i < SYM_MAX; i++)
        if (mtr->sym[i].y == BOARD_BOTTOM)
            mtr->sym[i].y = BOARD_TOP;
}
