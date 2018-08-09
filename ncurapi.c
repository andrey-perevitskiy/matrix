#include "ncurapi.h"

void HideCursor(bool state)
{
  if (state)
  {
    curs_set(0);
  }
  else
  {
    curs_set(2);
  }
}

void SetSym(char c, int x, int y)
{
  move(y, x);
  printw("%c", c);
  refresh();
}

void SymbolDraw(symbol *sym)
{
  SetSym(sym->c, sym->pos.x, sym->pos.y);
}

void SymbolRand(symbol *sym)
{
  sym->c = Random('a', 'z');
  sym->pos.x = Random(0, WINDOW_SIZE_X);
  sym->pos.y = Random(0, WINDOW_SIZE_Y);
}

void SymbolClear(symbol *sym)
{
  SetSym(' ', sym->pos.x, sym->pos.y);
}

bool SymbolCheck(symbol *sym)
{
  if (sym->pos.y == WINDOW_SIZE_Y)
  {
    return true;
  }
  
  return false;
}
