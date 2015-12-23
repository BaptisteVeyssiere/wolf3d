/*
** music.c for wolf3d in /home/VEYSSI_B/rendu/gfx_wolf3d
**
** Made by Baptiste veyssiere
** Login   <VEYSSI_B@epitech.net>
**
** Started on  Thu Dec 17 11:27:10 2015 Baptiste veyssiere
** Last update Wed Dec 23 12:14:06 2015 Baptiste veyssiere
*/

#include "wolf3d.h"

void	music(t_bunny_music *song)
{
  bunny_sound_loop(song, 1);
  bunny_sound_volume(song, 50);
  bunny_sound_play(song);
}
