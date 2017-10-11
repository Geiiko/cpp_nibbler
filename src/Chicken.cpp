//
// Chicken.cpp for  in /home/zwertv_e/rendu/cpp_nibbler
// 
// Made by zwertv_e
// Login   <zwertv_e@epitech.net>
// 
// Started on  Sun Apr  5 22:32:35 2015 zwertv_e
// Last update Sun Apr  5 22:59:10 2015 zwertv_e
//

#include "IObject.hh"
#include "Chicken.hh"

Chicken::Chicken(int _x, int _y) : x(_x), y(_y)
{
  this->color.r = 245;
  this->color.g = 241;
  this->color.b = 222;
  this->color.disp = 'C';
  this->collected = false;
  this->life = 20;
}
Chicken::~Chicken(void) {}

int Chicken::getPosX(void) const { return (this->x); }
int Chicken::getPosY(void) const { return (this->y); }
void Chicken::lifeCycle(void)
{
  --this->life;
  if (life == 0)
    this->collected = true;
}
int Chicken::isAvailable(void) const { return (!(this->collected)); }

void Chicken::setAvailable(bool _available)
{
  this->collected = !(_available);
}

int Chicken::getScoreValue(void) const { return (-30); }
bool Chicken::isWall(void) const { return (false); }
bool Chicken::canCollect(void) const { return (true); }
IObject::effect Chicken::getEffect(void) const { return (IObject::SpeedDown); }
const RGBcolor &Chicken::getColor(void) const { return (this->color); }
