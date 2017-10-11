//
// SdlError.cpp for  in /home/degand/Projects/cpp_nibbler/lib/SDL/src
// 
// Made by Alaric
// Login   <degand@epitech.net>
// 
// Started on  Sun Apr  5 22:12:38 2015 Alaric
// Last update Sun Apr  5 22:13:12 2015 Alaric
//

#include "SdlError.hh"

SdlError::SdlError(const std::string _msg) : msg(_msg) {}

SdlError::~SdlError(void) throw() {}

const char *SdlError::what(void) const throw()
{
  return (this->msg.c_str());
}
