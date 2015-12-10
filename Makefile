##
## Makefile for wolf3d in /home/VEYSSI_B/rendu/gfx_wolf3d
##
## Made by Baptiste veyssiere
## Login   <VEYSSI_B@epitech.net>
##
## Started on  Thu Dec 10 15:43:10 2015 Baptiste veyssiere
## Last update Thu Dec 10 20:02:23 2015 Baptiste veyssiere
##

CFLAGS	= -W -Wall -Werror -ansi -pedantic -I./include -I/home/${USER}/.froot/include

LDFLAGS	= -L/home/${USER}/.froot/lib \
	-llapin -lsfml-audio -lsfml-graphics \
	-lsfml-window -lsfml-system -lstdc++ -ldl -lm

CC	= gcc

RM	= rm -f

NAME	= wolf3d

SRCS	= wolf3d.c \
	get_ini_data.c

OBJS	= $(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
