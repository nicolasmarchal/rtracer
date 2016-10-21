#include "raytracer.h"

int	def_position(char *line, t_list **shapes)
{
  int	ret;

  ret = get_coord(line, (*shapes)->coord);
  if (ret == WARNING)
    my_printf(" shape position ", 1);
  return (ret);
}

int	def_angle(char *line, t_list **shapes)
{
  int	ret;

  ret = get_coord(line, (*shapes)->angle);
  if (ret == WARNING)
    my_printf(" shape rotation ", 1);
  return (ret);
}

int	def_rayon(char *line, t_list **shapes)
{
  int	ret;

  ret = get_one_value(line, &(*shapes)->rayon);
  if (ret == WARNING)
    my_printf(" shape rayon", 1);
  return (ret);
}

int	def_shine(char *line, t_list **shapes)
{
  int	ret;

  ret = get_one_value(line, &(*shapes)->shine);
  if (ret == WARNING)
    my_printf(" shape shine", 1);
  return (ret);
}

int	def_color(char *line, t_list **shapes)
{
  int	ret;

  ret = get_a_color(line, &(*shapes)->color);
  if (ret == WARNING)
    my_printf(" shape color ", 1);
  return (ret);
}
