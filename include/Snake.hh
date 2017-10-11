//
// Snake.hh for  in /home/zwertv_e/rendu/cpp_nibbler/include
// 
// Made by zwertv_e
// Login   <zwertv_e@epitech.net>
// 
// Started on  Thu Apr  2 15:37:52 2015 zwertv_e
// Last update Sun Apr  5 23:22:05 2015 zwertv_e
//

#ifndef SNAKE_H__
# define SNAKE_H__

# include <vector>
# include "ICharacter.hh"

class Snake : public ICharacter
{
private:
  std::vector<int> posX;
  std::vector<int> posY;
  int size;
  ICharacter::direction direction;
  int speed;
  RGBcolor color;

public:
  Snake(int _x, int _y, int _size, int _speed);
  ~Snake(void);

private:
  virtual void moveLeft(void);
  virtual void moveRight(void);
  virtual void moveUp(void);
  virtual void moveDown(void);

public:
  virtual void move(void);
  virtual void turnLeft(void);
  virtual void turnRight(void);

public:
  virtual void grow(void);
  virtual void shrink(void);

public:
  virtual int getPosX(int _elem) const;
  virtual int getPosY(int _elem) const;
  virtual int getSize(void) const;
  virtual int getSpeed(void) const;
  virtual void setSpeed(int _speed);
  virtual ICharacter::direction getDir(void) const;
  virtual bool isAlive(void) const;
  virtual const RGBcolor &getColor(void) const;
};

#endif
