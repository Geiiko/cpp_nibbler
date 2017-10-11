//
// Apple.cpp for  in /home/zwertv_e/rendu/cpp_nibbler
// 
// Made by zwertv_e
// Login   <zwertv_e@epitech.net>
// 
// Started on  Sun Apr  5 16:56:13 2015 zwertv_e
// Last update Sun Apr  5 22:58:53 2015 zwertv_e
//

#include "IObject.hh"
#include "Apple.hh"

Apple::Apple(int _x, int _y) : x(_x), y(_y)
{
  this->color.r = 255;
  this->color.g = 0;
  this->color.b = 0;
  this->color.disp = 'a';
  this->collected = false;
  this->life = -1;
}
Apple::~Apple(void) {}

int Apple::getPosX(void) const { return (this->x); }
int Apple::getPosY(void) const { return (this->x); }
void Apple::lifeCycle(void) {}
int Apple::isAvailable(void) const { return (!(this->collected)); }

void Apple::setAvailable(bool _available)
{
  this->collected = !(_available);
}

int Apple::getScoreValue(void) const { return (50); }
bool Apple::isWall(void) const { return (false); }
bool Apple::canCollect(void) const { return (true); }
IObject::effect Apple::getEffect(void) const { return (IObject::Grow); }
const RGBcolor &Apple::getColor(void) const { return (this->color); }
