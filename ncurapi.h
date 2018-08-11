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
  int mask;
} symbol;

bool COLOR_SUPPORT;

void HideCursor(bool state);

void SetSym(char c, int x, int y);
void SetMsg(char *msg, int x, int y);

void SymbolDraw(symbol *sym);
void SymbolRand(symbol *sym);
void SymbolRandSym(symbol *sym);
void SymbolClear(symbol *sym);
bool SymbolCheck(symbol *sym);

#endif
