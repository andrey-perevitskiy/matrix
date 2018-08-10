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

void MatroidRandSym(matroid *mtr)
{
  int i;
  for (i = 0; i < SYMBOLS_MAX; i++)
  {
    SymbolRandSym(&mtr->sym[i]);
  }
}

void MatroidAlign(matroid *mtr, int x, int y)
{
  int i;
  for (i = 0; i < SYMBOLS_MAX; i++)
  {
    mtr->sym[i].pos.x = x;
    mtr->sym[i].pos.y = i + y;
  }
}

void MatroidMove(matroid *mtr, int x, int y)
{
  int i;
  for (i = 0; i < SYMBOLS_MAX; i++)
  {
    mtr->sym[i].pos.x += x;
    mtr->sym[i].pos.y += y;
  }
}

void MatroidClear(matroid *mtr)
{
  int i;
  for (i = 0; i < SYMBOLS_MAX; i++)
  {
    SymbolClear(&mtr->sym[i]);
  }
}

void MatroidCheck(matroid *mtr)
{
  int i;
  for (i = 0; i < SYMBOLS_MAX; i++)
  {
    if (!SymbolCheck(&mtr->sym[i]))
    {
      mtr->sym[i].pos.y = MATRIX_BOARD_TOP;
    }
  }
}

void MatrixInit(matrix *mtx)
{
  mtx->mtr = malloc(sizeof(matroid) * MATROIDS_MAX);
  
  int i;
  for (i = 0; i < MATROIDS_MAX; i++)
  {
    mtx->mtr[i].sym = malloc(sizeof(symbol) * SYMBOLS_MAX);
  }
}

void MatrixDraw(matrix *mtx)
{
  int i;
  for (i = 0; i < MATROIDS_MAX; i++)
  {
    MatroidDraw(&mtx->mtr[i]);
  }
}

void MatrixRand(matrix *mtx)
{
  int i;
  for (i = 0; i < MATROIDS_MAX; i++)
  {
    MatroidRand(&mtx->mtr[i]);
  }
}

void MatrixRandSym(matrix *mtx)
{
  int i;
  for (i = 0; i < MATROIDS_MAX; i++)
  {
    MatroidRandSym(&mtx->mtr[i]);
  }
}

void MatrixGen(matrix *mtx)
{
  int i;
  for (i = 0; i < MATROIDS_MAX; i++)
  {
    MatroidRand(&mtx->mtr[i]);
    MatroidAlign(&mtx->mtr[i], Random(MATRIX_BOARD_LEFT, 
      MATRIX_BOARD_RIGHT), MATRIX_BOARD_TOP - 1);
  }
}

void MatrixMove(matrix *mtx, int y)
{
  int i;
  for (i = 0; i < MATROIDS_MAX; i++)
  {
    MatroidMove(&mtx->mtr[i], 0, y);
  }
}

void MatrixClear(matrix *mtx)
{
  int i;
  for (i = 0; i < MATROIDS_MAX; i++)
  {
    MatroidClear(&mtx->mtr[i]);
  }
}

void MatrixCheck(matrix *mtx)
{
  int i;
  for (i = 0; i < MATROIDS_MAX; i++)
  {
    MatroidCheck(&mtx->mtr[i]);
  }
}

void MatrixFree(matrix *mtx)
{
  int i;
  for (i = 0; i < MATROIDS_MAX; i++)
  {
    free(mtx->mtr[i].sym);
  }
  
  free(mtx->mtr);
}
