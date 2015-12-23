/*
** wall_draw.c for wolf3d in /home/VEYSSI_B/rendu/gfx_wolf3d
**
** Made by Baptiste veyssiere
** Login   <VEYSSI_B@epitech.net>
**
** Started on  Sat Dec 12 18:45:55 2015 Baptiste veyssiere
** Last update Wed Dec 23 12:15:15 2015 Baptiste veyssiere
*/

#include "wolf3d.h"

void	initializer(t_inter_dist *k, t_bunny_position *pos,
		    t_coord *coord, t_size *size)
{
  k->dist = 0;
  k->x = 0;
  k->y = 0;
  pos->y = 0;
  coord->x = 0;
  coord->y = 0;
  size->wall = 0;
  size->sky_floor = 0;
}

void	sky(t_size size, t_refresh *ptr, t_bunny_position *pos)
{
  int		i;
  t_color	color[2];

  i = 1;
  color[0].full = SKY;
  while (i < size.sky_floor)
    {
      tekpixel(ptr->pix, pos, &color[0]);
      pos->y += 1;
      i += 1;
    }
}

void		wall(t_refresh *ptr, t_bunny_position *pos, t_size size, t_inter_dist k)
{
  int		i;
  float		scale;
  t_color	*color;
  float		index;

  i = 1;
  scale = ((float)TEXTURE_SIZE / (float)(HEIGHT / k.dist));
  color = ptr->textures[k.texture - 1]->pixels;
  index = 0;
  while (i < (size.wall - 1))
    {
      /*if (k.y < Y0 && k.y != 0)
	tekpixel(ptr->pix, pos, &color[0]);
      else if (k.y >= Y0 && k.y != 0)
	tekpixel(ptr->pix, pos, &color[3]);
      else if (k.x < X0 && k.x != 0)
	tekpixel(ptr->pix, pos, &color[1]);
      else
      tekpixel(ptr->pix, pos, &color[2]);*/
      if ((HEIGHT / k.dist) > HEIGHT)
	tekpixel(ptr->pix, pos, &color[((int)index + (int)(scale * (((HEIGHT / k.dist) - HEIGHT) / 2))) * TEXTURE_SIZE + k.offset]);
      else
	tekpixel(ptr->pix, pos, &color[(int)index * TEXTURE_SIZE + k.offset]);
      pos->y += 1;
      index += scale;
      i += 1;
    }
}

void		ground(t_refresh *ptr, t_size size, t_bunny_position *pos)
{
  int		i;
  t_color	color;

  i = 1;
  color.full = GROUND;
  while (i < size.sky_floor)
    {
      tekpixel(ptr->pix, pos, &color);
      pos->y += 1;
      i += 1;
    }
}

void			wall_draw(t_refresh *ptr)
{
  int			x;
  t_inter_dist		k;
  t_coord		coord;
  t_size		size;
  t_bunny_position	pos;

  x = 0;
  while (x < WIDTH)
    {
      initializer(&k, &pos, &coord, &size);
      pos.x = x;
      get_intersection_coord(ptr, &coord, x);
      found_k_min_y(ptr, coord, &k);
      get_sizes(k, &size);
      sky(size, ptr, &pos);
      wall(ptr, &pos, size, k);
      ground(ptr, size, &pos);
      x += 1;
    }
}
