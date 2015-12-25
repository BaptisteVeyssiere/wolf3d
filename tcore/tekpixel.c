/*
** my_set_line.c for fdf1 in /home/VEYSSI_B/rendu/gfx_fdf1
**
** Made by Baptiste veyssiere
** Login   <VEYSSI_B@epitech.net>
**
** Started on  Wed Nov 18 12:51:14 2015 Baptiste veyssiere
** Last update Sun Nov 22 20:57:46 2015 Baptiste veyssiere
*/

#include <lapin.h>
#include "my.h"

void	tekpixel(t_bunny_pixelarray *pix, t_bunny_position *pos,
		 t_color *color)
{
  t_color	*col;

  col = pix->pixels;
  col[pix->clipable.clip_width * pos->y + pos->x].full = color->full;
}
