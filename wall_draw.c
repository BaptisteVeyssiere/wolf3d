/*
** wall_draw.c for wolf3d in /home/VEYSSI_B/rendu/gfx_wolf3d
**
** Made by Baptiste veyssiere
** Login   <VEYSSI_B@epitech.net>
**
** Started on  Sat Dec 12 18:45:55 2015 Baptiste veyssiere
** Last update Wed Dec 16 19:50:01 2015 Baptiste veyssiere
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
  t_color		color[4];

  x = 0;
  k = 0;
  coord.x = 0;
  coord.y = 0;
  size.wall = 0;
  size.sky_floor = 0;
  color[0].full = 0xFEB577;
  color[1].full = 0xAEAEAE;
  color[2].full = 0x606060;
  color[3].full = 0x303030;
  while (x < WIDTH)
    {
      pos.x = x;
      pos.y = 0;
      get_intersection_coord(ptr, &coord, x);
      found_k_min(ptr, coord, &k);
      get_sizes(k, &size);
      i = 1;
      while (i < size.sky_floor)
	{
	  tekpixel(ptr->pix, &pos, &color[0]);
	  pos.y += 1;
	  i += 1;
	}
      tekpixel(ptr->pix, &pos, &color[3]);
      pos.y += 1;
      i = 1;
      while (i < (size.wall - 2))
	{
	  tekpixel(ptr->pix, &pos, &color[1]);
          pos.y += 1;
          i += 1;
	}
      tekpixel(ptr->pix, &pos, &color[3]);
      pos.y += 1;
      i = 1;
      while (i < size.sky_floor)
	{
	  tekpixel(ptr->pix, &pos, &color[2]);
          pos.y += 1;
          i += 1;
	}
      x += 1;
    }
}
