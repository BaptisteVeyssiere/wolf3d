/*
** bitmap.c for bitmap.c in /home/VEYSSI_B/rendu/gfx_wolf3d
**
** Made by Baptiste veyssiere
** Login   <VEYSSI_B@epitech.net>
**
** Started on  Fri Dec 18 15:13:25 2015 Baptiste veyssiere
** Last update Fri Dec 18 23:16:55 2015 Baptiste veyssiere
*/

#include "prototypes.h"

int	read_bitmap(int fd, t_bunny_position pos, t_refresh *ptr)
{
  t_color	*color;

  color = ptr->textures->pixels;
  read(fd, &color[pos.x + pos.y * TEXTURE_SIZE].argb[1], 1);
  read(fd, &color[pos.x + pos.y * TEXTURE_SIZE].argb[0], 1);
  read(fd, &color[pos.x + pos.y * TEXTURE_SIZE].argb[2], 1);
  return (0);
}

int	bitmap(t_refresh *ptr)
{
  char			buffer[TEXTURE_SIZE + 72];
  int			fd;
  t_bunny_position	pos;

  ptr->textures = bunny_new_pixelarray(TEXTURE_SIZE, TEXTURE_SIZE);
  fd = open("textures/cross_wall.bmp", O_RDONLY);
  read(fd, buffer, TEXTURE_SIZE + 72);
  pos.y = TEXTURE_SIZE - 1;
  pos.x = 0;
  while (pos.y >= 0)
    {

      pos.x = 0;
      while (pos.x < TEXTURE_SIZE)
	{
	  if (read_bitmap(fd, pos, ptr) == 1)
	    return (1);
	  ++pos.x;
	}
      --pos.y;
    }
  return (0);
}
