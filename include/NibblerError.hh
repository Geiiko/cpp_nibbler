//
// NibblerError.hh for  in /home/zwertv_e/rendu/cpp_nibbler/include
// 
// Made by zwertv_e
// Login   <zwertv_e@epitech.net>
// 
// Started on  Sun Apr  5 06:27:36 2015 zwertv_e
// Last update Sun Apr  5 06:33:44 2015 zwertv_e
//

#ifndef NIBBLERERROR_H__
# define NIBBLERERROR_H__

# include <exception>
# include <string>
# include "INibblerError.hh"

class NibblerError : public INibblerError
{
private:
  std::string msg;

public:
  NibblerError(const std::string _msg);
  virtual ~NibblerError(void) throw();

public:
  virtual const char *what(void) const throw();
};

#endif
