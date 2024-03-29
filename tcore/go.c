/*
** go.c for wolf3d in /home/VEYSSI_B/rendu/gfx_wolf3d
**
** Made by Baptiste veyssiere
** Login   <VEYSSI_B@epitech.net>
**
** Started on  Mon Dec 14 20:20:56 2015 Baptiste veyssiere
** Last update Sun Dec 27 21:02:16 2015 Baptiste veyssiere
*/

#include <lapin.h>

void	go(t_bunny_position *curpos, double angle,
	   t_bunny_position *newpos, int move)
{
  newpos->x = curpos->x + move * cos(angle);
  newpos->y = curpos->y + move * sin(angle);
}
