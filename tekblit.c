/*
** tekblit.c for wolf3d in /home/VEYSSI_B/rendu/gfx_wolf3d
**
** Made by Baptiste veyssiere
** Login   <VEYSSI_B@epitech.net>
**
** Started on  Wed Dec 23 11:46:32 2015 Baptiste veyssiere
** Last update Fri Dec 25 00:39:03 2015 Baptiste veyssiere
*/

#include "wolf3d.h"

void		tekblit(t_bunny_pixelarray *pix, t_bunny_pixelarray *sprite,
			const t_bunny_position *position)
{
  int		i;
  int		j;
  int		k;
  t_color	*color_pix;
  t_color	*color_sprite;

  i = position->y;
  k = 0;
  color_pix = pix->pixels;
  color_sprite = sprite->pixels;
  while (i < (position->y + sprite->clipable.clip_height))
    {
      j = position->x;
      while (j < (position->x + sprite->clipable.clip_width))
	{
	  if (color_sprite[k].argb[3] != 0)
	    color_pix[(i * WIDTH) + j].full = color_sprite[k].full;
	  ++k;
	  ++j;
	}
      ++i;
    }
}
