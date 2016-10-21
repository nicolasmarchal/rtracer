#include "raytracer.h"

int	which_ft_cam(char *line)
{
  char	*type[4];
  int	i;

  i = -1;
  type[0] = "POSITION";
  type[1] = "ANGLE";
  type[2] = "BACKGROUND";
  type[3] = NULL;
  while (type[++i] && check_match(type[i], line) != 0);
  if (i == 3)
    {
      my_printf("Use --help for the config file\n", 2);
      my_printf("\033[1;5;31mError:\033[0m Bad Data type ", 2);
      return (ERROR);
    }
  return (i);
}

int	def_position_cam(char *line, t_env *e)
{
  int	ret;

  ret = get_coord(line, e->cam.eye);
  if (ret == WARNING)
    my_printf(" camera position", 1);
  return (ret);
}

int	def_angle_cam(char *line, t_env *e)
{
  int	ret;

  ret = get_coord(line, e->cam.angle);
  if (ret == WARNING)
    my_printf(" camera rotation", 1);
  return (ret);
}

int	def_background_cam(char *line, t_env *e)
{
  int	i;

  i = -1;
  while (line[++i] && line[i] != ' ');
  my_printf("Loading %s texture....", 1, &line[++i]);
  if ((e->img2 = mlx_xpm_file_to_image(e->mlx, &line[i],
				       &e->cam.x_text, &e->cam.y_text)) == 0
      || (e->cam.texture = mlx_get_data_addr(e->img2, &e->bpp2,
					     &e->sizeline2, &e->endian2)) == 0)
    my_printf("Error\n", 1);
  else
    my_printf(" Ok\n", 1);
  return (0);
}

int	fill_cam(char *line, t_env *e)
{
  int	ret;

  if ((ret = which_ft_cam(line)) == ERROR)
    return (ERROR);
  if (ret == 0)
    ret = def_position_cam(line, e);
  if (ret == 1)
    ret = def_angle_cam(line, e);
  if (ret == 2)
    ret = def_background_cam(line, e);
  return (ret);
}
