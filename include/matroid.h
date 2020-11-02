#ifndef MATROID_H

#include <stdlib.h>
#include <ncurses.h>

#define random(min, max) (min + rand() % ((max + 1) - min))

#define BOARD_LEFT 0
#define BOARD_RIGHT (WIN_SIZE_X - 2)
#define BOARD_TOP 0
#define BOARD_BOTTOM (WIN_SIZE_Y - 1)
#define MATROID_MAX 118
#define MATROID_HEIGHT 5
#define SYM_MAX 5
#define WIN_SIZE_X (getmaxx(stdscr))
#define WIN_SIZE_Y (getmaxy(stdscr))

struct sym {
    int x;
    int y;
    char c;
};

struct mtr {
    struct sym * sym;
};

void mtr_draw (struct mtr * mtr);
void mtr_rand (struct mtr * mtr);
void mtr_rand_sym (struct mtr * mtr);
void mtr_align (struct mtr * mtr, int x, int y);
void mtr_move (struct mtr * mtr, int y);
void mtr_clear (struct mtr * mtr);
void mtr_check (struct mtr * mtr);

#define MATROID_H
#endif
