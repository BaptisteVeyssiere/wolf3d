/*
** moving.c for wolf3d in /home/VEYSSI_B/rendu/gfx_wolf3d
**
** Made by Baptiste veyssiere
** Login   <VEYSSI_B@epitech.net>
**
** Started on  Mon Dec 14 20:30:27 2015 Baptiste veyssiere
** Last update Tue Dec 15 23:50:14 2015 Baptiste veyssiere
*/

#include "prototypes.h"
#include <stdio.h>

void	moving(t_refresh *ptr)
{
  t_coord	newpos;
  int		width;
  int		height;

  newpos.x = 0;
  newpos.y = 0;
  height = 0;
  width = 0;
  height = get_height(ptr->ini);
  width = get_width(ptr->ini);
  width = width;
  newpos = newpos;
  height = height;
  if (ptr->move->x != 0 || ptr->move->y != 0)
    {
      if (ptr->move->y)
	go(&(ptr->perso->pos), ANGLE, &newpos, ptr->move->y);
      else if (ptr->move->x)
	go(&(ptr->perso->pos), (ANGLE + M_PI / 2), &newpos, ptr->move->x);
      if (newpos.x < (width -1) && newpos.x > 0 && newpos.y > 0 && newpos.y < (height - 1) && ptr->map[(int)newpos.y][(int)newpos.x] == 0)
	{
	  printf("y = %f x = %f %d %d\n", newpos.y, newpos.x, (int)newpos.y, (int)newpos.x);
	  X0 = newpos.x;
	  Y0 = newpos.y;
	}
      ptr->move->x = 0;
      ptr->move->y = 0;
    }
}
