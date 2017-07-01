##
## Makefile for  in /home/tbesson/Piscine_synthese/ADM_calendar_2016
## 
## Made by Tamsi Besson
## Login   <tbesson@epitech.net>
## 
## Started on  Fri Jun 30 11:31:15 2017 Tamsi Besson
## Last update Sat Jul  1 15:49:35 2017 Tamsi Besson
##

CFLAGS	+= -I./include
CFLAGS	+= -Wall -Wextra -Werror

SRC	= main.c			\
	  requirement.c			\
	  src/my_str_to_wordtab.c	\
	  src/wordtab_tools.c		\
	  src/fill.c 			\
	  src/employee.c		\
	  src/employee_tools.c		\
	  src/meeting.c			\

OBJ	= $(SRC:.c=.o)

NAME	= calendar

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	rm -f $(NAME)

fclean: clean
	rm -f $(OBJ)

re: fclean all

.PHONY: all clean fclean re
