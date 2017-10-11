//
// ICharacter.hh for  in /home/zwertv_e/rendu/cpp_nibbler/include
// 
// Made by zwertv_e
// Login   <zwertv_e@epitech.net>
// 
// Started on  Tue Mar 31 17:23:34 2015 zwertv_e
// Last update Sun Apr  5 23:21:53 2015 zwertv_e
//

#ifndef ICHARACTER_H__
# define ICHARACTER_H__

# include "IDisplayNibbler.hh"

class ICharacter
{
public:
  enum direction
    {
      Left,
      Right,
      Up,
      Down
    };

public:
  virtual ~ICharacter(void) {}

protected: // Deplacements
  virtual void moveLeft(void) = 0;
  virtual void moveRight(void) = 0;
  virtual void moveUp(void) = 0;
  virtual void moveDown(void) = 0;

public: // Rotations
  virtual void move(void) = 0;
  virtual void turnLeft(void) = 0;
  virtual void turnRight(void) = 0;

public: // effets
  virtual void grow(void) = 0;
  virtual void shrink(void) = 0;

public:
  virtual int getPosX(int _elem) const = 0;
  virtual int getPosY(int _elem) const = 0;
  virtual int getSize(void) const = 0;
  virtual int getSpeed(void) const = 0;
  virtual void setSpeed(int _speed) = 0;
  virtual ICharacter::direction getDir(void) const = 0;
  virtual bool isAlive(void) const = 0;
  virtual const RGBcolor &getColor(void) const = 0;
};

#endif
