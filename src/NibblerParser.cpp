//
// NibblerParser.cpp for  in /home/zwertv_e/rendu/cpp_nibbler/include
// 
// Made by zwertv_e
// Login   <zwertv_e@epitech.net>
// 
// Started on  Sun Apr  5 20:22:11 2015 zwertv_e
// Last update Sun Apr  5 20:46:15 2015 zwertv_e
//

#include <string>
#include <cstdlib>
#include "NibblerParser.hh"
#include "NibblerError.hh"

NibblerParser::NibblerParser(void) {}
NibblerParser::~NibblerParser(void) {}

bool is_number(const std::string& s)
{
  std::string::const_iterator it = s.begin();
  while (it != s.end() && std::isdigit(*it)) ++it;
  return !s.empty() && it == s.end();
}

void	NibblerParser::parseArg(int argc, char **argv) const
{
  if (argc != 4)
    throw NibblerError("Wrong number of arguments");
  if (!is_number(std::string(argv[1])))
    throw NibblerError("First argument must be a valid positive integer");
  if (!is_number(std::string(argv[2])))
    throw NibblerError("Second argument must be a valid positive integer");
  if (atoi(argv[1]) < 12 || atoi(argv[2]) < 12)
    throw NibblerError("Game Area must be at least a 12 by 12 squarre");
}
