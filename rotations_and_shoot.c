/*
** rotations_and_shoot.c for wolf3d in /home/VEYSSI_B/rendu/gfx_wolf3d
**
** Made by Baptiste veyssiere
** Login   <VEYSSI_B@epitech.net>
**
** Started on  Fri Dec 25 17:57:44 2015 Baptiste veyssiere
** Last update Fri Dec 25 18:21:00 2015 Baptiste veyssiere
*/

#include "wolf3d.h"

void	rotate_left(t_refresh *ptr, t_bunny_event_state state)
{
  if (state == GO_DOWN)
    ptr->move->angle = (M_PI / 40);
  else
    ptr->move->angle = 0;
}

void	rotate_right(t_refresh *ptr, t_bunny_event_state state)
{
  if (state == GO_DOWN)
    ptr->move->angle = -(M_PI / 40);
  else
    ptr->move->angle = 0;
}

void	shoot(t_refresh *ptr, t_bunny_event_state state)
{
  if (ptr->shotgun_counter == 0 && state == GO_DOWN)
    {
      ptr->shotgun_counter = 1;
      bunny_sound_play(ptr->shot_sound);
    }
}
