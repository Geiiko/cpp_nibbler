//
// Libsdl.hh for  in /home/zwertv_e/rendu/cpp_nibbler/lib/SDL
// 
// Made by zwertv_e
// Login   <zwertv_e@epitech.net>
// 
// Started on  Thu Apr  2 19:32:24 2015 zwertv_e
// Last update Sun Apr  5 23:50:11 2015 Alaric
//

#ifndef		_LIBSDL_HH_
# define	_LIBSDL_HH_

#include	<SDL/SDL.h>
#include	<SDL/SDL_ttf.h>
#include	<SDL/SDL_image.h>
#include	"IDisplayNibbler.hh"
#include	"IGame.hh"

#define		SIZE_X 10
#define		SIZE_Y 10

class		Libsdl : public IDisplayNibbler
{
private:
  SDL_Surface	*_ecran;
  SDL_Surface	*_grid;
  SDL_Surface	*_texte;
  SDL_Surface	*_chicken;
  SDL_Surface	*_apple;
  SDL_Surface	*_bad;
  SDL_Surface	*_spike;
  SDL_Surface	*_wall;
  int		_SquareX;
  int		_SquareY;
  SDL_Event	_Event;
  int		_x;
  int		_y;
  TTF_Font	*_poli;
  SDL_Rect	_posPoli;
 public:

  RGBcolor      _white;
  Libsdl(void);
  virtual ~Libsdl(void);
  virtual int  createWindow(int x, int y);
  virtual void colorPixel(int x, int y, const RGBcolor &color);
  virtual void colorSquare(int x, int y, const RGBcolor &color);
  virtual void clearScreen(void);
  virtual void displayScore(int _score);
  virtual IDisplayNibbler::event clearEvents(void);
  virtual void closeWindow();
  virtual IGame::GameType displayMenu();
};

extern "C" Libsdl* create_object();
extern "C" void destroy_object(Libsdl* object);

#endif		/* !_LIBSDL_HH_ */
