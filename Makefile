##
## Makefile for minishell1 in /home/costa_d/Documents/minishell1
## 
## Made by Arnaud Costa
## Login   <costa_d@epitech.net>
## 
## Started on  Tue Jan 19 18:40:20 2016 Arnaud Costa
## Last update Tue Apr 12 23:07:35 2016 Arnaud Costa
##

CC	= gcc

RM	= rm -rf

NAME	= mysh

CFLAGS	= -Wall -Wextra -ansi -Iinclude

SRC	= src/main.c \
	  src/tools.c \
	  src/get_next_line.c \
	  src/my_str_to_worldtab.c \
	  src/parce_env.c \
	  src/get_commande.c \
	  src/update_path.c \
	  src/exec_bin.c \
	  src/exec_bin_pip.c \
	  src/find_builtins.c \
	  src/get_env.c \
	  src/free_tab.c \
	  src/tools_error.c \
	  src/exec_relative_path.c \
	  src/my_memset.c \
	  src/my_strncmp.c \
	  src/my_unsetenv.c \
	  src/my_setenv.c \
	  src/my_strcpy.c \
	  src/minishell_manager.c \
	  src/tab_maker.c \
	  src/my_getnbr.c \
	  src/pip_manager.c \
	  src/update_path_tmp.c \
	  src/accessing.c \
	  src/pwd_manager.c \
	  src/mini_line.c \

OBJ	= $(SRC:.c=.o)

$(NAME): $(OBJ)
	 $(CC) $(OBJ) -o $(NAME) 

all:	  $(NAME)

clean:
	  $(RM) $(OBJ)

fclean:		clean
	  $(RM) $(NAME)

re:	  fclean all

.PHONY:	  all clean fclean re
