//
// Wall.cpp for  in /home/zwertv_e/rendu/cpp_nibbler
// 
// Made by zwertv_e
// Login   <zwertv_e@epitech.net>
// 
// Started on  Sun Apr  5 23:08:26 2015 zwertv_e
// Last update Sun Apr  5 23:11:04 2015 zwertv_e
//

#include "IObject.hh"
#include "Wall.hh"

Wall::Wall(int _x, int _y) : x(_x), y(_y)
{
  this->color.r = 100;
  this->color.g = 100;
  this->color.b = 100;
  this->color.disp = 'W';
  this->collected = false;
  this->life = 45;
}
Wall::~Wall(void) {}

int Wall::getPosX(void) const { return (this->x); }
int Wall::getPosY(void) const { return (this->y); }
void Wall::lifeCycle(void)
{
  --this->life;
  if (life == 0)
    this->collected = true;
}
int Wall::isAvailable(void) const { return (!(this->collected)); }

void Wall::setAvailable(bool _available)
{
  this->collected = !(_available);
}

int Wall::getScoreValue(void) const { return (0); }
bool Wall::isWall(void) const { return (true); }
bool Wall::canCollect(void) const { return (false); }
IObject::effect Wall::getEffect(void) const { return (IObject::None); }
const RGBcolor &Wall::getColor(void) const { return (this->color); }
