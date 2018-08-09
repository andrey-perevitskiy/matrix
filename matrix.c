#include "matrix.h"

void MatroidDraw(matroid *mtr)
{
  int i;
  for (i = 0; i < SYMBOLS_MAX; i++)
  {
    SymbolDraw(&mtr->sym[i]);
  }
}

void MatroidRand(matroid *mtr)
{
  int i;
  for (i = 0; i < SYMBOLS_MAX; i++)
  {
    SymbolRand(&mtr->sym[i]);
  }
}

void MatroidGen(matroid *mtr, int x, int y)
{
  int i;
  for (i = 0; i < SYMBOLS_MAX; i++)
  {
    SymbolRand(&mtr->sym[i]);
    
    mtr->sym[i].pos.x = x;
    mtr->sym[i].pos.y = i + y;
  }
}
