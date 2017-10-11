//
// NcursesError.cpp for  in /home/zwertv_e/rendu/cpp_nibbler/lib/ncurse/src
// 
// Made by zwertv_e
// Login   <zwertv_e@epitech.net>
// 
// Started on  Sun Apr  5 21:27:13 2015 zwertv_e
// Last update Sun Apr  5 21:30:11 2015 zwertv_e
//

#include "NcursesError.hh"

NcursesError::NcursesError(const std::string _msg) : msg(_msg) {}

NcursesError::~NcursesError(void) throw() {}

const char *NcursesError::what(void) const throw()
{
  return (this->msg.c_str());
}
