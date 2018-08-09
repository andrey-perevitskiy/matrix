#ifndef __NCURAPI_H__
#define __NCURAPI_H__

#include <stdio.h>

#include <ncurses.h>

#include "defs.h"

typedef struct Coord
{
  int x;
  int y;
} coord;

typedef struct Symbol
{
  char c;
  coord pos;
} symbol;

void SymbolDraw(symbol *sym);
void SymbolRand(symbol *sym);

#endif
