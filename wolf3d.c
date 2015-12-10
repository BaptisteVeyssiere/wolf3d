/*
** fdf2.c for fdf2 in /home/VEYSSI_B/rendu/gfx_wolf3d
**
** Made by Baptiste veyssiere
** Login   <VEYSSI_B@epitech.net>
**
** Started on  Wed Dec  9 11:54:05 2015 Baptiste veyssiere
** Last update Thu Dec 10 20:00:35 2015 Baptiste veyssiere
*/

#include "prototypes.h"

t_bunny_response        echap(t_bunny_event_state state,
                              t_bunny_keysym key,
                              void *data)
{
  state = state;
  data = data;
  if (key == BKS_ESCAPE)
    return (EXIT_ON_SUCCESS);
  return (GO_ON);
}

t_bunny_response        refresh(void *p)
{
  t_refresh		*ptr;
  t_bunny_position      pos;

  ptr = p;
  pos.x = 0;
  pos.y = 0;
  bunny_blit(&ptr->win->buffer, &ptr->pix->clipable, &pos);
  bunny_display(ptr->win);
  return (GO_ON);
}

int	main(int ac, char **av)
{
  t_refresh	ptr;

  ptr.win = bunny_start(WIDTH, HEIGHT, false, "wolf3d");
  ptr.pix = bunny_new_pixelarray(WIDTH, HEIGHT);
  if (ac != 2 || (ptr.ini = bunny_load_ini(av[1])) == NULL)
    {
      write(2, "error : bad .ini file\n", 22);
      return (1);
    }
  if (get_pov(&ptr) == 1 || get_array(&ptr) == 1)
    {
      write(2, "error : bad .ini file\n", 22);
      return (1);
    }
  bunny_set_key_response(echap);
  bunny_set_loop_main_function(refresh);
  bunny_loop(ptr.win, 30, &ptr);
  bunny_delete_clipable(&ptr.pix->clipable);
  bunny_stop(ptr.win);
  return (0);
}
