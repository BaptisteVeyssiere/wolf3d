/*
** directions.c for wolf3d in /home/VEYSSI_B/rendu/gfx_wolf3d
**
** Made by Baptiste veyssiere
** Login   <VEYSSI_B@epitech.net>
**
** Started on  Fri Dec 25 17:56:26 2015 Baptiste veyssiere
** Last update Fri Dec 25 18:19:44 2015 Baptiste veyssiere
*/

#include "wolf3d.h"

void	up(t_refresh *ptr, t_bunny_event_state state)
{
  if (state == GO_DOWN)
    ptr->move->y = 0.025;
  else
    ptr->move->y = 0;
}

void	down(t_refresh *ptr, t_bunny_event_state state)
{
  if (state == GO_DOWN)
    ptr->move->y = -0.025;
  else
    ptr->move->y = 0;
}

void	left(t_refresh *ptr, t_bunny_event_state state)
{
  if (state == GO_DOWN)
    ptr->move->x = 0.025;
  else
    ptr->move->x = 0;
}

void	right(t_refresh *ptr, t_bunny_event_state state)
{
  if (state == GO_DOWN)
    ptr->move->x = -0.025;
  else
    ptr->move->x = 0;
}
