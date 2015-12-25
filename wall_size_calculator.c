/*
** wall_size_calculator.c for wolf3d in /home/VEYSSI_B/rendu/gfx_wolf3d
**
** Made by Baptiste veyssiere
** Login   <VEYSSI_B@epitech.net>
**
** Started on  Sat Dec 12 18:50:27 2015 Baptiste veyssiere
** Last update Fri Dec 25 17:02:48 2015 Baptiste veyssiere
*/

#include "wolf3d.h"

void	get_intersection_coord(t_refresh *ptr, t_coord *intersection, int column)
{
  float	x;
  float	y;

  intersection->x = 0.5;
  intersection->y = ((WIDTH / 2) - column);
  intersection->y /= WIDTH;
  x = intersection->x;
  y = intersection->y;
  intersection->x = x * cos(ANGLE) - y * sin(ANGLE);
  intersection->y = x * sin(ANGLE) + y * cos(ANGLE);
  intersection->x += X0;
  intersection->y += Y0;
}

void		wall_check(t_refresh *ptr, int x, int y, t_inter_dist *k)
{
  if (ptr->map[y - 1][x] != 0)
    k->texture = ptr->map[y - 1][x];
  else
    k->texture = ptr->map[y][x];
}

void		found_k_min_x(t_refresh *ptr, t_inter_dist *k, float *k_min)
{
  int		x;
  int		y;

  y = 0;
  x = 0;
  while (++x <= ptr->width)
    {
      k->dist = (x - X0) / k->vector.x;
      y = Y0 + k->dist * k->vector.y;
      if (k->dist > 0 && y < ptr->height && y >= 0)
        if (k->dist < *k_min && (ptr->map[y][x - 1] != 0 ||
                                ((x < ptr->width) && ptr->map[y][x] != 0)))
          {
            *k_min = k->dist;
            k->x = x;
            k->y = 0;
	    k->offset  = ((Y0 + k->dist * k->vector.y)
			  - (int)(Y0 + k->dist * k->vector.y)) * TEXTURE_SIZE;
	    if (ptr->map[y][x - 1] != 0)
	      k->texture = ptr->map[y][x - 1];
	    else
	      k->texture = ptr->map[y][x];
          }
    }
  k->dist = *k_min;
}

void		found_k_min_y(t_refresh *ptr, t_inter_dist *k)
{
  float		k_min;
  int		y;
  int		x;

  k_min = 0;
  k->dist = 0;
  k_min = ptr->height * ptr->width;
  y = 0;
  while (++y <= ptr->height)
    {
      k->dist = (y - Y0) / k->vector.y;
      x = X0 + k->dist * k->vector.x;
      if (k->dist > 0 && x < ptr->width)
	if (k->dist < k_min && (ptr->map[y - 1][x] != 0 ||
				((y < ptr->height) && ptr->map[y][x] != 0)))
	  {
	    k_min = k->dist;
	    k->y = y;
	    k->offset = ((X0 + k->dist * k->vector.x) -
			 (int)(X0 + k->dist * k->vector.x)) * TEXTURE_SIZE;
	    wall_check(ptr, x, y, k);
	  }
    }
  found_k_min_x(ptr, k, &k_min);
}

void	get_sizes(t_inter_dist k, t_size *size)
{
  size->wall = HEIGHT / k.dist;
  if (size->wall >= HEIGHT)
    size->wall = HEIGHT;
  size->sky_floor = (HEIGHT - size->wall) / 2;
}
