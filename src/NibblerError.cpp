//
// NibblerError.cpp for  in /home/zwertv_e/rendu/cpp_nibbler/include
// 
// Made by zwertv_e
// Login   <zwertv_e@epitech.net>
// 
// Started on  Sun Apr  5 06:29:33 2015 zwertv_e
// Last update Sun Apr  5 06:34:15 2015 zwertv_e
//

#include "NibblerError.hh"

NibblerError::NibblerError(const std::string _msg) : msg(_msg) {}

NibblerError::~NibblerError(void) throw() {}

const char *NibblerError::what(void) const throw()
{
  return (this->msg.c_str());
}
