# @Author: charlesR
# @Date:   2019-01-07T12:54:50+01:00
# @Last modified by:   charlesR
# @Last modified time: 2019-01-07T13:15:03+01:00



##
## EPITECH PROJECT, 2017
## corewar
## File description:
## Makefile
##

NAME	=	libmy_malloc.so

CC	=	gcc

MAKE	=	/usr/bin/make

SRC_DIR	=	./srcs

BUILTINS	=$(SRC_DIR)/builtins

EXTRA		=$(SRC_DIR)/extra

HISTORY_DIR =	$(SRC_DIR)/history/

VAR_DIR	=	$(SRC_DIR)/variables/

LIB_DIR	=	./lib/my

UT_DIR	=	./tests

LIB_DIR	=	./lib/my

EXE	=	$(SRC_DIR)/main.c\

OBJ	=	$(EXE:.c=.o)

UT 	= 	$(UT_DIR)/ut_cat.cpp\


UT2	=	main.cpp\
		cat.cpp

RM	=	rm -f

CFLAGS	=	#-W -Wall -Wextra -Wno-unused-variable -Wno-unused-parameter

CPPFLAGS=	-I./includes/

LDFLAGS	=

UT_FLAGS=	-lcriterion --coverage

INCLUDE	=	-I ./includes


all:		$(NAME)

$(NAME):
		gcc $(INCLUDE) -shared -fPIC $(EXE) -o $(NAME)

tests_run:
		$(CC) $(INCLUDE) -o $(NAME) $(UT) $(UT2) -lcriterion -coverage
		./$(NAME)

clean:
		$(RM) $(OBJ)

ut_clean:
		rm *gc*

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		re all fclean clean
