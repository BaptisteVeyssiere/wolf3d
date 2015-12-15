/*
** get_ini_data.c for wolf3d in /home/VEYSSI_B/rendu/gfx_wolf3d
**
** Made by Baptiste veyssiere
** Login   <VEYSSI_B@epitech.net>
**
** Started on  Thu Dec 10 20:01:21 2015 Baptiste veyssiere
** Last update Tue Dec 15 17:29:00 2015 Baptiste veyssiere
*/

#include "prototypes.h"
#include <stdio.h>

int		get_width(t_bunny_ini *ini)
{
  int           width;
  int           i;

  i = 0;
  width = 0;
  width = my_getnbr(bunny_ini_get_field(ini, "level1", "width", i++));
  return (width);
}

int		get_height(t_bunny_ini *ini)
{
  int           height;
  int           i;

  i = 0;
  height = 0;
  height = my_getnbr(bunny_ini_get_field(ini, "level1", "height", i++));
  return (height);
}

int	get_pov(t_refresh *ptr)
{
  const char	*str;
  int		i;

  str = NULL;
  if ((ptr->perso = bunny_malloc(sizeof(*(ptr->perso)))) == NULL)
    return (1);
  ANGLE = 0;
  X0 = 0;
  Y0 = 0;
  i = 0;
  if ((str = bunny_ini_get_field(ptr->ini, "level1",
				 "start_position", i++)) == NULL)
    return (1);
  X0 = my_getdouble(str);
  /*printf("%f\n", X0);*/
  if ((str = bunny_ini_get_field(ptr->ini, "level1",
				 "start_position", i++)) == NULL)
    return (1);
  Y0 = my_getdouble(str);
  /*printf("%f\n", Y0);*/
  if ((str = bunny_ini_get_field(ptr->ini, "level1",
				 "start_position", i++)) == NULL)
    return (1);
  ANGLE = my_getdouble(str);
  return (0);
}

int	put_data_in_array(t_refresh *ptr, int width, int height)
{
  int		i;
  int		j;
  int		k;
  const char	*str;

  i = height - 1;
  k = 0;
  str = NULL;
  while (i >= 0)
    {
      j = 0;
      while (j < width)
	{
	  if ((str = bunny_ini_get_field(ptr->ini, "level1", "data", k++)) == NULL)
	    return (1);
	  ptr->map[i][j] = my_getnbr(str);
	  if (ptr->map[i][j] == 0 && (i == 0 || i == (height - 1)
				      || j == 0 || j == (width - 1)))
	    return (1);
	  j++;
	}
      i--;
    }
  return (0);
}

int	get_array(t_refresh *ptr)
{
  int	width;
  int	height;
  int	i;

  width = 0;
  height = 0;
  width = get_width(ptr->ini);
  height = get_height(ptr->ini);
  if ((ptr->map = bunny_malloc(sizeof(*(ptr->map)) * height)) == NULL)
    return (1);
  i = 0;
  while (i < height)
    {
      ptr->map[i] = NULL;
      if ((ptr->map[i] = bunny_malloc(sizeof(**(ptr->map)) * width)) == NULL)
	return (1);
      i++;
    }
  if (put_data_in_array(ptr, width, height) == 1)
    return (1);
  return (0);
}
