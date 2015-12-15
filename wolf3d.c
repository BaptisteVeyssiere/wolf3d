/*
** fdf2.c for fdf2 in /home/VEYSSI_B/rendu/gfx_wolf3d
**
** Made by Baptiste veyssiere
** Login   <VEYSSI_B@epitech.net>
**
** Started on  Wed Dec  9 11:54:05 2015 Baptiste veyssiere
** Last update Tue Dec 15 22:32:37 2015 Baptiste veyssiere
*/

#include "prototypes.h"
#include <stdio.h>

void	free_function(t_refresh *ptr)
{
  int	height;
  int	i;

  i = 0;
  height = 0;
  height = get_height(ptr->ini);
  height = height;
  while (i < height)
    bunny_free(ptr->map[i++]);
  bunny_free(ptr->map);
  bunny_free(ptr->perso);
}

t_bunny_response	echap(t_bunny_event_state state,
                              t_bunny_keysym key,
                              void *data)
{
  t_refresh	*ptr;

  ptr = data;
  ptr->move->y = 0;
  ptr->move->x = 0;
  if (key == BKS_UP)
    ptr->move->y = 0.05;
  else if (key == BKS_DOWN)
    ptr->move->y = -0.05;
  else if (key == BKS_LEFT)
    ptr->move->x = 0.05;
  else if (key == BKS_RIGHT)
    ptr->move->x = -0.05;
  else
    {
      ptr->move->y = 0;
      ptr->move->x = 0;
    }
  state = state;
  if (key == BKS_ESCAPE)
    return (EXIT_ON_SUCCESS);
  return (GO_ON);
}

t_bunny_response	refresh(void *p)
{
  t_refresh		*ptr;
  t_bunny_position      pos;

  ptr = NULL;
  ptr = p;
  pos.x = 0;
  pos.y = 0;
  wall_draw(ptr);
  moving(ptr);
  bunny_blit(&ptr->win->buffer, &ptr->pix->clipable, &pos);
  bunny_display(ptr->win);
  return (GO_ON);
}

int	main(int ac, char **av)
{
  t_refresh	ptr;

  ptr.win = bunny_start(WIDTH, HEIGHT, false, "wolf3d");
  ptr.pix = bunny_new_pixelarray(WIDTH, HEIGHT);
  if (ac != 2 || (ptr.ini = bunny_load_ini(av[1])) == NULL
      || get_pov(&ptr) == 1 || get_array(&ptr) == 1 ||
      (ptr.move = bunny_malloc(sizeof(*(ptr.move)))) == NULL)
    {
      write(2, "error : bad .ini file\n", 22);
      return (1);
    }
  radian(&(ptr.perso->angle));
  bunny_set_key_response(echap);
  bunny_set_loop_main_function(refresh);
  bunny_loop(ptr.win, 20, &ptr);
  bunny_delete_clipable(&ptr.pix->clipable);
  bunny_stop(ptr.win);
  free_function(&ptr);
  return (0);
}
