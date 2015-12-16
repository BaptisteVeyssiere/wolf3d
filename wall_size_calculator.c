/*
** wall_size_calculator.c for wolf3d in /home/VEYSSI_B/rendu/gfx_wolf3d
**
** Made by Baptiste veyssiere
** Login   <VEYSSI_B@epitech.net>
**
** Started on  Sat Dec 12 18:50:27 2015 Baptiste veyssiere
** Last update Wed Dec 16 18:42:31 2015 Baptiste veyssiere
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

void	found_k_min(t_refresh *ptr, t_coord coord, float *k)
{
  int	height;
  int	width;
  float	Vx;
  float Vy;
  float	k_min;
  int	y;
  int	x;

  k_min = 0;
  *k = 0;
  height = get_height(ptr->ini);
  width = get_width(ptr->ini);
  Vx = X1 - X0;
  Vy = Y1 - Y0;
  k_min = height * width;
  y = 1;
  while (y <= height)
    {
      *k = (y - Y0) / Vy;
      x = X0 + *k * Vx;
      if (*k > 0 && x < width)
	if (*k < k_min && (ptr->map[y - 1][x] == 1 || ((y < height) && ptr->map[y][x] == 1)))
	  k_min = *k;
      y += 1;
    }
  x = 1;
  while (x <= width)
    {
      *k = (x - X0) / Vx;
      y = Y0 + *k * Vy;
      if (*k > 0 && y < height && y >= 0)
	if (*k < k_min && (ptr->map[y][x - 1] == 1 || ((x < width) && ptr->map[y][x] == 1)))
	  k_min = *k;
      x += 1;
    }
  *k = k_min;
}

void	get_sizes(float k, t_size *size)
{
  size->wall = HEIGHT / (2 * k);
  if (size->wall >= HEIGHT)
    size->wall = HEIGHT;
  size->sky_floor = (HEIGHT - size->wall) / 2;
}
