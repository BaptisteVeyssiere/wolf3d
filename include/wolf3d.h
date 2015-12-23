/*
** prototypes.h for wolf3d in /home/VEYSSI_B/rendu/gfx_wolf3d
**
** Made by Baptiste veyssiere
** Login   <VEYSSI_B@epitech.net>
**
** Started on  Thu Dec 10 15:48:34 2015 Baptiste veyssiere
** Last update Wed Dec 23 15:56:24 2015 Baptiste veyssiere
*/

#ifndef WOLF3D_H_
# define WOLF3D_H_

# include <lapin.h>
# include <math.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define WIDTH 1080
# define HEIGHT 720
# define TEXTURE_NBR 6
# define TEXTURE_SIZE 64
# define SHOTGUN_NBR 5
# define BLACK_LINE 0x303030
# define SKY 0x383838
# define GROUND 0x707070
# define SQUARE(x) ((x) * (x))
# define X0 ptr->perso->pos.x
# define Y0 ptr->perso->pos.y
# define X1 coord.x
# define Y1 coord.y
# define ANGLE ptr->perso->angle

typedef struct
{
  float		dist;
  int		x;
  int		y;
  int		offset;
  int		texture;
}		t_inter_dist;

typedef struct
{
  int		sky_floor;
  int		wall;
}		t_size;

typedef struct
{
  float		x;
  float		y;
}		t_coord;

typedef struct
{
  t_coord	pos;
  double	angle;
}		t_pov;

typedef struct
{
  float		x;
  float		y;
  double	angle;
}		t_axis;

typedef struct
{
  t_bunny_window        *win;
  t_bunny_pixelarray    *pix;
  t_bunny_ini		*ini;
  t_pov			*perso;
  int			**map;
  t_axis		*move;
  int			shotgun_counter;
  t_bunny_pixelarray	*textures[TEXTURE_NBR];
  t_bunny_pixelarray	*shotgun[SHOTGUN_NBR];
  t_bunny_music		*shot_sound;
}			t_refresh;

t_bunny_response	echap(t_bunny_event_state, t_bunny_keysym, void*);
t_bunny_response        refresh(void*);
int			get_pov(t_refresh*);
int			get_array(t_refresh*);
int			my_getnbr(const char*);
double			my_getdouble(const char*);
void			double_filler(const char*, int*, double*, double);
int			get_width(t_bunny_ini*);
int			get_height(t_bunny_ini*);
int			put_data_in_array(t_refresh*, int, int);
void			free_function(t_refresh*);
void			radian(double*);
void			rotation_translation(t_coord*, double, t_pov*, float);
void			wall_draw(t_refresh*);
void			initializer(t_inter_dist*, t_bunny_position*, t_coord*, t_size*);
void			sky(t_size, t_refresh*, t_bunny_position*);
void			wall(t_refresh*, t_bunny_position*, t_size, t_inter_dist);
void			ground(t_refresh*, t_size, t_bunny_position*);
void			get_intersection_coord(t_refresh*, t_coord*, int);
void			found_k_min_y(t_refresh*, t_coord, t_inter_dist*);
void			found_k_min_x(t_refresh*, t_coord, t_inter_dist*, float*);
void			get_sizes(t_inter_dist, t_size*);
void			tekpixel(t_bunny_pixelarray*, t_bunny_position*, t_color*);
void			go(t_coord*, double, t_coord*, float);
void			moving(t_refresh*);
double			double_modulo(double, double);
void			angle_rotation(t_refresh*);
void			music(t_bunny_music*);
int			bitmap(t_refresh*);
int			read_bitmap(int, t_bunny_position, t_refresh*, int);
int			bitmap_loop(t_refresh*, char**, int);
int                     shotgun(t_refresh*);
int                     read_shotgun_sprite(int, t_bunny_position, t_refresh*, int);
int                     shotgun_loop(t_refresh*, char**, int);
void			tekblit(t_bunny_pixelarray*, t_bunny_pixelarray*, const t_bunny_position*);

#endif /* !WOLF3D_H_ */