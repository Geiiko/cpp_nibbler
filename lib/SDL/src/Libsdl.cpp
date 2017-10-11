//
// Libsdl.cpp for src in /home/degand/Projects/cpp_nibbler/src
// 
// Made by Alaric
// Login   <degand@epitech.net>
// 
// Started on  Tue Mar 31 14:20:56 2015 Alaric
// Last update Sun Apr  5 23:54:35 2015 Alaric
//

#include	<iostream>
#include	<SDL/SDL.h>
#include        <SDL/SDL_ttf.h>
#include	<SDL/SDL_image.h>
#include	<sstream>
#include	<string>
#include	"Libsdl.hh"
#include	"IGame.hh"
#include	"SdlError.hh"
#include	"IDisplayNibbler.hh"

Libsdl *create_object()
{
   return new Libsdl;
}

void destroy_object(Libsdl *object)
{
  delete object;
}

Libsdl::Libsdl()
{
  SDL_Init(SDL_INIT_VIDEO);
  TTF_Init();
  this->_poli = TTF_OpenFont("arial.ttf", 18);
  this->_white.r = 0xff;
  this->_white.g = 0xff;
  this->_white.b = 0xff;
  this->_SquareX = 30;
  this->_SquareY = 30;
  this->_chicken = SDL_LoadBMP("BMP/chicken.bmp");
  this->_apple = SDL_LoadBMP("BMP/pomme.bmp");
  this->_bad = SDL_LoadBMP("BMP/bad.bmp");
  this->_spike = SDL_LoadBMP("BMP/pointe.bmp");
  this->_wall = SDL_LoadBMP("BMP/wall.bmp");
}

Libsdl::~Libsdl()
{
  TTF_CloseFont(this->_poli);
  SDL_Quit();
  TTF_Quit();
}

int		Libsdl::createWindow(int x, int y)
{
  int		a = 1;
  int		b = 1;
  SDL_Rect	pos;

  if (x > 60 || y > 34)
    throw SdlError("Screen is too small for that map size");
  this->_x = x * this->_SquareX;
  this->_y = y * this->_SquareY;
  this->_posPoli.y = this->_y + 5;
  this->_posPoli.x = 50;
  pos.x = 0;
  pos.y = 0;
  this->_ecran = SDL_SetVideoMode(this->_SquareX * x, this->_SquareY * y + 50, 32, SDL_HWSURFACE);
  if (this->_ecran == NULL)
    throw SdlError("Fail SDL_SetVideoMode");
  SDL_WM_SetCaption("Nibbler", NULL);
  this->_grid = SDL_CreateRGBSurface(SDL_HWSURFACE, this->_SquareX * x, this->_SquareY * y, 32, 0, 0, 0, 0);
  SDL_FillRect(this->_grid, NULL, SDL_MapRGB(this->_grid->format, 159, 106, 26));
  a = this->_SquareX;
  while (a < x * this->_SquareX)
    {
      b = 0;
      while (++b < y * this->_SquareY)
	this->colorPixel(a, b, this->_white);
      a += this->_SquareX;
    }
  a = this->_SquareY;
  while (a < y * this->_SquareY)
    {
      b = 0;
      while (++b < x * this->_SquareX)
	this->colorPixel(b, a, this->_white);
      a += this->_SquareY;
    }
  SDL_BlitSurface(this->_grid, NULL, this->_ecran, &pos);
  SDL_Flip(this->_ecran);
  return (this->_SquareX);
}

void		Libsdl::colorPixel(int x, int y, const RGBcolor &col)
{
  Uint32	color;
  int		bpp;
  Uint8		*p;

  color = SDL_MapRGB(this->_grid->format, col.r, col.g, col.b);
  SDL_LockSurface(this->_grid);
  bpp = this->_grid->format->BytesPerPixel;
  p = (Uint8 *)this->_grid->pixels + y * this->_grid->pitch + x * bpp;
  *(Uint32 *)p = color;
  SDL_UnlockSurface(this->_grid);
}

void		Libsdl::colorSquare(int x, int y, const RGBcolor &color)
{
  int		a = x + this->_SquareX;
  int		b = y + this->_SquareY;
  int		c = y;
  SDL_Rect	pos;

  pos.x = x;
  pos.y = y;
  if (color.disp == 'C')
    SDL_BlitSurface(this->_chicken, NULL, this->_grid, &pos);
  else if (color.disp == 'a')
    SDL_BlitSurface(this->_apple, NULL, this->_grid, &pos);
  else if (color.disp == 'b')
    SDL_BlitSurface(this->_bad, NULL, this->_grid, &pos);
  else if (color.disp == 'S')
    SDL_BlitSurface(this->_spike, NULL, this->_grid, &pos);
  else if (color.disp == 'W')
    SDL_BlitSurface(this->_wall, NULL, this->_grid, &pos);
  else
    while (x < a)
      {
	c = y;
	while (c < b)
	  {
	    this->colorPixel(x, c, color);
	    c++;
	  }
	x++;
      }
  pos.x = 0;
  pos.y = 0;
  SDL_BlitSurface(this->_grid, NULL, this->_ecran, &pos);
}

void		Libsdl::clearScreen()
{
  int		a = 1;
  int		b = 1;
  SDL_Rect	pos;

  pos.x = 0;
  pos.y = 0;
  SDL_FillRect(this->_ecran, NULL, SDL_MapRGB(this->_ecran->format, 0, 0, 0));
  SDL_FillRect(this->_grid, NULL, SDL_MapRGB(this->_grid->format, 159, 106, 26));
  a = this->_SquareX;
  while (a < this->_x)
    {
      b = 0;
      while (++b < this->_y)
	this->colorPixel(a, b, this->_white);
      a += this->_SquareX;
    }
  a = this->_SquareY;
  while (a < this->_y)
    {
      b = 0;
      while (++b < this->_x)
	this->colorPixel(b, a, this->_white);
      a += this->_SquareY;
    }
  SDL_BlitSurface(this->_grid, NULL, this->_ecran, &pos);
}

IDisplayNibbler::event		Libsdl::clearEvents()
{
  SDL_Flip(this->_ecran);
  while (SDL_PollEvent(&this->_Event))
    {
      switch (this->_Event.type)
	{
	case SDL_QUIT:
	  return (Exit);
	  break;
	case SDL_KEYDOWN:
	  switch (this->_Event.key.keysym.sym)
	    {
	    case SDLK_RIGHT:
	      return (TurnRight);
	      break;
	    case SDLK_LEFT:
	      return (TurnLeft);
	      break;
	    case SDLK_ESCAPE:
	      return (Exit);
	      break;
	    default:
	      break;
	    }
	  break;
	default:
	  break;
	}
    }
  return (None);
}

void		Libsdl::displayScore(int _score)
{
  std::stringstream	ss;
  std::string		score;
  SDL_Color		couleur;

  couleur.r = 250;
  couleur.g = 250;
  couleur.b = 250;
  ss << "Score : " << _score;
  score = ss.str();
  this->_texte = TTF_RenderText_Solid(this->_poli, score.c_str(), couleur);
  SDL_BlitSurface(this->_texte, NULL, this->_ecran, &this->_posPoli);
  SDL_Flip(this->_ecran);
  SDL_FillRect(this->_texte, NULL, SDL_MapRGB(this->_texte->format, 0, 0, 0));
}

void		Libsdl::closeWindow()
{
  SDL_FreeSurface(this->_ecran);
  SDL_FreeSurface(this->_grid);
  SDL_FreeSurface(this->_texte);
}

IGame::GameType Libsdl::displayMenu()
{
  return (IGame::GameSolo);
}
