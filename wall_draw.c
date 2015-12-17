/*
** wall_draw.c for wolf3d in /home/VEYSSI_B/rendu/gfx_wolf3d
**
** Made by Baptiste veyssiere
** Login   <VEYSSI_B@epitech.net>
**
** Started on  Sat Dec 12 18:45:55 2015 Baptiste veyssiere
** Last update Thu Dec 17 16:20:03 2015 Baptiste veyssiere
*/

#include "prototypes.h"
#include <stdio.h>

void			wall_draw(t_refresh *ptr)
{
  int			x;
  int			i;
  t_inter_dist		k;
  t_coord		coord;
  t_size		size;
  t_bunny_position	pos;
  t_color		color[7];

  x = 0;
  coord.x = 0;
  coord.y = 0;
  size.wall = 0;
  size.sky_floor = 0;
  color[0].full = 0xFEB577;
  color[1].full = 0xB8B8B8;
  color[2].full = 0xAEAEAE;
  color[3].full = 0xA4A4A4;
  color[4].full = 0x9A9A9A;
  color[5].full = 0x606060;
  color[6].full = 0x303030;
  while (x < WIDTH)
    {
      k.dist = 0;
      k.x = 0;
      k.y = 0;
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
      tekpixel(ptr->pix, &pos, &color[6]);
      pos.y += 1;
      i = 1;
      while (i < (size.wall - 2))
	{
	  if (k.y < Y0 && k.y != 0)
	    tekpixel(ptr->pix, &pos, &color[1]);
	  else if (k.y >= Y0 && k.y != 0)
	    tekpixel(ptr->pix, &pos, &color[4]);
	  else if (k.x < X0 && k.x != 0)
	    tekpixel(ptr->pix, &pos, &color[2]);
	  else
	    tekpixel(ptr->pix, &pos, &color[3]);
          pos.y += 1;
          i += 1;
	}
      tekpixel(ptr->pix, &pos, &color[6]);
      pos.y += 1;
      i = 1;
      while (i < size.sky_floor)
	{
	  tekpixel(ptr->pix, &pos, &color[5]);
          pos.y += 1;
          i += 1;
	}
      x += 1;
    }
}
