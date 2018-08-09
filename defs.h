#ifndef __DEFS_H__
#define __DEFS_H__

#include <stdlib.h>

#define WINDOW_SIZE_X getmaxx(stdscr)
#define WINDOW_SIZE_Y getmaxy(stdscr)

#define Random(min, max) (min + rand() % ((max + 1) - min))

#define SYMBOLS_MAX 5
#define MATROIDS_MAX 10

#endif
