//
// libOpenGL.cpp for  in /home/dubell_g/rendu/cpp_nibbler/lib/OpenGL
// 
// Made by dubell_g
// Login   <dubell_g@epitech.net>
// 
// Started on  Sun Apr  5 14:57:46 2015 dubell_g
// Last update Sun Apr  5 23:52:34 2015 dubell_g
//

#include	<SDL/SDL.h>
#include	<GL/gl.h>
#include	<GL/glu.h>
#include	"DisplayOpenGL.hh"
#include	"IGame.hh"
#include	"IDisplayNibbler.hh"
#include	"OpenGLError.hh"

DisplayOpenGL*	create_object(void)
{
  return new DisplayOpenGL;
}

void		destroy_object(DisplayOpenGL* object)
{
  delete object;
}

DisplayOpenGL::DisplayOpenGL(void)
{
  SDL_Init(SDL_INIT_VIDEO);
  this->_square = 30;
}

DisplayOpenGL::~DisplayOpenGL(void)
{
  SDL_Quit();
}

int		DisplayOpenGL::createWindow(int x, int y)
{
  if (x > 61 || y > 34)
    {
      throw OpenGLError("Screen is too small for that map size !");
    }
  this->_width = x * this->_square;
  this->_height = y * this->_square;
  this->_ecran = SDL_SetVideoMode(this->_width, this->_height, 32, SDL_OPENGL);
  if (this->_ecran == NULL)
    {
      throw OpenGLError("Fail SetVideoMode");
    }
  SDL_WM_SetCaption("Nibbler", NULL);
  glViewport(0, 0, this->_width, this->_height);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0, this->_width, this->_height, 0);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glClear(GL_COLOR_BUFFER_BIT);
  glBegin(GL_QUADS);
  glColor3ub(50, 50, 50);
  glVertex2d(0, 0);
  glVertex2d(0, this->_height);
  glVertex2d(this->_width, this->_height);
  glVertex2d(this->_width, 0);
  glEnd();
  return (this->_square);
}

void		DisplayOpenGL::colorPixel(int x, int y, const RGBcolor &color)
{
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glBegin(GL_POINTS);
  glColor3ub(color.r, color.g, color.b);
  glVertex2d(x, y);
  glEnd();
}

void		DisplayOpenGL::colorSquare(int x, int y, const RGBcolor &color)
{
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glBegin(GL_QUADS);
  glColor3ub(color.r, color.g, color.b);
  glVertex2d(x, y);
  glVertex2d(x + this->_square, y);
  glVertex2d(x + this->_square, y + this->_square);
  glVertex2d(x, y + this->_square);
  glEnd();
}

void		DisplayOpenGL::clearScreen(void)
{
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glClear(GL_COLOR_BUFFER_BIT);
  glBegin(GL_QUADS);
  glColor3ub(50, 50, 50);
  glVertex2d(0, 0);
  glVertex2d(0, this->_height);
  glVertex2d(this->_width, this->_height);
  glVertex2d(this->_width, 0);
  glEnd();
}

IDisplayNibbler::event	DisplayOpenGL::clearEvents(void)
{
  SDL_Event	event;

  glFlush();
  SDL_GL_SwapBuffers();
  while (SDL_PollEvent(&event))
    {
      switch(event.type)
	{
	case SDL_QUIT:
	  return (IDisplayNibbler::Exit);
	  break;
	case SDL_KEYDOWN:
	  switch (event.key.keysym.sym)
	    {
	    case SDLK_LEFT:
	      return (IDisplayNibbler::TurnLeft);
	      break;
	    case SDLK_RIGHT:
	      return (IDisplayNibbler::TurnRight);
	      break;
	    case ('q'):
	    case SDLK_ESCAPE:
	      return (IDisplayNibbler::Exit);
	    break;
	    default:
	      return (IDisplayNibbler::None);
	      break;
	    }
	  break;
	}
    }
  return (IDisplayNibbler::None);
}

void		DisplayOpenGL::displayScore(int score)
{
  this->_score = score;
}

void		DisplayOpenGL::closeWindow(void)
{
  SDL_FreeSurface(this->_ecran);
}

IGame::GameType	DisplayOpenGL::displayMenu(void)
{
  return (IGame::GameSolo);
}
