/*
** sprite.c for wolf3d in /home/VEYSSI_B/rendu/gfx_wolf3d
**
** Made by Baptiste veyssiere
** Login   <VEYSSI_B@epitech.net>
**
** Started on  Mon Dec 21 17:50:34 2015 Baptiste veyssiere
** Last update Wed Dec 23 14:50:06 2015 Baptiste veyssiere
*/

#include "wolf3d.h"

int     read_shotgun_sprite(int fd, t_bunny_position pos, t_refresh *ptr, int i)
{
  t_color       *color;
  int		j;

  color = ptr->shotgun[i]->pixels;
  j = 0;
  read(fd, &color[pos.x + pos.y * TEXTURE_SIZE * 6].argb[1], 1);
  read(fd, &color[pos.x + pos.y * TEXTURE_SIZE * 6].argb[0], 1);
  read(fd, &color[pos.x + pos.y * TEXTURE_SIZE * 6].argb[2], 1);
  if (color[pos.x + pos.y * TEXTURE_SIZE * 6].full == 0xFF880098)
    color[pos.x + pos.y * TEXTURE_SIZE * 6].full = 0x00000000;
  while (j < 6)
    {
      if (j > 0)
	color[pos.x + (pos.y - j) * TEXTURE_SIZE * 6].full = color[pos.x + pos.y * TEXTURE_SIZE * 6].full;
      color[pos.x + 1 + (pos.y - j) * TEXTURE_SIZE * 6].full = color[pos.x + pos.y * TEXTURE_SIZE * 6].full;
      color[pos.x + 2 + (pos.y - j) * TEXTURE_SIZE * 6].full = color[pos.x + pos.y * TEXTURE_SIZE * 6].full;
      color[pos.x + 3 + (pos.y - j) * TEXTURE_SIZE * 6].full = color[pos.x + pos.y * TEXTURE_SIZE * 6].full;
      color[pos.x + 4 + (pos.y - j) * TEXTURE_SIZE * 6].full = color[pos.x + pos.y * TEXTURE_SIZE * 6].full;
      color[pos.x + 5 + (pos.y - j) * TEXTURE_SIZE * 6].full = color[pos.x + pos.y * TEXTURE_SIZE * 6].full;
      ++j;
    }
  return (0);
}

int     shotgun_loop(t_refresh *ptr, char *name[SHOTGUN_NBR], int i)
{
  char                  buffer[TEXTURE_SIZE + 72];
  int                   fd;
  t_bunny_position      pos;

  while (i < TEXTURE_NBR)
    {
      ptr->shotgun[i] = bunny_new_pixelarray(TEXTURE_SIZE * 6, TEXTURE_SIZE * 6);
      fd = open(name[i], O_RDONLY);
      read(fd, buffer, TEXTURE_SIZE + 72);
      pos.y = (6 * TEXTURE_SIZE) - 1;
      pos.x = 0;
      while (pos.y > 0)
        {
          pos.x = 0;
          while (pos.x < (TEXTURE_SIZE * 6))
            {
              if (read_shotgun_sprite(fd, pos, ptr, i) == 1)
                return (1);
              pos.x += 6;
            }
          pos.y -= 6;
        }
      ++i;
    }
  return (0);
}

int     shotgun(t_refresh *ptr)
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
