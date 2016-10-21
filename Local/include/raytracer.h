#ifndef RAYTRACER_H_
# define RAYTRACER_H_

# include "mlx.h"
# include <math.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "/usr/include/X11/X.h"
# include "my.h"

# define UNU __attribute__((unused))
# define COL(col,min,max) ((col > min && col < max)) ? col : ((col >= max) ? max : min)
# define ERROR -1
# define WARNING -2
# define WIDTH 1000
# define HEIGHT 1000
# define WINDOWS_NAME "Raytracer"
# define COMMENT_CHAR '#'
# define ECHAP 65307
# define PLAN 0
# define SPHERE 1
# define CYLINDER 2
# define CONE 3
# define HYPERBOL 4
# define BOLOIDE 5
# define RED 0xFF0000
# define BLUE 0x0000FF
# define WHITE 0xFFFFFF
# define GREEN 0x00FF00
# define BLACK 0x000000
# define EPS 0.00001

typedef struct	s_list
{
  int		shape;
  double	coord[3];
  double	angle[3];
  double	rayon;
  double	k;
  double	shine;
  int		color;
  int		damier;
  double	limit[3];
  struct s_list	*next;
}		t_list;

typedef struct	s_spot
{
  double	coord[3];
  int		color_spot;
  int		color[3];
  struct s_spot	*next;
}		t_spot;

typedef struct	s_camera
{
  double	eye[3];
  double	angle[3];
  double	v[3];
  char		*texture;
  int		x_text;
  int		y_text;
}		t_cam;

typedef struct	s_env
{
  void		*mlx;
  void		*win;
  void		*img;
  void		*img2;
  char		*data;
  int		bpp;
  int		sizeline;
  int		endian;
  int		bpp2;
  int		sizeline2;
  int		endian2;
  t_cam		cam;
  t_spot	*light;
}		t_env;

int	init_env(t_env *);
int	gere_expose(t_env *);
int	gere_key(int, t_env *);
int	mlx_put_pixel_to_img(t_env  *, int, int, int *);
int	raytracer_introduction(t_env *, t_list *);
int	print_loading_bar(int, int *, char *);
int	my_put_in_list(t_list **, int);
int	my_put_in_light(t_spot **);
void	my_show_list(t_list *);
int	calc_color_pixel(t_env *, t_list *, int *, int *);
int	calc_k(t_list *, double *, double *);
void	rotate_axe(double *, double *, char);
int	translate(double *, double *, double *);
double	delta_solution(double, double *);
int	inter_sphere(t_list *, double *, double *);
int	inter_plan(t_list *, double *, double *);
int	inter_cone(t_list *, double *, double *);
int	inter_cyl(t_list *, double *, double *);
int	inter_hyperbol(t_list *, double *, double *);
int	inter_hyperboloid(t_list *, double *, double *);
int	lighting(t_env *, t_list *, t_list *, double *, double *);
void	normale_plan(double *, double *);
void	normale_sphere(double *, double *);
void	normale_cyl(double *, double *);
void	normale_cone(double *, double *);
void	normale_hyperbol(double *, double *);
void	normale_hyperboloid(double *, double *);
int	get_scene_from_files(char *, t_env *e, t_list **);
int	get_scene(int, t_env *, t_list **);
int	fill_shapes(char *, t_list **);
int	fill_cam(char *, t_env *);
int	fill_light(char *, t_spot *);
int	get_a_color(char *, int *);
int	get_one_value(char *, double *);
int	get_coord(char *, double *);
int	check_match(char *, char *);
void	init_ptr(double (*limit_ptr[9])(double *, double,
					double *, double *, double *));
double	limit(t_list *, double, double *, double *, double *);
double	x_top(double *, double, double *, double *, double *);
double	x_bot(double *, double, double *, double *, double *);
double	x_double(double *, double, double *, double *, double *);
double	y_top(double *, double, double *, double *, double *);
double	y_bot(double *, double, double *, double *, double *);
double	y_double(double *, double, double *, double *, double *);
double	z_top(double *, double, double *, double *, double *);
double	z_bot(double *, double, double *, double *, double *);
double	z_double(double *, double, double *, double *, double *);
void	delete_comment(char *);
double	scal_prod(double *, double *);
int	def_position(char *, t_list **);
int	def_angle(char *, t_list **);
int	def_rayon(char *, t_list **);
int	def_shine(char *, t_list **);
int	def_color(char *, t_list **);
int	def_damier(char *, t_list **);
int	def_limit(char *, t_list **);
int	define_color(t_spot *, int *);
int	set_background(t_env *, int *, int *);
void	ft_light(void (**)(double *, double *));
int	reflection(t_env *, int *, t_list *, t_list *);

#endif /* !RAYTRACER_H_ */
