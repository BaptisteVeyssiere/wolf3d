/*
** bitmap.c for bitmap.c in /home/VEYSSI_B/rendu/gfx_wolf3d
**
** Made by Baptiste veyssiere
** Login   <VEYSSI_B@epitech.net>
**
** Started on  Fri Dec 18 15:13:25 2015 Baptiste veyssiere
** Last update Thu Dec 24 23:49:50 2015 Baptiste veyssiere
*/

#include "wolf3d.h"
#include <stdio.h>

int	read_bitmap(int fd, t_bunny_position pos, t_refresh *ptr, int i)
{
  t_color	*color;

  color = ptr->textures[i]->pixels;
  if (read(fd, &color[pos.x + pos.y * TEXTURE_SIZE].argb[2], 1) < 1 ||
      read(fd, &color[pos.x + pos.y * TEXTURE_SIZE].argb[1], 1) < 1 ||
      read(fd, &color[pos.x + pos.y * TEXTURE_SIZE].argb[0], 1) < 1)
    return (1);
  return (0);
}

int	bitmap_header(int fd, int *width, int *height)
{
  int	offset;
  char	buffer[OFFSET_LIM] = {0};

  *height = 0;
  *width= 0;
  offset = 0;
  if (read(fd, buffer, 10) < 1 || read(fd, &offset, 4) < 1 ||
      read(fd, buffer, 4) < 1 || read(fd, width, 4) < 1 ||
      read(fd, height, 4) < 1 || read(fd, buffer, (offset - 26)) < 1)
    return (1);
  return (0);
}

int	bitmap_loop(t_refresh *ptr, char *name[TEXTURE_NBR], int i)
{
  int                   fd;
  t_bunny_position      pos;
  int			width;
  int			height;

  while (i < TEXTURE_NBR)
    {
      if ((fd = open(name[i], O_RDONLY)) == -1 ||
	  bitmap_header(fd, &width, &height) == 1)
	return (1);
      ptr->textures[i] = bunny_new_pixelarray(width, height);
      pos.y = height;
      pos.x = 0;
      while (--pos.y >= 0)
        {
          pos.x = -1;
          while (++pos.x < width)
	    if (read_bitmap(fd, pos, ptr, i) == 1)
	      return (1);
        }
      close(fd);
      ++i;
    }
  return (0);
}

int	bitmap(t_refresh *ptr)
{
  int	i;
  char	*name[TEXTURE_NBR] =
    {
      "textures/wall.bmp",
      "textures/flag_wall.bmp",
      "textures/broken_wall_1.bmp",
      "textures/broken_wall_2.bmp",
      "textures/cross_wall.bmp",
      "textures/picture_wall.bmp",
    };

  i = 0;
  if ((bitmap_loop(ptr, name, i)) == 1)
    return (1);
  return (0);
}
