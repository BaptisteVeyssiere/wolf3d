/*
** go.c for wolf3d in /home/VEYSSI_B/rendu/gfx_wolf3d
**
** Made by Baptiste veyssiere
** Login   <VEYSSI_B@epitech.net>
**
** Started on  Mon Dec 14 20:20:56 2015 Baptiste veyssiere
** Last update Wed Dec 23 12:13:07 2015 Baptiste veyssiere
*/

#include "wolf3d.h"

void	go(t_coord *curpos, double angle, t_coord *newpos, float move)
{
  newpos->x = curpos->x + move * cos(angle);
  newpos->y = curpos->y + move * sin(angle);
}
