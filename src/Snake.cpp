//
// Snake.cpp for  in /home/zwertv_e/rendu/cpp_nibbler/include
// 
// Made by zwertv_e
// Login   <zwertv_e@epitech.net>
// 
// Started on  Thu Apr  2 15:41:16 2015 zwertv_e
// Last update Sun Apr  5 23:22:54 2015 zwertv_e
//

#include <list>
#include <cstdlib>
#include "ICharacter.hh"
#include "Snake.hh"

Snake::Snake(int _x, int _y, int _size, int _speed)
{
  int tmp = 0;

  this->size = _size;
  this->speed = _speed;
  while (_size > 0)
    {
      this->posX.push_back(_x - tmp);
      this->posY.push_back(_y);
      --_size;
      ++tmp;
    }
  this->direction = ICharacter::Right;
  this->color.r = 0;
  this->color.g = 255;
  this->color.b = 0;
  this->color.disp = '*';
}

Snake::~Snake(void)
{
  while (!(this->posX.empty()))
    this->posX.pop_back();
  while (!(this->posY.empty()))
    this->posY.pop_back();
}

// Deplacements
void Snake::moveLeft(void)
{
  this->posX.pop_back();
  this->posY.pop_back();
  this->posX.insert(this->posX.begin(), this->posX[0] - 1);
  this->posY.insert(this->posY.begin(), this->posY[0]);
}

void Snake::moveRight(void)
{
  this->posX.pop_back();
  this->posY.pop_back();
  this->posX.insert(this->posX.begin(), this->posX[0] + 1);
  this->posY.insert(this->posY.begin(), this->posY[0]);
}

void Snake::moveUp(void)
{
  this->posX.pop_back();
  this->posY.pop_back();
  this->posX.insert(this->posX.begin(), this->posX[0]);
  this->posY.insert(this->posY.begin(), this->posY[0] - 1);
}

void Snake::moveDown(void)
{
  this->posX.pop_back();
  this->posY.pop_back();
  this->posX.insert(this->posX.begin(), this->posX[0]);
  this->posY.insert(this->posY.begin(), this->posY[0] + 1);
}

void Snake::move(void)
{
  switch (this->direction)
    {
    case (ICharacter::Left):
      this->moveLeft();
      break;
    case (ICharacter::Right):
      this->moveRight();
      break;
    case (ICharacter::Up):
      this->moveUp();
      break;
    case (ICharacter::Down):
      this->moveDown();
      break;
    default:
      this->moveRight();
      break;
    }
}

// Rotations
void Snake::turnLeft(void)
{
  switch (this->direction)
    {
    case (ICharacter::Left):
      this->direction = ICharacter::Down;
      break;
    case (ICharacter::Right):
      this->direction = ICharacter::Up;
      break;
    case (ICharacter::Up):
      this->direction = ICharacter::Left;
      break;
    case (ICharacter::Down):
      this->direction = ICharacter::Right;
      break;
    default:
      this->direction = ICharacter::Right;
      break;
    }
}

void Snake::turnRight(void)
{
  switch (this->direction)
    {
    case (ICharacter::Left):
      this->direction = ICharacter::Up;
      break;
    case (ICharacter::Right):
      this->direction = ICharacter::Down;
      break;
    case (ICharacter::Up):
      this->direction = ICharacter::Right;
      break;
    case (ICharacter::Down):
      this->direction = ICharacter::Left;
      break;
    default:
      this->direction = ICharacter::Right;
      break;
    }
}

// effets
void Snake::grow(void)
{
  ++this->size;
  this->posX.push_back(this->posX[this->size - 2]);
  this->posY.push_back(this->posY[this->size - 2]);
}

void Snake::shrink(void)
{
  if (this->size < 3)
    return;
  --this->size;
  this->posX.pop_back();
  this->posY.pop_back();
}

int Snake::getPosX(int _elem) const { return (this->posX[(unsigned long)_elem]); }
int Snake::getPosY(int _elem) const { return (this->posY[(unsigned long)_elem]); }
int Snake::getSize(void) const { return (this->size); }
int Snake::getSpeed(void) const { return (this->speed); }
void Snake::setSpeed(int _speed) { this->speed = _speed; }
ICharacter::direction Snake::getDir(void) const { return (this->direction); }
bool Snake::isAlive(void) const
{
  int x = this->posX[0];
  int y = this->posY[0];
  int tmp = 1;

  while (tmp < this->size)
    {
      if (this->posX[tmp] == x && this->posY[tmp] == y)
	return (false);
      ++tmp;
    }
  return (true);
}
const RGBcolor &Snake::getColor(void) const { return (this->color); }
