#include "textui.hpp"

#include <cstring>
#include <memory>
#include "util/error.hpp"

namespace goapp {

static std::unique_ptr<TextWindow> s_screen;

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
  s_screen = std::make_unique<TextWindow>(stdscr);
}

void TextUiSystem::Close() {
  s_screen.reset();
  endwin();
}

UISize TextUiSystem::ScreenSize() { return s_screen->Size(); }

TextWindow::TextWindow(int x, int y, int width, int height) { m_win = newwin(height, width, y, x); }
TextWindow::TextWindow(UICoords where, UISize size) { m_win = newwin(size.height, size.width, where.y, where.x); }
TextWindow::TextWindow(WINDOW* wnd) {
  m_win = wnd;
  m_owned = false;
}

TextWindow::~TextWindow() {
  wclear(m_win);
  wrefresh(m_win);
  if (m_owned) {
    delwin(m_win);
  }
}

UISize TextWindow::Size() {
  UISize size;
  getmaxyx(m_win, size.height, size.width);
  return size;
}

} // namespace goapp
