##
## Makefile for wolf3d in /home/VEYSSI_B/rendu/gfx_wolf3d
##
## Made by Baptiste veyssiere
## Login   <VEYSSI_B@epitech.net>
##
## Started on  Thu Dec 10 15:43:10 2015 Baptiste veyssiere
## Last update Thu Dec 17 11:30:00 2015 Baptiste veyssiere
##

CFLAGS	= -W -Wall -Werror -ansi -pedantic -I./include \
	-I/home/${USER}/.froot/include

LDFLAGS	= -L/home/${USER}/.froot/lib \
	-llapin -lsfml-audio -lsfml-graphics \
	-lsfml-window -lsfml-system -lstdc++ -ldl -lm

CC	= gcc

RM	= rm -f

NAME	= wolf3d

SRCS	= wolf3d.c \
	get_ini_data.c \
	my_getnbr.c \
	math.c \
	wall_size_calculator.c \
	wall_draw.c \
	tekpixel.c \
	moving.c \
	go.c \
	music.c

OBJS	= $(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(CC) -g -o $(NAME) $(OBJS) $(LDFLAGS)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
