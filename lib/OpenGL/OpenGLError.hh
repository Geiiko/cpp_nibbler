//
// OpenGLError.hh for  in /home/dubell_g/rendu/cpp_nibbler/lib/OpenGL
// 
// Made by dubell_g
// Login   <dubell_g@epitech.net>
// 
// Started on  Sun Apr  5 21:50:44 2015 dubell_g
// Last update Sun Apr  5 22:05:11 2015 dubell_g
//

#ifndef		_OPENGLERROR_HH_
# define	_OPENGLERROR_HH_

# include	<exception>
# include	<string>
# include	"INibblerError.hh"

class		OpenGLError : public INibblerError
{
private:
  std::string	msg;

public:
  OpenGLError(const std::string _msg);
  virtual ~OpenGLError(void) throw();

  virtual const char	*what(void) const throw();
};

#endif		/* !_OPENGLERROR_HH_ */
