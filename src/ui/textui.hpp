#pragma once

#include <ncurses.h>
namespace goapp {

class TextUiSystem {
public:
  static void Init(bool mouse_support);
  static void Close();
};

class TextWindow {
  WINDOW* m_win;

public:
  TextWindow(int x, int y, int width, int height);
  ~TextWindow();

  void KeyPad();
};

} // namespace goapp
