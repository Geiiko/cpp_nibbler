//
// IObject.hh for  in /home/zwertv_e/rendu/cpp_nibbler
// 
// Made by zwertv_e
// Login   <zwertv_e@epitech.net>
// 
// Started on  Sun Apr  5 16:45:43 2015 zwertv_e
// Last update Sun Apr  5 20:16:30 2015 zwertv_e
//

#ifndef IOBJECT_H__
# define IOBJECT_H__

# include "IDisplayNibbler.hh"

class IObject
{
public:
  enum effect
    {
      Grow,
      Shrink,
      SpeedUp,
      SpeedDown,
      None
    };

public:
  virtual ~IObject() {}

public:
  virtual int getPosX(void) const = 0;
  virtual int getPosY(void) const = 0;
  virtual void lifeCycle(void) = 0;
  virtual int isAvailable(void) const = 0;
  virtual void setAvailable(bool _available) = 0;
  virtual int getScoreValue(void) const = 0;
  virtual bool isWall(void) const = 0;
  virtual bool canCollect(void) const = 0;
  virtual IObject::effect getEffect(void) const = 0;
  virtual const RGBcolor &getColor(void) const = 0;
};

#endif
