#include "ncurapi.h"

void SymbolDraw(symbol *sym)
{
  move(sym->pos.y, sym->pos.x);
  printw("%c", sym->c);
  refresh();
}

void SymbolRand(symbol *sym)
{
  sym->c = Random('a', 'z');
  sym->pos.x = Random(0, WINDOW_SIZE_X);
  sym->pos.y = Random(0, WINDOW_SIZE_Y);
}
