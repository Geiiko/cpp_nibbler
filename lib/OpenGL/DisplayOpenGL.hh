//
// libOpenGL.hh for  in /home/dubell_g/rendu/cpp_nibbler/lib/OpenGL
// 
// Made by dubell_g
// Login   <dubell_g@epitech.net>
// 
// Started on  Sun Apr  5 14:58:05 2015 dubell_g
// Last update Sun Apr  5 22:15:25 2015 dubell_g
//

#ifndef		_DISPLAYOPENGL_HH_
# define	_DISPLAYOPENGL_HH_

# include	<SDL/SDL.h>
# include	"IDisplayNibbler.hh"
# include	"IGame.hh"

class		DisplayOpenGL : public IDisplayNibbler
{
private:
  int		_width;
  int		_height;
  int		_square;
  int		_score;
  SDL_Surface	*_ecran;

public:
  DisplayOpenGL(void);
  virtual ~DisplayOpenGL(void);

  virtual int	createWindow(int x, int y);
  virtual void	colorPixel(int x, int y, const RGBcolor &color);
  virtual void	colorSquare(int x, int y, const RGBcolor &color);
  virtual void	clearScreen(void);
  virtual IDisplayNibbler::event clearEvents(void);
  virtual void	displayScore(int score);
  virtual void	closeWindow(void);
  virtual IGame::GameType displayMenu(void);
};

extern "C" DisplayOpenGL*	create_object(void);
extern "C" void			destroy_object(DisplayOpenGL* object);

#endif		/* DISPLAYOPENGL_HH_ */
