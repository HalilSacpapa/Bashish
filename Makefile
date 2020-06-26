##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## a file that make
##

RM	=	rm -f

CC	=	gcc

NAME	=	bashish

SRC	=	src/basic_fun2.c	\
		src/basic_fun.c	\
		src/check_fun.c	\
		src/clean_str.c	\
		src/env_fun.c	\
		src/exec_prog.c	\
		src/main.c	\
		src/prompt_color.c	\
		src/user_name.c	\
		src/malloc_free.c	\
		src/my_cd.c	\
		src/my_gnl.c	\
		src/path_dir.c	\
		src/str_to_word_tab.c	\
		src/sys_cmd.c	\
		src/path_cmd.c	\
		src/mult_usage.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-Wall -Wextra -W -g3 -Iinclude

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean:
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
