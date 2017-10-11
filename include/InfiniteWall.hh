//
// InfiniteWall.hh for  in /home/zwertv_e/rendu/cpp_nibbler
// 
// Made by zwertv_e
// Login   <zwertv_e@epitech.net>
// 
// Started on  Sun Apr  5 23:28:13 2015 zwertv_e
// Last update Sun Apr  5 23:28:34 2015 zwertv_e
//

#ifndef INFINITEWALL_H__
# define INFINITEWALL_H__

# include "IDisplayNibbler.hh"
# include "IObject.hh"

class InfiniteWall : public IObject
{
private:
  int x;
  int y;
  int life;
  bool collected;
  RGBcolor color;

public:
  InfiniteWall(int _x, int _y);
  virtual ~InfiniteWall(void);

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
