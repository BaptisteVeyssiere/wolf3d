/*
** moving.c for wolf3d in /home/VEYSSI_B/rendu/gfx_wolf3d
**
** Made by Baptiste veyssiere
** Login   <VEYSSI_B@epitech.net>
**
** Started on  Mon Dec 14 20:30:27 2015 Baptiste veyssiere
** Last update Fri Dec 25 16:25:52 2015 Baptiste veyssiere
*/

#include "wolf3d.h"

void	move_calc(t_refresh *ptr, t_coord *newpos, t_coord *newpos_2)
{
  if (ptr->move->y)
    go(&(ptr->perso->pos), ANGLE, newpos, ptr->move->y);
  if (ptr->move->x)
    go(&(ptr->perso->pos), (ANGLE + M_PI / 2), newpos_2, ptr->move->x);
  if (newpos->x && newpos_2->x)
    newpos->x += (newpos_2->x - X0);
  else
    newpos->x += newpos_2->x;
  if (newpos->y && newpos_2->y)
    newpos->y += (newpos_2->y - Y0);
  else
    newpos->y += newpos_2->y;
}

void	moving(t_refresh *ptr)
{
  t_coord	newpos;
  t_coord	newpos_2;

  newpos.x = 0;
  newpos.y = 0;
  newpos_2.x = 0;
  newpos_2.y = 0;
  if (ptr->move->x != 0 || ptr->move->y != 0)
    {
      move_calc(ptr, &newpos, &newpos_2);
      if (newpos.x < (ptr->width - 1) && newpos.x > 0 &&
	  newpos.y > 0 && newpos.y
	  < (ptr->height - 1) && ptr->map[(int)newpos.y][(int)newpos.x] == 0)
	{
	  X0 = newpos.x;
	  Y0 = newpos.y;
	}
      else if (ptr->map[(int)newpos.y][(int)X0] == 0)
	Y0 = newpos.y;
      else if (ptr->map[(int)Y0][(int)newpos.x] == 0)
	X0 = newpos.x;
    }
}

void	angle_rotation(t_refresh *ptr)
{
  if (ptr->move->angle != 0)
    ANGLE += ptr->move->angle;
}
