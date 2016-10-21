#include "raytracer.h"

int	which_ft_light(char *line)
{
  char	*type[3];
  int	i;

  i = -1;
  type[0] = "POSITION";
  type[1] = "COLOR";
  type[2] = NULL;
  while (type[++i] && check_match(type[i], line) != 0);
  if (i == 2)
    {
      my_printf("Use --help for the config file\n", 2);
      my_printf("\033[1;5;31mError:\033[0m Bad Data type ", 2);
      return (ERROR);
    }
  return (i);
}

int	def_position_light(char *line, t_spot *light)
{
  int	ret;

  ret = get_coord(line, light->coord);
  if (ret == WARNING)
    my_printf(" light position ", 1);
  return (ret);
}

int	def_color_light(char *line, t_spot *light)
{
  int	ret;

  ret = get_a_color(line, &light->color_spot);
  if (ret == WARNING)
    my_printf(" light color", 1);
  return (ret);
}

int	fill_light(char *line, t_spot *light)
{
  int	ret;

  if ((ret = which_ft_light(line)) == ERROR)
    return (ERROR);
  if (ret == 0)
    ret = def_position_light(line, light);
  else if (ret == 1)
    ret = def_color_light(line, light);
  return (0);
}
