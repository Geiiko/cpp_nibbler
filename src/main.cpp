//
// main.cpp for  in /home/zwertv_e/rendu/cpp_nibbler/src
// 
// Made by zwertv_e
// Login   <zwertv_e@epitech.net>
// 
// Started on  Thu Mar 26 14:08:53 2015 zwertv_e
// Last update Sun Apr  5 21:40:48 2015 zwertv_e
//

#include	<exception>
#include	<iostream>
#include	<cstdlib>
#include	"IDisplayNibbler.hh"
#include	"SnakeRT.hh"
#include	"GameSolo.hh"
#include	"ICharacter.hh"
#include	"Snake.hh"
#include	"NibblerParser.hh"

int		main(int argc, char **argv)
{
  NibblerParser parse;
  SnakeRT	*rt;

  try
    {
      parse.parseArg(argc, argv);
      rt = new SnakeRT(argv[3]);
      if (!(rt->loadGame(atoi(argv[1]), atoi(argv[2]))))
	return (EXIT_SUCCESS);
      rt->loadChars();
      rt->runGame();
      delete (rt);
    }
  catch (const std::exception &e)
    {
      std::cerr << "Error: " << e.what() << std::endl;
      exit(EXIT_FAILURE);
    }
  return (EXIT_SUCCESS);
}
