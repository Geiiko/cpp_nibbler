//
// Spicke.cpp for  in /home/zwertv_e/rendu/cpp_nibbler
// 
// Made by zwertv_e
// Login   <zwertv_e@epitech.net>
// 
// Started on  Sun Apr  5 23:17:39 2015 zwertv_e
// Last update Sun Apr  5 23:24:04 2015 zwertv_e
//

#include "IObject.hh"
#include "Spicke.hh"

Spicke::Spicke(int _x, int _y) : x(_x), y(_y)
{
  this->color.r = 100;
  this->color.g = 100;
  this->color.b = 250;
  this->color.disp = 'S';
  this->collected = false;
  this->life = 50;
}
Spicke::~Spicke(void) {}

int Spicke::getPosX(void) const { return (this->x); }
int Spicke::getPosY(void) const { return (this->y); }
void Spicke::lifeCycle(void)
{
  --this->life;
  if (life == 0)
    this->collected = true;
}
int Spicke::isAvailable(void) const { return (!(this->collected)); }

void Spicke::setAvailable(bool _available)
{
  this->collected = !(_available);
}

int Spicke::getScoreValue(void) const { return (-90); }
bool Spicke::isWall(void) const { return (false); }
bool Spicke::canCollect(void) const { return (true); }
IObject::effect Spicke::getEffect(void) const { return (IObject::Shrink); }
const RGBcolor &Spicke::getColor(void) const { return (this->color); }
