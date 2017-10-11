//
// GameSolo.hh for  in /home/zwertv_e/rendu/cpp_nibbler/include
// 
// Made by zwertv_e
// Login   <zwertv_e@epitech.net>
// 
// Started on  Thu Apr  2 14:59:47 2015 zwertv_e
// Last update Sun Apr  5 19:45:15 2015 zwertv_e
//

#ifndef GAMESOLO_H__
# define GAMESOLO_H__

# include <list>
# include "IObject.hh"
# include "IGame.hh"
# include "ICharacter.hh"
# include "IDisplayNibbler.hh"

class GameSolo : public IGame
{
private:
  int tileSize;
  int score;
  int mapX;
  int mapY;
  int validX;
  int validY;
  IDisplayNibbler *display;
  ICharacter *player;
  std::list<IObject *> objects;
  IDisplayNibbler::event lastEvent;

public:
  GameSolo(IDisplayNibbler *_display, int _x, int _y);
  virtual ~GameSolo(void);
  virtual void runGame(void);
  virtual bool loadChars(void);
  virtual void displayChar(void);
  virtual void displayObjects(void);
  virtual bool collectObjects(void);

public:
  bool getWallCollision(void) const;
  bool getObjectsCollision(void) const;
  void updateEvents(void);
  void generatePositions(void);
};

#endif
