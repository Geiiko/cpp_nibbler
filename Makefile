##
## Makefile for  in /home/zwertv_e/rendu/cpp_nibbler
## 
## Made by zwertv_e
## Login   <zwertv_e@epitech.net>
## 
## Started on  Sun Apr  5 20:50:39 2015 zwertv_e
## Last update Sun Apr  5 23:41:38 2015 zwertv_e
##

NAME		=	nibbler

FOLDER		=	src/
FILES		=	${FOLDER}main.cpp		\
			${FOLDER}GameSolo.cpp		\
			${FOLDER}Snake.cpp		\
			${FOLDER}SnakeRT.cpp		\
			${FOLDER}NibblerError.cpp	\
			${FOLDER}Apple.cpp		\
			${FOLDER}BadApple.cpp		\
			${FOLDER}Chicken.cpp		\
			${FOLDER}BlackHole.cpp		\
			${FOLDER}Wall.cpp		\
			${FOLDER}InfiniteWall.cpp	\
			${FOLDER}Spicke.cpp		\
			${FOLDER}NibblerParser.cpp

SRC		=	${FILES}

OBJ		=	$(SRC:.cpp=.o)

CXX		=	g++

CXXFLAGS	+=	-Iinclude -W -Wall
LDFLAGS		+=	-ldl

ifeq ($(DEBUG),1)
CXXFLAGS	+=	-g
endif

ifeq ($(CXX),clang++)
CXXFLAGS	+=	-Weverything -Wno-padded
endif

all::			$(NAME)

$(NAME):		$(OBJ)
			$(CXX) -o $(NAME) $(OBJ) $(LDFLAGS)

clean::
			@rm -f $(NAME)

fclean::		clean
			@rm -f $(OBJ)

re::			fclean	all

.PHONY:			all	clean	fclean	re

##
## Règles communes
##

all::
	cd ./lib/ncurse && make
	cd ./lib/SDL && make
	cd ./lib/OpenGL && make

clean::
	cd ./lib/ncurse && make clean
	cd ./lib/SDL && make clean
	cd ./lib/OpenGL && make clean

fclean::
	cd ./lib/ncurse && make fclean
	cd ./lib/SDL && make fclean
	cd ./lib/OpenGL && make fclean

re::
	cd ./lib/ncurse && make re
	cd ./lib/SDL && make re
	cd ./lib/OpenGL && make re
