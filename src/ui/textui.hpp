#pragma once

#include <ncurses.h>
namespace goapp {

struct UISize {
  int width = 0;
  int height = 0;
};

struct UICoords {
  int x = 0;
  int y = 0;
};

class TextUiSystem {
public:
  static void Init(bool mouse_support);
  static void Close();
  static UISize ScreenSize();
};

class TextWindow {
  WINDOW* m_win;
  bool m_owned = true;

public:
  TextWindow(int x, int y, int width, int height);
  TextWindow(UICoords, UISize);
  TextWindow(WINDOW*);
  ~TextWindow();

  void KeyPad();
  UISize Size();
};

} // namespace goapp
