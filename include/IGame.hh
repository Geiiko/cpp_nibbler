//
// IGame.hh for  in /home/zwertv_e/rendu/cpp_nibbler/include
// 
// Made by zwertv_e
// Login   <zwertv_e@epitech.net>
// 
// Started on  Thu Apr  2 17:55:03 2015 zwertv_e
// Last update Sun Apr  5 19:13:02 2015 zwertv_e
//

#ifndef IGAME_H__
# define IGAME_H__

class IGame
{
public:
  enum GameType
    {
      Quit = 0,
      GameSolo
    };

public:
  virtual ~IGame(void) {}

public:
  virtual void runGame(void) = 0;
  virtual bool loadChars(void) = 0;
  virtual void displayChar(void) = 0;
  virtual void displayObjects(void) = 0;
  virtual bool collectObjects(void) = 0;
};

#endif
