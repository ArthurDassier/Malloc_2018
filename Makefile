##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

NAME	=	libmy_malloc.so

CC	=	gcc -std=c99 -std=gnu99

MAKE	=	/usr/bin/make

SRC_DIR	=	./srcs

BUILTINS	=$(SRC_DIR)/builtins

EXTRA		=$(SRC_DIR)/extra

HISTORY_DIR =	$(SRC_DIR)/history/

VAR_DIR	=	$(SRC_DIR)/variables/

LIB_DIR	=	./lib/my

UT_DIR	=	./tests

LIB_DIR	=	./lib/my

EXE	=	$(SRC_DIR)/main.c		\
		$(SRC_DIR)/alloc.c		\
		$(SRC_DIR)/algo.c		\
		$(SRC_DIR)/tools.c		\
		$(SRC_DIR)/interface.c	\

OBJ	=	$(EXE:.c=.o)

UT 	= 	$(UT_DIR)/malloc_tests.c		\
		$(UT_DIR)/realloc_tests.c		\
		$(UT_DIR)/calloc_tests.c		\
		$(UT_DIR)/start_mem_tests.c		\

UT2	=	$(SRC_DIR)/main.c		\
		$(SRC_DIR)/alloc.c		\
		$(SRC_DIR)/algo.c		\
		$(SRC_DIR)/tools.c		\

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
		$(CC) $(INCLUDE) -o UT $(UT) $(UT2) -lcriterion -coverage
		./UT

clean:
		$(RM) $(OBJ)

ut_clean:
		rm *.gc*
		rm UT

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		re all fclean clean
