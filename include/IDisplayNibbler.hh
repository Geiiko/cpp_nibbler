//
// IDisplayNibbler.hh for  in /home/zwertv_e/rendu/cpp_nibbler/include
// 
// Made by zwertv_e
// Login   <zwertv_e@epitech.net>
// 
// Started on  Mon Mar 30 18:48:28 2015 zwertv_e
// Last update Sun Apr  5 19:46:11 2015 zwertv_e
//

#ifndef IDISPLAYNIBBLER_H__
# define IDISPLAYNIBBLER_H__

# include "IGame.hh"

typedef struct	RGBcolor
{
  int		r;
  int		g;
  int		b;
  char		disp;
}		RGBcolor;

class IDisplayNibbler
{
public:
  enum event
    {
      TurnRight,
      TurnLeft,
      Exit,
      None
    };

public:
  virtual ~IDisplayNibbler(void) {}

public:
  virtual int createWindow(int _x, int _y) = 0;
  virtual void colorPixel(int _x, int _y, const RGBcolor &_color) = 0;
  virtual void colorSquare(int _x, int _y, const RGBcolor &_color) = 0;
  virtual void clearScreen(void) = 0;
  virtual IDisplayNibbler::event clearEvents(void) = 0;
  virtual void displayScore(int _score) = 0;
  virtual void closeWindow() = 0;
  virtual IGame::GameType displayMenu(void) = 0;
};

#endif
