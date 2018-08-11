#ifndef __MATRIX_H__
#define __MATRIX_H__

#include "ncurapi.h"

typedef struct Matroid
{
  symbol *sym;
} matroid;

typedef struct Matrix
{
  matroid *mtr;
} matrix;

void MatroidDraw(matroid *mtr);
void MatroidRand(matroid *mtr);
void MatroidRandSym(matroid *mtr);
void MatroidAlign(matroid *mtr, int x, int y);
void MatroidMove(matroid *mtr, int x, int y);
void MatroidClear(matroid *mtr);
void MatroidCheck(matroid *mtr);

void MatrixInit(matrix *mtx);
void MatrixDraw(matrix *mtx);
void MatrixRand(matrix *mtx);
void MatrixRandSym(matrix *mtx);
void MatrixGen(matrix *mtx);
void MatrixMove(matrix *mtx, int y);
void MatrixClear(matrix *mtx);
void MatrixCheck(matrix *mtx);
void MatrixFree(matrix *mtx);

#endif
