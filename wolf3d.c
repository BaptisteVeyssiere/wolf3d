/*
** fdf2.c for fdf2 in /home/VEYSSI_B/rendu/gfx_wolf3d
**
** Made by Baptiste veyssiere
** Login   <VEYSSI_B@epitech.net>
**
** Started on  Wed Dec  9 11:54:05 2015 Baptiste veyssiere
** Last update Sat Dec 12 20:52:15 2015 Baptiste veyssiere
*/

#include "prototypes.h"

void	free_function(t_refresh *ptr)
{
  int	height;
  int	i;

  i = 0;
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
  state = state;
  data = data;
  if (key == BKS_ESCAPE)
    return (EXIT_ON_SUCCESS);
  return (GO_ON);
}

t_bunny_response	refresh(void *p)
{
  t_refresh		*ptr;
  t_bunny_position      pos;

  ptr = p;
  pos.x = 0;
  pos.y = 0;
  wall_draw(ptr);
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
      || get_pov(&ptr) == 1 || get_array(&ptr) == 1)
    {
      write(2, "error : bad .ini file\n", 22);
      return (1);
    }
  radian(&(ptr.perso->angle));
  bunny_set_key_response(echap);
  bunny_set_loop_main_function(refresh);
  bunny_loop(ptr.win, 30, &ptr);
  bunny_delete_clipable(&ptr.pix->clipable);
  bunny_stop(ptr.win);
  free_function(&ptr);
  return (0);
}
