/*
** bitmap.c for bitmap.c in /home/VEYSSI_B/rendu/gfx_wolf3d
**
** Made by Baptiste veyssiere
** Login   <VEYSSI_B@epitech.net>
**
** Started on  Fri Dec 18 15:13:25 2015 Baptiste veyssiere
** Last update Wed Dec 23 12:12:52 2015 Baptiste veyssiere
*/

#include "wolf3d.h"

int	read_bitmap(int fd, t_bunny_position pos, t_refresh *ptr, int i)
{
  t_color	*color;

  color = ptr->textures[i]->pixels;
  read(fd, &color[pos.x + pos.y * TEXTURE_SIZE].argb[1], 1);
  read(fd, &color[pos.x + pos.y * TEXTURE_SIZE].argb[0], 1);
  read(fd, &color[pos.x + pos.y * TEXTURE_SIZE].argb[2], 1);
  return (0);
}

int	bitmap_loop(t_refresh *ptr, char *name[TEXTURE_NBR], int i)
{
  char                  buffer[TEXTURE_SIZE + 72];
  int                   fd;
  t_bunny_position      pos;

  while (i < TEXTURE_NBR)
    {
      ptr->textures[i] = bunny_new_pixelarray(TEXTURE_SIZE, TEXTURE_SIZE);
      fd = open(name[i], O_RDONLY);
      read(fd, buffer, TEXTURE_SIZE + 72);
      pos.y = TEXTURE_SIZE - 1;
      pos.x = 0;
      while (pos.y >= 0)
        {
          pos.x = 0;
          while (pos.x < TEXTURE_SIZE)
            {
              if (read_bitmap(fd, pos, ptr, i) == 1)
                return (1);
              ++pos.x;
            }
          --pos.y;
        }
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
