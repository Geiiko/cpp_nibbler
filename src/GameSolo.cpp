//
// GameSolo.cpp for  in /home/zwertv_e/rendu/cpp_nibbler/include
// 
// Made by zwertv_e
// Login   <zwertv_e@epitech.net>
// 
// Started on  Thu Apr  2 15:03:54 2015 zwertv_e
// Last update Sun Apr  5 23:30:53 2015 zwertv_e
//

#include <iostream>
#include <list>
#include <cstdlib>
#include <unistd.h>
#include <time.h>
#include "IGame.hh"
#include "ICharacter.hh"
#include "Snake.hh"
#include "GameSolo.hh"
#include "IObject.hh"
#include "Apple.hh"
#include "BadApple.hh"
#include "Chicken.hh"
#include "BlackHole.hh"
#include "Wall.hh"
#include "InfiniteWall.hh"
#include "Spicke.hh"
#include "NibblerError.hh"

bool removeUnavailableObjects(const IObject *obj) { return (!(obj->isAvailable())); }

GameSolo::GameSolo(IDisplayNibbler *_display, int _x, int _y)
{
  this->display = _display;
  this->mapX = _x;
  this->mapY = _y;
  this->score = 0;
  this->lastEvent = IDisplayNibbler::None;
  srand(time(NULL));
}
GameSolo::~GameSolo(void)
{
  while (!(this->objects.empty()))
    this->objects.pop_back();
  if (this->player)
    delete (this->player);
}

bool GameSolo::loadChars(void)
{
  this->player = new Snake(this->mapX / 2, this->mapY / 2, 4, 10);
  return (true);
}

void GameSolo::runGame(void)
{
  bool run = true;

  this->tileSize = this->display->createWindow(this->mapX, this->mapY);
  this->generatePositions();
  this->objects.push_back(new Apple(this->validX, this->validY));
  while (this->lastEvent != IDisplayNibbler::Exit && run)
    {
      this->display->clearScreen();
      this->displayChar();
      this->displayObjects();
      usleep((1500 * 1000) / static_cast<unsigned int>(this->player->getSpeed()));
      this->updateEvents();
      run = this->getWallCollision();
      if (run != false)
	run = this->getObjectsCollision();
      if (run != false)
	this->player->move();
      if (run != false)
	run = this->player->isAlive();
      if (this->collectObjects())
	{
	  this->generatePositions();
	  this->objects.push_back(new Apple(this->validX, this->validY));
	}
      if (rand() % 1000 <= 20)
	{
	  this->generatePositions();
	  this->objects.push_back(new BadApple(this->validX, this->validY));
	}
      if (rand() % 1000 <= 30)
	{
	  this->generatePositions();
	  this->objects.push_back(new Wall(this->validX, this->validY));
	}
      if (rand() % 1000 <= 1)
	{
	  this->generatePositions();
	  this->objects.push_back(new InfiniteWall(this->validX, this->validY));
	}
      if (rand() % 1000 <= 10)
	{
	  this->generatePositions();
	  this->objects.push_back(new Spicke(this->validX, this->validY));
	}
      if (rand() % 1000 <= 9)
	{
	  this->generatePositions();
	  this->objects.push_back(new Chicken(this->validX, this->validY));
	}
      if (rand() % 1000 <= 3)
	{
	  this->generatePositions();
	  this->objects.push_back(new BlackHole(this->validX, this->validY));
	}
      this->display->displayScore(this->score);
    }
  this->display->closeWindow();
  if (!run)
    std::cout << "You died !" << std::endl << "Your score: " << this->score << std::endl;
  else
    std::cout << "Game ended !" << std::endl << "Your score: " << this->score << std::endl;
}

void GameSolo::updateEvents(void)
{
  this->lastEvent = this->display->clearEvents();
  if (this->lastEvent == IDisplayNibbler::TurnLeft)
    this->player->turnLeft();
  else if (this->lastEvent == IDisplayNibbler::TurnRight)
    this->player->turnRight();
}

bool GameSolo::collectObjects(void)
{
  std::list<IObject *>::const_iterator it;
  bool collected = false;

  for (it = this->objects.begin(); it != this->objects.end(); ++it)
    {
      (*it)->lifeCycle();
      if ((*it)->canCollect() && (*it)->isAvailable())
	{
	  if ((*it)->getPosX() == this->player->getPosX(0) && (*it)->getPosY() == this->player->getPosY(0))
	    {
	      (*it)->setAvailable(false);
	      this->score += (*it)->getScoreValue();
	      switch ((*it)->getEffect())
		{
		case (IObject::Grow):
		  collected = true;
		  this->player->grow();
		  break;
		case (IObject::Shrink):
		  this->player->shrink();
		  break;
		case (IObject::SpeedUp):
		  this->player->setSpeed(this->player->getSpeed() + 3);
		  break;
		case (IObject::SpeedDown):
		  if (this->player->getSpeed() > 10)
		    this->player->setSpeed(this->player->getSpeed() - 1);
		  break;
		default:
		  break;
		};
	    }
	}
    }
  this->objects.remove_if(removeUnavailableObjects);
  return (collected);
}

void GameSolo::generatePositions(void)
{
  int ranX = 0;
  int ranY = 0;
  int secu = (this->mapX * this->mapY);
  bool isOk = false;
  int tmp;
  std::list<IObject *>::const_iterator it;

  secu *= secu;
  while (secu > 0 && isOk == false)
    {
      ranX = rand() % this->mapX;
      ranY = rand() % this->mapY;
      tmp = 0;
      isOk = true;
      while (tmp < this->player->getSize())
	{
	  if (ranX == this->player->getPosX(tmp) && this->player->getPosY(tmp) == ranY)
	    isOk = false;
	  ++tmp;
	}
      for (it = this->objects.begin(); it != this->objects.end(); ++it)
	{
	  if ((*it)->getPosX() == ranX && (*it)->getPosY() == ranY)
	    isOk = false;
	}
      --secu;
    }
  if (secu == 0)
    throw NibblerError("Map is full !");
  this->validX = ranX;
  this->validY = ranY;
}

bool GameSolo::getWallCollision(void) const
{
  bool run = true;

  switch (this->player->getDir())
    {
    case (ICharacter::Left):
      if (this->player->getPosX(0) == 0)
	run = false;
      break;
    case (ICharacter::Right):
      if (this->player->getPosX(0) == this->mapX - 1)
	run = false;
      break;
    case (ICharacter::Up):
      if (this->player->getPosY(0) == 0)
	run = false;
      break;
    case (ICharacter::Down):
      if (this->player->getPosY(0) == this->mapY - 1)
	run = false;
      break;
    };
  return (run);
}

bool GameSolo::getObjectsCollision(void) const
{
  std::list<IObject *>::const_iterator it;

  for (it = this->objects.begin(); it != this->objects.end(); ++it)
    {
      if ((*it)->isWall())
	{
	  if ((*it)->getPosX() == this->player->getPosX(0) && (*it)->getPosY() == this->player->getPosY(0))
	    return (false);
	}
    }
  return (true);
}

void GameSolo::displayChar(void)
{
  int s = this->player->getSize();
  int tmp = 0;

  while (tmp < s)
    {
      this->display->colorSquare(this->player->getPosX(tmp) * this->tileSize, this->player->getPosY(tmp) * this->tileSize, this->player->getColor());
      ++tmp;
    }
}

void GameSolo::displayObjects(void)
{
  std::list<IObject *>::const_iterator it;

  for (it = this->objects.begin(); it != this->objects.end(); ++it)
    this->display->colorSquare((*it)->getPosX() * this->tileSize, (*it)->getPosY() * this->tileSize, (*it)->getColor());
}
