//
// BlackHole.cpp for  in /home/zwertv_e/rendu/cpp_nibbler
// 
// Made by zwertv_e
// Login   <zwertv_e@epitech.net>
// 
// Started on  Sun Apr  5 22:40:05 2015 zwertv_e
// Last update Sun Apr  5 23:17:13 2015 zwertv_e
//

#include "IObject.hh"
#include "BlackHole.hh"

BlackHole::BlackHole(int _x, int _y) : x(_x), y(_y)
{
  this->color.r = 0;
  this->color.g = 0;
  this->color.b = 0;
  this->color.disp = 'H';
  this->collected = false;
  this->life = 25;
}
BlackHole::~BlackHole(void) {}

int BlackHole::getPosX(void) const { return (this->x); }
int BlackHole::getPosY(void) const { return (this->y); }
void BlackHole::lifeCycle(void)
{
  --this->life;
  if (life == 0)
    this->collected = true;
}
int BlackHole::isAvailable(void) const { return (!(this->collected)); }

void BlackHole::setAvailable(bool _available)
{
  this->collected = !(_available);
}

int BlackHole::getScoreValue(void) const { return (100); }
bool BlackHole::isWall(void) const { return (false); }
bool BlackHole::canCollect(void) const { return (true); }
IObject::effect BlackHole::getEffect(void) const { return (IObject::SpeedUp); }
const RGBcolor &BlackHole::getColor(void) const { return (this->color); }
