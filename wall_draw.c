/*
** wall_draw.c for wolf3d in /home/VEYSSI_B/rendu/gfx_wolf3d
**
** Made by Baptiste veyssiere
** Login   <VEYSSI_B@epitech.net>
**
** Started on  Sat Dec 12 18:45:55 2015 Baptiste veyssiere
** Last update Sun Dec 13 19:52:22 2015 Baptiste veyssiere
*/

#include "prototypes.h"
#include <stdio.h>

void			wall_draw(t_refresh *ptr)
{
  int			x;
  int			i;
  float			k;
  t_coord		coord;
  t_size		size;
  t_bunny_position	pos;
  t_color		color[3];

  x = 0;
  k = 0;
  color[0].full = 0xFF0000;
  color[1].full = 0xAAAAAA;
  color[2].full = 0x202020;
  while (x < WIDTH)
    {
      pos.x = x;
      pos.y = 0;
      i = 1;
      get_intersection_coord(ptr, &coord, x);
      found_k_min(ptr, coord, &k);
      get_sizes(k, &size);
      while (i < size.sky_floor)
	{
	  tekpixel(ptr->pix, &pos, &color[0]);
	  pos.y++;
	  i++;
	}
      i = 1;
      while (i < size.wall)
	{
	  tekpixel(ptr->pix, &pos, &color[1]);
          pos.y++;
          i++;
	}
      i = 1;
      while (i < size.sky_floor)
	{
	  tekpixel(ptr->pix, &pos, &color[2]);
          pos.y++;
          i++;
	}
      x++;
    }
}
