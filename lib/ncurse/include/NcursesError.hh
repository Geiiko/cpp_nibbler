//
// NcursesError.hh for  in /home/zwertv_e/rendu/cpp_nibbler/lib/ncurse/include
// 
// Made by zwertv_e
// Login   <zwertv_e@epitech.net>
// 
// Started on  Sun Apr  5 21:27:53 2015 zwertv_e
// Last update Sun Apr  5 21:28:29 2015 zwertv_e
//

#ifndef NCURSESERROR_H__
# define NCURSESERROR_H__

# include <exception>
# include <string>
# include "INibblerError.hh"

class NcursesError : public INibblerError
{
private:
  std::string msg;

public:
  NcursesError(const std::string _msg);
  virtual ~NcursesError(void) throw();

public:
  virtual const char *what(void) const throw();
};

#endif
