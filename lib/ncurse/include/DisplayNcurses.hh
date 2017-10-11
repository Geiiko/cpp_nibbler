//
// DisplayNcurses.hh for  in /home/zwertv_e/rendu/cpp_nibbler/lib/ncurse/include
// 
// Made by zwertv_e
// Login   <zwertv_e@epitech.net>
// 
// Started on  Mon Mar 30 18:31:51 2015 zwertv_e
// Last update Sun Apr  5 19:46:32 2015 zwertv_e
//

#ifndef DISPLAYNCURSES_H__
# define DISPLAYNCURSES_H__

# include "IDisplayNibbler.hh"
# include "IGame.hh"

class DisplayNcurses : public IDisplayNibbler
{
private:
  int maxX;
  int maxY;
  int x;
  int y;
  WINDOW *score;

public:
  DisplayNcurses(void);
  virtual int createWindow(int _x, int _y);
  virtual void colorPixel(int _x, int _y, const RGBcolor &_color);
  virtual void colorSquare(int _x, int _y, const RGBcolor &_color);
  virtual void clearScreen(void);
  virtual IDisplayNibbler::event clearEvents(void);
  virtual void displayScore(int _score);
  virtual void closeWindow();
  virtual IGame::GameType displayMenu(void);
  virtual ~DisplayNcurses(void);
};

extern "C" DisplayNcurses* create_object();
extern "C" void destroy_object(DisplayNcurses* object);

#endif
