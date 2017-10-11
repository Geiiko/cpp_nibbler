//
// NibblerParser.hh for  in /home/zwertv_e/rendu/cpp_nibbler/include
// 
// Made by zwertv_e
// Login   <zwertv_e@epitech.net>
// 
// Started on  Sun Apr  5 20:20:41 2015 zwertv_e
// Last update Sun Apr  5 20:24:02 2015 zwertv_e
//

#ifndef NIBBLERPARSER_H__
# define NIBBLERPARSER_H__

# include <exception>
# include "INibblerError.hh"

class NibblerParser
{
public:
  NibblerParser();
  ~NibblerParser();

public:
  void parseArg(int argc, char **argv) const;
};

#endif
