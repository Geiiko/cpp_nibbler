//
// SDLError.hh for  in /home/degand/Projects/cpp_nibbler/lib/SDL/Include
// 
// Made by Alaric
// Login   <degand@epitech.net>
// 
// Started on  Sun Apr  5 22:09:03 2015 Alaric
// Last update Sun Apr  5 22:09:40 2015 Alaric
//

#ifndef SDLERROR_H__
# define SDLERROR_H__

# include <exception>
# include <string>
# include "INibblerError.hh"

class SdlError : public INibblerError
{
private:
  std::string msg;

public:
  SdlError(const std::string _msg);
  virtual ~SdlError(void) throw();

public:
  virtual const char *what(void) const throw();
};

#endif
