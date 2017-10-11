##
## Makefile for  in /home/dubell_g/rendu/cpp_nibbler/lib/OpenGL
## 
## Made by dubell_g
## Login   <dubell_g@epitech.net>
## 
## Started on  Sun Apr  5 17:30:42 2015 dubell_g
## Last update Sun Apr  5 22:48:03 2015 dubell_g
##

NAME		=	lib_nibbler_OpenGL.so

FILES		=	DisplayOpenGL.cpp \
			OpenGLError.cpp
SRC		=	${FILES}

CXX		=	g++

CXXFLAGS	+=	-W -Wall -Wextra -fPIC -I../../include -Iinclude
LDFLAGS		+=	-shared -lSDL -lSDLmain -lGL -lGLU

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
			g++ test.cpp -Iinclude -I../../include -ldl -o test -g -lSDL -lSDLmain -lGL -lGLU
