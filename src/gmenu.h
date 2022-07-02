#pragma once
#pragma once

#include <ncurses.h>

#ifndef GMENU_H_INCLUDED
#define GMENU_H_INCLUDED

enum ACTION { REQ_DOWN, REQ_UP, REQ_SEL };

typedef struct GMenu_ GMenu;
typedef struct GItem_ GItem;

/* Menu Item */
struct GItem_ {
  char* name;
  int checked;
};

/* Menu Panel */
struct GMenu_ {
  WINDOW* win;

  int count;
  int size;
  int idx;
  int start;
  int h;
  int w;
  int x;
  int y;
  unsigned short multiple;
  unsigned short selectable;
  unsigned short status;
  GItem* items;
};

GMenu* new_gmenu(WINDOW* parent, int h, int w, int y, int x);
int post_gmenu(GMenu* menu);
void gmenu_driver(GMenu* menu, int c);

#endif
