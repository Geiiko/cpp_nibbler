//
// InfiniteWall.cpp for  in /home/zwertv_e/rendu/cpp_nibbler
// 
// Made by zwertv_e
// Login   <zwertv_e@epitech.net>
// 
// Started on  Sun Apr  5 23:28:57 2015 zwertv_e
// Last update Sun Apr  5 23:29:56 2015 zwertv_e
//

#include "IObject.hh"
#include "InfiniteWall.hh"

InfiniteWall::InfiniteWall(int _x, int _y) : x(_x), y(_y)
{
  this->color.r = 100;
  this->color.g = 100;
  this->color.b = 100;
  this->color.disp = 'W';
  this->collected = false;
  this->life = -1;
}
InfiniteWall::~InfiniteWall(void) {}

int InfiniteWall::getPosX(void) const { return (this->x); }
int InfiniteWall::getPosY(void) const { return (this->y); }
void InfiniteWall::lifeCycle(void) {}
int InfiniteWall::isAvailable(void) const { return (!(this->collected)); }

void InfiniteWall::setAvailable(bool _available)
{
  this->collected = !(_available);
}

int InfiniteWall::getScoreValue(void) const { return (0); }
bool InfiniteWall::isWall(void) const { return (true); }
bool InfiniteWall::canCollect(void) const { return (false); }
IObject::effect InfiniteWall::getEffect(void) const { return (IObject::None); }
const RGBcolor &InfiniteWall::getColor(void) const { return (this->color); }
