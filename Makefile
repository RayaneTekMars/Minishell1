##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

SRC	=	src/main.c			\
		src/exec.c			\
		src/error_exec.c		\
		src/command.c		\
		src/my_access.c		\
		src/clean_str.c		\
		src/get_next_line.c	\
		src/cd.c		\
		src/builtins.c		\
		src/setenv.c	\
		src/unsetenv.c	\
		lib/my_atoi.c	\
		lib/my_free_array.c	\
		lib/my_putchar.c	\
		lib/my_putnbr.c	\
		lib/my_putstr_error.c	\
		lib/my_putstr.c	\
		lib/my_str_to_word_array.c	\
		lib/my_strcat_va.c	\
		lib/my_strcat.c	\
		lib/my_strcmp.c	\
		lib/my_strdup.c	\
		lib/my_strlen_array.c	\
		lib/my_strlen.c	\
		lib/my_strncmp.c \
		lib/my_strcpy.c

OBJ	=	$(SRC:.c=.o)

NAME	=	mysh

all:	$(NAME) clean

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(OBJ)

clean:
		rm -f $(OBJ)
		cd src/ && rm -f $(OBJ)$

fclean:		clean
		rm -f $(NAME)
		cd src/ && rm -f $(OBJ)$

re:	fclean all

.PHONY : all clean fclean re
