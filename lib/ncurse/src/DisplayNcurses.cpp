//
// DisplayNcurses.cpp for  in /home/zwertv_e/rendu/cpp_nibbler/lib/ncurse/include
// 
// Made by zwertv_e
// Login   <zwertv_e@epitech.net>
// 
// Started on  Mon Mar 30 18:35:29 2015 zwertv_e
// Last update Sun Apr  5 21:49:23 2015 zwertv_e
//

#include	<ncurses.h>
#include	<curses.h>
#include	<string>
#include	<sstream>
#include	<iostream>
#include	"IDisplayNibbler.hh"
#include	"DisplayNcurses.hh"
#include	"NcursesError.hh"

DisplayNcurses* create_object()
{
  return new DisplayNcurses;
}

void destroy_object(DisplayNcurses* object)
{
  delete object;
}

DisplayNcurses::DisplayNcurses(void) {}
DisplayNcurses::~DisplayNcurses(void) {}

int	DisplayNcurses::createWindow(int _x, int _y)
{
  this->x = _x;
  this->y = _y;
  initscr();
  getmaxyx(stdscr, this->maxX, this->maxY);
  if (_x >= this->maxX || _y > this->maxY)
    {
      endwin();
      throw NcursesError("Screen is too small for that map size !");
    }
  nodelay(stdscr, TRUE);
  noecho();
  cbreak();
  curs_set(0);
  keypad(stdscr, TRUE);
  wresize(stdscr, _x + 2, _y + 2);
  this->score = newwin(3, _y + 2, 0 , 0);
  mvwin(this->score, _x + 1, 0);
  box(stdscr, '|', '-');
  box(this->score, '|', '-');
  mvwprintw(this->score, 1, 2, "Score: 0");
  wrefresh(stdscr);
  wrefresh(this->score);
  refresh();
  return (1);
}

void	DisplayNcurses::colorPixel(int _x, int _y, const RGBcolor &_color)
{
  mvwprintw(stdscr, _y + 1, _x + 1, std::string(1, _color.disp).c_str());
  redrawwin(stdscr);
}

void	DisplayNcurses::colorSquare(int _x, int _y, const RGBcolor &_color)
{
  mvwprintw(stdscr, _y + 1, _x + 1, std::string(1, _color.disp).c_str());
  redrawwin(stdscr);
  refresh();
}

void	DisplayNcurses::displayScore(int _score)
{
  std::stringstream ss;
  std::string score;

  ss << "Score: " << _score;
  score = ss.str();
  wclear(this->score);
  box(this->score, '|', '-');
  mvwprintw(this->score, 1, 2, score.c_str());
  wrefresh(this->score);
}

void	DisplayNcurses::clearScreen(void)
{
  wclear(stdscr);
  box(stdscr, '|', '-');
}

IDisplayNibbler::event	DisplayNcurses::clearEvents(void)
{
  int ch;

  ch = wgetch(stdscr);
  refresh();
  switch (ch)
    {
    case (KEY_LEFT):
      return (IDisplayNibbler::TurnLeft);
      break;
    case (KEY_RIGHT):
      return (IDisplayNibbler::TurnRight);
      break;
    case ('q'):
      return (IDisplayNibbler::Exit);
      break;
    default:
      return (IDisplayNibbler::None);
      break;
    }
}

IGame::GameType DisplayNcurses::displayMenu(void)
{
  return (IGame::GameSolo);
}

void	DisplayNcurses::closeWindow()
{
  delwin(this->score);
  endwin();
}
