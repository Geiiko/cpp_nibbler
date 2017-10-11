//
// SnakeRT.hh for  in /home/zwertv_e/rendu/cpp_nibbler/src
// 
// Made by zwertv_e
// Login   <zwertv_e@epitech.net>
// 
// Started on  Thu Apr  2 17:52:45 2015 zwertv_e
// Last update Sun Apr  5 21:44:01 2015 zwertv_e
//

#ifndef SNAKERT_H__
# define SNAKERT_H__

# include <vector>
# include "IGame.hh"
# include "IDisplayNibbler.hh"

class SnakeRT
{
private:
  void *handler;
  IDisplayNibbler *display;
  IGame *game;

public:
  SnakeRT(const char *path);
  ~SnakeRT(void);

public:
  bool loadGame(int _x, int _y);
  bool loadChars(void) const;
  void runGame(void) const;
};

#endif
