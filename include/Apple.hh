//
// Apple.hh for  in /home/zwertv_e/rendu/cpp_nibbler
// 
// Made by zwertv_e
// Login   <zwertv_e@epitech.net>
// 
// Started on  Sun Apr  5 16:53:43 2015 zwertv_e
// Last update Sun Apr  5 20:17:25 2015 zwertv_e
//

#ifndef APPLE_H__
# define APPLE_H__

# include "IDisplayNibbler.hh"
# include "IObject.hh"

class Apple : public IObject
{
private:
  int x;
  int y;
  int life;
  bool collected;
  RGBcolor color;

public:
  Apple(int _x, int _y);
  virtual ~Apple(void);

public:
  virtual int getPosX(void) const;
  virtual int getPosY(void) const;
  virtual void lifeCycle(void);
  virtual int isAvailable(void) const;
  virtual void setAvailable(bool _available);
  virtual int getScoreValue(void) const;
  virtual bool isWall(void) const;
  virtual bool canCollect(void) const;
  virtual IObject::effect getEffect(void) const;
  virtual const RGBcolor &getColor(void) const;
};

#endif
