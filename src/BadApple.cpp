//
// BadApple.cpp for  in /home/zwertv_e/rendu/cpp_nibbler
// 
// Made by zwertv_e
// Login   <zwertv_e@epitech.net>
// 
// Started on  Sun Apr  5 22:13:15 2015 zwertv_e
// Last update Sun Apr  5 23:01:53 2015 zwertv_e
//

#include "IObject.hh"
#include "BadApple.hh"

BadApple::BadApple(int _x, int _y) : x(_x), y(_y)
{
  this->color.r = 125;
  this->color.g = 0;
  this->color.b = 0;
  this->color.disp = 'b';
  this->collected = false;
  this->life = 30;
}
BadApple::~BadApple(void) {}

int BadApple::getPosX(void) const { return (this->x); }
int BadApple::getPosY(void) const { return (this->y); }
void BadApple::lifeCycle(void)
{
  --this->life;
  if (life == 0)
    this->collected = true;
}
int BadApple::isAvailable(void) const { return (!(this->collected)); }

void BadApple::setAvailable(bool _available)
{
  this->collected = !(_available);
}

int BadApple::getScoreValue(void) const { return (-50); }
bool BadApple::isWall(void) const { return (false); }
bool BadApple::canCollect(void) const { return (true); }
IObject::effect BadApple::getEffect(void) const { return (IObject::None); }
const RGBcolor &BadApple::getColor(void) const { return (this->color); }
