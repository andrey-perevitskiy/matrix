#ifndef MATRIX_H

#include "matroid.h"

struct mtx {
    struct mtr * mtr;
};

struct mtx * mtx_init (void);
void mtx_draw (struct mtx * m);
void mtx_rand (struct mtx * m);
void mtx_rand_sym (struct mtx * m);
void mtx_gen (struct mtx * m);
void mtx_move (struct mtx * m, int y);
void mtx_clear (struct mtx * m);
void mtx_check (struct mtx * m);
void mtx_free (struct mtx * m);

#define MATRIX_H
#endif
