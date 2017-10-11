//
// INibblerError.hh for  in /home/zwertv_e/rendu/cpp_nibbler/include
// 
// Made by zwertv_e
// Login   <zwertv_e@epitech.net>
// 
// Started on  Sun Apr  5 06:23:10 2015 zwertv_e
// Last update Sun Apr  5 16:39:21 2015 zwertv_e
//

#ifndef INIBBLERERROR_H__
# define INIBBLERERROR_H__

# include <exception>

class INibblerError : public std::exception
{
public:
  virtual ~INibblerError(void) throw() {}

public:
  virtual const char *what(void) const throw() = 0;
};

#endif
