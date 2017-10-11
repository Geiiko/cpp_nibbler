//
// OpenGLError.cpp for  in /home/dubell_g/rendu/cpp_nibbler/lib/OpenGL
// 
// Made by dubell_g
// Login   <dubell_g@epitech.net>
// 
// Started on  Sun Apr  5 21:54:33 2015 dubell_g
// Last update Sun Apr  5 21:56:12 2015 dubell_g
//

#include	"OpenGLError.hh"

OpenGLError::OpenGLError(const std::string _msg) : msg(_msg) {}

OpenGLError::~OpenGLError(void) throw() {}

const char	*OpenGLError::what(void) const throw()
{
  return (this->msg.c_str());
}
