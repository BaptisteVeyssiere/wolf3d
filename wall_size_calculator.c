/*
** wall_size_calculator.c for wolf3d in /home/VEYSSI_B/rendu/gfx_wolf3d
**
** Made by Baptiste veyssiere
** Login   <VEYSSI_B@epitech.net>
**
** Started on  Sat Dec 12 18:50:27 2015 Baptiste veyssiere
** Last update Fri Dec 18 23:32:10 2015 Baptiste veyssiere
*/

#include "prototypes.h"
#include <stdio.h>

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

void		found_k_min_x(t_refresh *ptr, t_coord vector, t_inter_dist *k,
		      float *k_min)
{
  int		width;
  int		height;
  int		x;
  int		y;

  y = 0;
  x = 1;
  width = get_width(ptr->ini);
  height = get_height(ptr->ini);
  while (x <= width)
    {
      k->dist = (x - X0) / vector.x;
      y = Y0 + k->dist * vector.y;
      if (k->dist > 0 && y < height && y >= 0)
        if (k->dist < *k_min && (ptr->map[y][x - 1] == 1 ||
                                ((x < width) && ptr->map[y][x] == 1)))
          {
            *k_min = k->dist;
            k->x = x;
            k->y = 0;
          }
      x += 1;
    }
}

void		found_k_min_y(t_refresh *ptr, t_coord coord, t_inter_dist *k)
{
  int		height;
  int		width;
  t_coord	vector;
  float		k_min;
  int		y;
  int		x;

  k_min = 0;
  k->dist = 0;
  height = get_height(ptr->ini);
  width = get_width(ptr->ini);
  vector.x = X1 - X0;
  vector.y = Y1 - Y0;
  k_min = height * width;
  y = 1;
  while (y <= height)
    {
      k->dist = (y - Y0) / vector.y;
      x = X0 + k->dist * vector.x;
      if (k->dist > 0 && x < width)
	if (k->dist < k_min && (ptr->map[y - 1][x] == 1 ||
				((y < height) && ptr->map[y][x] == 1)))
	  {
	    k_min = k->dist;
	    k->y = y;
	  }
      y += 1;
    }
  found_k_min_x(ptr, vector, k, &k_min);
  k->dist = k_min;
}

void	get_sizes(t_inter_dist k, t_size *size)
{
  size->wall = HEIGHT / k.dist;
  if (size->wall >= HEIGHT)
    size->wall = HEIGHT;
  size->sky_floor = (HEIGHT - size->wall) / 2;
}
