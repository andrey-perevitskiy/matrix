#include <stdlib.h>
#include "matrix.h"

struct mtx *
mtx_init (void)
{
    int i;
    struct mtx * m = malloc(sizeof(struct mtx));

    m->mtr = malloc(sizeof(struct mtr) * MATROID_MAX);
    for (i = 0; i < MATROID_MAX; i++)
        m->mtr[i].sym = malloc(sizeof(struct sym) * SYM_MAX);

    return m;
}

void
mtx_draw (struct mtx * m)
{
    int i;

    for (i = 0; i < MATROID_MAX; i++)
        mtr_draw(&m->mtr[i]);
}

void
mtx_rand (struct mtx * m)
{
    int i;

    for (i = 0; i < MATROID_MAX; i++)
        mtr_rand(&m->mtr[i]);
}

void
mtx_rand_sym (struct mtx * m)
{
    int i;

    for (i = 0; i < MATROID_MAX; i++)
        mtr_rand_sym(&m->mtr[i]);
}

void
mtx_gen (struct mtx * m)
{
    int i;

    for (i = 0; i < MATROID_MAX; i++) {
        mtr_rand(&m->mtr[i]);
        mtr_align(&m->mtr[i], i, random(-1, BOARD_BOTTOM - SYM_MAX));
    }
}

void
mtx_move (struct mtx * m, int y)
{
    int i;

    for (i = 0; i < MATROID_MAX; i++)
        mtr_move(&m->mtr[i], y);
}

void
mtx_clear (struct mtx * m)
{
    int i;

    for (i = 0; i < MATROID_MAX; i++)
        mtr_clear(&m->mtr[i]);
}

void
mtx_check (struct mtx * m)
{
    int i;

    for (i = 0; i < MATROID_MAX; i++)
        mtr_check(&m->mtr[i]);
}

void
mtx_free (struct mtx * m)
{
    int i;

    for (i = 0; i < MATROID_MAX; i++)
        free(m->mtr[i].sym);
    free(m->mtr);
}
