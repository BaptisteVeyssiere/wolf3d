/*
** sprite.c for wolf3d in /home/VEYSSI_B/rendu/gfx_wolf3d
**
** Made by Baptiste veyssiere
** Login   <VEYSSI_B@epitech.net>
**
** Started on  Mon Dec 21 17:50:34 2015 Baptiste veyssiere
** Last update Fri Dec 25 00:56:41 2015 Baptiste veyssiere
*/

#include "wolf3d.h"

int	read_shotgun_sprite(int fd, t_bunny_position *pos, t_refresh *ptr, int i)
{
  t_color       *color;
  int		j;
  int		k;

  color = ptr->shotgun[i]->pixels;
  j = -1;
  if (read(fd, &color[pos->x + pos->y * TEXTURE_SIZE * 6].argb[2], 1) < 1 ||
      read(fd, &color[pos->x + pos->y * TEXTURE_SIZE * 6].argb[1], 1) < 1 ||
      read(fd, &color[pos->x + pos->y * TEXTURE_SIZE * 6].argb[0], 1) < 1)
    return (1);
  if (color[pos->x + pos->y * TEXTURE_SIZE * 6].argb[1] == 0
      && color[pos->x + pos->y * TEXTURE_SIZE * 6].argb[0] == 152)
    color[pos->x + pos->y * TEXTURE_SIZE * 6].argb[3] = 0;
  while (++j < 6)
    {
      k = -1;
      while (++k < 6)
	if (j > 0 || k > 0)
	  color[pos->x + k + (pos->y - j) * TEXTURE_SIZE * 6].full =
	    color[pos->x + pos->y * TEXTURE_SIZE * 6].full;
    }
  pos->x += 6;
  return (0);
}

int	shotgun_loop(t_refresh *ptr, char *name[TEXTURE_NBR], int i)
{
  int                   fd;
  t_bunny_position      pos;
  int                   width;
  int                   height;

  while (i < SHOTGUN_NBR)
    {
      if ((fd = open(name[i], O_RDONLY)) == -1 ||
          bitmap_header(fd, &width, &height) == 1)
        return (1);
      ptr->shotgun[i] = bunny_new_pixelarray(width * 6, height * 6);
      pos.y = (height * 6) - 1;
      pos.x = 0;
      while (pos.y > 0)
        {
          pos.x = 0;
          while (pos.x < (width * 6))
	    if (read_shotgun_sprite(fd, &pos, ptr, i) == 1)
	      return (1);
	  pos.y -= 6;
        }
      close(fd);
      ++i;
    }
  return (0);
}

int	shotgun(t_refresh *ptr)
{
  int   i;
  char  *name[SHOTGUN_NBR] =
    {
      "sprites/shotgun/shotgun1.bmp",
      "sprites/shotgun/shotgun2.bmp",
      "sprites/shotgun/shotgun3.bmp",
      "sprites/shotgun/shotgun4.bmp",
      "sprites/shotgun/shotgun5.bmp",
    };

  i = 0;
  ptr->shotgun_counter = 0;
  if ((shotgun_loop(ptr, name, i)) == 1)
    return (1);
  ptr->shotgun_counter = 0;
  return (0);
}
