#include "textui.hpp"

#include <cstring>

#include "error.hpp"

namespace goapp {

void TextUiSystem::Init(bool mouse_support) {
  initscr();
  clear();
  noecho();
  halfdelay(10);
  nonl();
  intrflush(stdscr, FALSE);
  keypad(stdscr, TRUE);
  if (curs_set(0) == ERR) {
    Log::Debug("Unable to change cursor: {}", ::strerror(errno));
  }
  if (mouse_support) {
    mousemask(BUTTON1_CLICKED, NULL);
  }
}

void TextUiSystem::Close() { endwin(); }

TextWindow::TextWindow(int x, int y, int width, int height) { m_win = newwin(width, height, x, y); }

TextWindow::~TextWindow() {
  wclear(m_win);
  wrefresh(m_win);
  delwin(m_win);
}

} // namespace goapp
