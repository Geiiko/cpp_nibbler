//
// Spicke.hh for  in /home/zwertv_e/rendu/cpp_nibbler
// 
// Made by zwertv_e
// Login   <zwertv_e@epitech.net>
// 
// Started on  Sun Apr  5 23:20:17 2015 zwertv_e
// Last update Sun Apr  5 23:20:36 2015 zwertv_e
//

#ifndef SPICKE_H__
# define SPICKE_H__

# include "IDisplayNibbler.hh"
# include "IObject.hh"

class Spicke : public IObject
{
private:
  int x;
  int y;
  int life;
  bool collected;
  RGBcolor color;

public:
  Spicke(int _x, int _y);
  virtual ~Spicke(void);

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
