/*
** prototypes.h for wolf3d in /home/VEYSSI_B/rendu/gfx_wolf3d
**
** Made by Baptiste veyssiere
** Login   <VEYSSI_B@epitech.net>
**
** Started on  Thu Dec 10 15:48:34 2015 Baptiste veyssiere
** Last update Thu Dec 10 23:53:06 2015 Baptiste veyssiere
*/

#ifndef PROTOTYPES_H_
# define PROTOTYPES_H_

# include <lapin.h>
# include <math.h>
# include <unistd.h>

# define WIDTH 1080
# define HEIGHT 720
# define SQUARE(x) ((x) * (x))

typedef struct
{
  t_bunny_position      pos;
  double                angle;
}                       t_pov;

typedef struct
{
  t_bunny_window        *win;
  t_bunny_pixelarray    *pix;
  t_bunny_ini		*ini;
  t_pov			*perso;
  int			**map;
}			t_refresh;

t_bunny_response	echap(t_bunny_event_state, t_bunny_keysym, void*);
t_bunny_response        refresh(void*);
int			get_pov(t_refresh*);
int			get_array(t_refresh*);
int			my_getnbr(const char*);
double			my_getdouble(const char*);
int			get_width(t_bunny_ini*);
int			get_height(t_bunny_ini*);
int			put_data_in_array(t_refresh*, int, int);
void			free_function(t_refresh*);

#endif /* !PROTOTYPES_H_ */
