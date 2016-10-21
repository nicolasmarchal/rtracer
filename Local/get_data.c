#include "raytracer.h"

int	check_args(char *line)
{
  int	i;

  i = -1;
  if (line[0] == '-' || line[0] == '+')
    ++i;
  while (line[++i] && line[i] != ' ')
    {
      if ((line[i] < '0' || line[i] > '9') && line[i] != '.')
	return (WARNING);
    }
  return (0);
}

int	check_color(char *line)
{
  int	i;

  i = -1;
  while (line[++i])
    {
      if ((line[i] < '0' || line[i] > '9') && (line[i] < 'A' || line[i] > 'F'))
	return (WARNING);
    }
  return (0);
}

int	get_coord(char *line, double *coord)
{
  int	i;
  int	y;
  int	ret;

  i = -1;
  y = -1;
  ret = 0;
  while (line[++i] && line[i] != ' ');
  while (++y < 3 && line[i])
    {
      if ((check_args(&line[++i])) == WARNING && ret != WARNING)
	{
	  my_printf("\033[1;5;33mWarning:\033[0m Invalid ", 1);
	  ret = WARNING;
	}
      else
	coord[y] = atof(&line[i]);
      while (line[++i] && line[i] != ' ');
    }
  return (ret);
}

int	get_one_value(char *line, double *value)
{
  int	i;
  int	ret;

  i = -1;
  ret = 0;
  while (line[++i] && line[i] != ' ');
  if ((ret = check_args(&line[++i])) == WARNING)
    my_printf("\033[1;5;33mWarning:\033[0m Invalid", 1);
  else
    *value = atof(&line[i]);
  return (ret);
}

int	get_a_color(char *line, int *color)
{
  int	i;
  int	ret;

  i = -1;
  ret = 0;
  while (line[++i] && line[i] != ' ');
  if ((ret = check_color(&line[++i])) == WARNING)
    my_printf("\033[1;5;33mWarning:\033[0m Invalid", 1);
  else
    *color = my_getnbr_base(&line[i], "0123456789ABCDEF");
  return (ret);
}
