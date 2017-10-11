//
// SnakeRT.cpp for  in /home/zwertv_e/rendu/cpp_nibbler/src
// 
// Made by zwertv_e
// Login   <zwertv_e@epitech.net>
// 
// Started on  Thu Apr  2 17:45:20 2015 zwertv_e
// Last update Sun Apr  5 21:39:49 2015 zwertv_e
//

#include <dlfcn.h>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include "SnakeRT.hh"
#include "IGame.hh"
#include "GameSolo.hh"

SnakeRT::SnakeRT(const char *path)
{
  std::stringstream ss;

  if (path[0] != '/' || path[0] != '~')
    ss << "./";
  ss << path;
  this->handler = dlopen((ss.str()).c_str(), RTLD_LAZY);
  if (handler == NULL)
    {
      char *error = dlerror();
      if (error != NULL)
	printf("Error: %s\n", error);
      exit(EXIT_FAILURE); // Throw execption
    }
  IDisplayNibbler* (*create)();

  create = (IDisplayNibbler * (*)())dlsym(this->handler, "create_object");
  this->display = (IDisplayNibbler *)create();
}

SnakeRT::~SnakeRT(void)
{
  void (*destroy)(IDisplayNibbler *);

  if (this->game)
    delete (this->game);
  destroy = (void (*)(IDisplayNibbler *))dlsym(this->handler, "destroy_object");
  destroy(this->display);
  dlclose(this->handler);
}

bool SnakeRT::loadGame(int _x, int _y)
{
  IGame::GameType _type;

  _type = this->display->displayMenu();
  if (_type == IGame::Quit)
    return (false);
  if (_type == IGame::GameSolo)
    this->game = new GameSolo(this->display, _x, _y);
  return (true);
}

bool SnakeRT::loadChars(void) const
{
  return (this->game->loadChars());
}

void SnakeRT::runGame() const
{
  this->game->runGame();
}
