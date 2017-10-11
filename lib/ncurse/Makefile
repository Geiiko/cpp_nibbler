##
## Makefile for  in /home/zwertv_e/rendu/cpp_nibbler/include
## 
## Made by zwertv_e
## Login   <zwertv_e@epitech.net>
## 
## Started on  Mon Mar 30 17:58:34 2015 zwertv_e
## Last update Sun Apr  5 21:29:54 2015 zwertv_e
##

NAME		=	lib_nibbler_ncurses.so

FOLDER		=	src/
FILES		=	${FOLDER}DisplayNcurses.cpp	\
			${FOLDER}NcursesError.cpp
SRC		=	${FILES}

CXX		=	g++

CXXFLAGS	+=	-W -Wall -Wextra -fPIC -I../../include -Iinclude
LDFLAGS		+=	-shared -lncurses

ifeq ($(DEBUG),1)
CXXFLAGS	+=	-g
endif

ifeq ($(CXX),clang++)
CXXFLAGS	+=	-Weverything
endif

OBJ		=	$(SRC:.cpp=.o)

all:			$(NAME)

$(NAME):		$(OBJ)
			$(CXX) -o $(NAME) $(OBJ) $(LDFLAGS)
			cp $(NAME) ../../

clean:
			@rm -f $(NAME)
			@rm -f ../../$(NAME)

fclean:			clean
			@rm -f $(OBJ)

re:			fclean	all

.PHONY:			all	clean	fclean	re	test

test:
			@rm -f test
			g++ test.cpp -Iinclude -I../../include -ldl -o test -g -lncurses
