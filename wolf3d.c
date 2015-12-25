/*
** fdf2.c for fdf2 in /home/VEYSSI_B/rendu/gfx_wolf3d
**
** Made by Baptiste veyssiere
** Login   <VEYSSI_B@epitech.net>
**
** Started on  Wed Dec  9 11:54:05 2015 Baptiste veyssiere
** Last update Fri Dec 25 18:30:40 2015 Baptiste veyssiere
*/

#include "wolf3d.h"

void	free_function(t_refresh *ptr, t_bunny_music *song)
{
  int	i;

  i = 0;
  bunny_delete_sound(song);
  bunny_delete_sound(ptr->shot_sound);
  bunny_delete_clipable(&ptr->pix->clipable);
  bunny_stop(ptr->win);
  while (i < ptr->height)
    bunny_free(ptr->map[i++]);
  bunny_free(ptr->map);
  bunny_free(ptr->perso);
}

t_bunny_response	echap(t_bunny_event_state state,
                              t_bunny_keysym key,
                              void *data)
{
  t_refresh	*ptr;
  int		i;
  int		keys[BUTTON_NBR] =
    {
      BKS_Z,
      BKS_S,
      BKS_Q,
      BKS_D,
      BKS_LEFT,
      BKS_RIGHT,
      BKS_A,
    };

  ptr = data;
  i = 0;
  while (keys[i] != key && i < BUTTON_NBR)
    ++i;
  if (i < BUTTON_NBR)
    ptr->keypad[i](ptr, state);
  if (key == BKS_ESCAPE)
    return (EXIT_ON_SUCCESS);
  return (GO_ON);
}

t_bunny_response	refresh(void *p)
{
  t_refresh		*ptr;
  t_bunny_position      pos;

  ptr = p;
  wall_draw(ptr);
  moving(ptr);
  angle_rotation(ptr);
  pos.x = (WIDTH - 6 * TEXTURE_SIZE) / 2;
  pos.y = HEIGHT - (6 * TEXTURE_SIZE);
  if (ptr->shotgun_counter > 0)
    ptr->shotgun_counter += 1;
  if (ptr->shotgun_counter >= (SHOTGUN_NBR * 20))
    ptr->shotgun_counter = 0;
  tekblit(ptr->pix, ptr->shotgun[(int)(ptr->shotgun_counter / 20)], &pos);
  pos.x = 0;
  pos.y = 0;
  bunny_blit(&ptr->win->buffer, &ptr->pix->clipable, &pos);
  bunny_display(ptr->win);
  return (GO_ON);
}

void	keypad_tab(t_refresh *ptr)
{
  ptr->keypad[0] = up;
  ptr->keypad[1] = down;
  ptr->keypad[2] = left;
  ptr->keypad[3] = right;
  ptr->keypad[4] = rotate_left;
  ptr->keypad[5] = rotate_right;
  ptr->keypad[6] = shoot;
}

int	main(int ac, char **av)
{
  t_refresh	ptr;
  t_bunny_music	*song;

  ptr.win = bunny_start(WIDTH, HEIGHT, false, "wolf3d");
  ptr.pix = bunny_new_pixelarray(WIDTH, HEIGHT);
  if (ac != 2 || (ptr.ini = bunny_load_ini(av[1])) == NULL
      || get_width_and_height(&ptr) == 1 ||
      get_pov(&ptr) == 1 || get_array(&ptr) == 1 ||
      (ptr.move = bunny_malloc(sizeof(*(ptr.move)))) == NULL ||
      bitmap(&ptr) == 1 || shotgun(&ptr) == 1 ||
      (song = bunny_load_music("music/earthworm_jim.ogg")) == NULL
      || (ptr.shot_sound = bunny_load_music("sounds/shotgun.ogg")) == NULL ||
      ptr.width < 3 || ptr.height < 3)
    {
      write(2, "error : bad .ini file\n", 22);
      return (1);
    }
  keypad_tab(&ptr);
  music(song);
  radian(&(ptr.perso->angle));
  bunny_set_key_response(echap);
  bunny_set_loop_main_function(refresh);
  bunny_loop(ptr.win, 60, &ptr);
  free_function(&ptr, song);
  return (0);
}
