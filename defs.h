#ifndef __DEFS_H__
#define __DEFS_H__

#include <stdlib.h>

#define WINDOW_SIZE_X getmaxx(stdscr)
#define WINDOW_SIZE_Y getmaxy(stdscr)

#define Random(min, max) (min + rand() % ((max + 1) - min))

#define SYMBOLS_MAX 5
#define MATROIDS_MAX 4

#define MATRIX_BOARD_LEFT 0
#define MATRIX_BOARD_RIGHT (WINDOW_SIZE_X - 2)
#define MATRIX_BOARD_TOP 0
#define MATRIX_BOARD_BOTTOM WINDOW_SIZE_Y

#endif
