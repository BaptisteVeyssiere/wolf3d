/*
** prototypes.h for wolf3d in /home/VEYSSI_B/rendu/gfx_wolf3d
**
** Made by Baptiste veyssiere
** Login   <VEYSSI_B@epitech.net>
**
** Started on  Thu Dec 10 15:48:34 2015 Baptiste veyssiere
** Last update Sun Dec 13 19:53:15 2015 Baptiste veyssiere
*/

#ifndef PROTOTYPES_H_
# define PROTOTYPES_H_

# include <lapin.h>
# include <math.h>
# include <unistd.h>

# define WIDTH 640
# define HEIGHT 640
# define SQUARE(x) ((x) * (x))
# define X0 ptr->perso->pos.x
# define Y0 ptr->perso->pos.y
# define X1 coord.x
# define Y1 coord.y
# define ANGLE ptr->perso->angle

typedef struct
{
  int	sky_floor;
  int	wall;
}		t_size;

typedef struct
{
  float		x;
  float		y;
}		t_coord;

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
void			radian(double*);
void			rotation_translation(t_coord*, double, t_pov*, float);
void			wall_draw(t_refresh*);
void			get_intersection_coord(t_refresh*, t_coord*, int);
void			found_k_min(t_refresh*, t_coord, float*);
void			get_sizes(float, t_size*);
void			tekpixel(t_bunny_pixelarray*, t_bunny_position*, t_color*);

#endif /* !PROTOTYPES_H_ */
