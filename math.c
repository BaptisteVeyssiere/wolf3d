/*
** math.c for wolf3d in /home/VEYSSI_B/rendu/gfx_wolf3d
**
** Made by Baptiste veyssiere
** Login   <VEYSSI_B@epitech.net>
**
** Started on  Fri Dec 11 12:03:00 2015 Baptiste veyssiere
** Last update Sun Dec 13 15:24:09 2015 Baptiste veyssiere
*/

#include "prototypes.h"

void	radian(double *angle)
{
  *angle = (M_PI * *angle) / 180;
}

void	rotation_translation(t_coord *coord, double angle, t_pov *perso, float x)
{
  coord->x = 0.5;
  coord->y = (WIDTH / 2 - x) / WIDTH;
  coord->x = acos(angle) - asin(angle);
  coord->x += perso->pos.x;
  coord->y = asin(angle) + acos(angle);
  coord->y += perso->pos.y;
}
