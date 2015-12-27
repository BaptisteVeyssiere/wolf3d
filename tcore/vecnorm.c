/*
** vecnorm.c for wolf3d in /home/VEYSSI_B/rendu/gfx_wolf3d
**
** Made by Baptiste veyssiere
** Login   <VEYSSI_B@epitech.net>
**
** Started on  Thu Dec 10 17:23:14 2015 Baptiste veyssiere
** Last update Sun Dec 27 21:05:51 2015 Baptiste veyssiere
*/

#include "wolf3d.h"

double	vecnorm(t_bunny_position *coord0, t_bunny_position *coord1)
{
  t_bunny_position	pos;
  double		norm;

  pos.x = coord1->x - coord0->x;
  pos.y = coord1->y - coord0->y;
  norm = sqrt(SQUARE(pos.x) + SQUARE(pos.y));
  return (norm);
}
