/*
** fdf2.c for fdf2 in /home/VEYSSI_B/rendu/gfx_wolf3d
**
** Made by Baptiste veyssiere
** Login   <VEYSSI_B@epitech.net>
**
** Started on  Wed Dec  9 11:54:05 2015 Baptiste veyssiere
** Last update Wed Dec 23 16:09:10 2015 Baptiste veyssiere
*/

#include "wolf3d.h"

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
  if (key == BKS_Z && state == GO_DOWN)
    ptr->move->y = 0.05;
  else if (key == BKS_Z && state == GO_UP)
    ptr->move->y = 0;
  if (key == BKS_S && state == GO_DOWN)
    ptr->move->y = -0.05;
  else if (key == BKS_S && state == GO_UP)
    ptr->move->y = 0;
  if (key == BKS_Q && state == GO_DOWN)
    ptr->move->x = 0.05;
  else if (key == BKS_Q && state == GO_UP)
    ptr->move->x = 0;
  if (key == BKS_D && state == GO_DOWN)
    ptr->move->x = -0.05;
  else if (key == BKS_D && state == GO_UP)
    ptr->move->x = 0;
  if (key == BKS_LEFT && state == GO_DOWN)
    ptr->move->angle = (M_PI / 40);
  else if (key == BKS_LEFT && state == GO_UP)
    ptr->move->angle = 0;
  if (key == BKS_RIGHT && state == GO_DOWN)
    ptr->move->angle = -(M_PI / 40);
  else if (key == BKS_RIGHT && state == GO_UP)
    ptr->move->angle = 0;
  if (key == BKS_A && ptr->shotgun_counter == 0)
    {
      ptr->shotgun_counter = 1;
      bunny_sound_play(ptr->shot_sound);
    }
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
  wall_draw(ptr);
  moving(ptr);
  angle_rotation(ptr);
  pos.x = (WIDTH - 6 * TEXTURE_SIZE) / 2;
  pos.y = HEIGHT - (6 * TEXTURE_SIZE);
  if (ptr->shotgun_counter > 0)
    ptr->shotgun_counter += 1;
  if (ptr->shotgun_counter >= (SHOTGUN_NBR * 10))
    ptr->shotgun_counter = 0;
  tekblit(ptr->pix, ptr->shotgun[(int)(ptr->shotgun_counter / 10)], &pos);
  pos.x = 0;
  pos.y = 0;
  bunny_blit(&ptr->win->buffer, &ptr->pix->clipable, &pos);
  bunny_display(ptr->win);
  return (GO_ON);
}

int	main(int ac, char **av)
{
  t_refresh	ptr;
  t_bunny_music	*song;

  ptr.win = bunny_start(WIDTH, HEIGHT, false, "wolf3d");
  ptr.pix = bunny_new_pixelarray(WIDTH, HEIGHT);
  if (ac != 2 || (ptr.ini = bunny_load_ini(av[1])) == NULL
      || get_pov(&ptr) == 1 || get_array(&ptr) == 1 ||
      (ptr.move = bunny_malloc(sizeof(*(ptr.move)))) == NULL ||
      (get_width(ptr.ini) < 3 && get_height(ptr.ini) < 3) || bitmap(&ptr) == 1 ||
      shotgun(&ptr) == 1 || (song = bunny_load_music("music/earthworm_jim.ogg")) == NULL
      || (ptr.shot_sound = bunny_load_music("sounds/shotgun.ogg")) == NULL)
    {
      write(2, "error : bad .ini file\n", 22);
      return (1);
    }
  music(song);
  radian(&(ptr.perso->angle));
  bunny_set_key_response(echap);
  bunny_set_loop_main_function(refresh);
  bunny_loop(ptr.win, 30, &ptr);
  bunny_delete_sound(song);
  bunny_delete_sound(ptr.shot_sound);
  bunny_delete_clipable(&ptr.pix->clipable);
  bunny_stop(ptr.win);
  free_function(&ptr);
  return (0);
}
