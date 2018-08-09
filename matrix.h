#ifndef __MATRIX_H__
#define __MATRIX_H__

#include "ncurapi.h"

typedef struct Matroid
{
  symbol *sym;
} matroid;

void MatroidDraw(matroid *mtr);
void MatroidRand(matroid *mtr);
void MatroidGen(matroid *mtr, int x, int y);

#endif
