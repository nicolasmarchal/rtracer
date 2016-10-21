#include "raytracer.h"

int	def_damier(char *line, t_list **shapes)
{
  int	ret;

  ret = get_a_color(line, &(*shapes)->damier);
  if (ret == WARNING)
    my_printf(" shape damier ", 1);
  return (ret);
}

void		inverse_arg(t_list **shapes)
{
  double	tmp;

  if ((*shapes)->limit[1] < (*shapes)->limit[2])
    {
      tmp = (*shapes)->limit[1];
      (*shapes)->limit[1] = (*shapes)->limit[2];
      (*shapes)->limit[2] = tmp;
    }
}

int	get_limit_value(t_list **shapes, char *line, int y)
{
  int	ret;
  int	i;

  i = -1;
  ret = get_one_value(line, &(*shapes)->limit[1]);
  if (ret == WARNING)
    {
      my_printf(" shape limit value\n", 1);
      return (WARNING);
    }
  while (line[++i] && line[i] != ' ');
  while (line[++i] && line[i] != ' ');
  if (!line[i] && (y == 2 || y == 5 || y == 8))
    {
      my_printf("\033[1;5;33mWarning:\033[0m Missing limit value ", 1);
      return (WARNING);
    }
  else if ((y == 2 || y == 5 || y == 8))
    {
      ret = get_one_value(&line[i], &(*shapes)->limit[2]);
      if (ret == WARNING)
	my_printf(" shape limit value\n", 1);
      inverse_arg(shapes);
    }
  return (ret);
}

int	def_limit(char *line, t_list **shapes)
{
  int	ret;
  int	i;
  int	y;
  char	*axe[10];

  i = -1;
  y = -1;
  axe[0] = "XTOP";
  axe[1] = "XBOT";
  axe[2] = "XDOUBLE";
  axe[3] = "YTOP";
  axe[4] = "YBOT";
  axe[5] = "YDOUBLE";
  axe[6] = "ZTOP";
  axe[7] = "ZBOT";
  axe[8] = "ZDOUBLE";
  axe[9] = NULL;
  while (line[++i] && line[i] != ' ');
  (line[i]) ? ++i : 0;
  while (axe[++y] && check_match(axe[y], &line[i]) != 0);
  if (y > 8)
    {
      my_printf("\033[1;5;33mWarning:\033[0m Invalid limit type ", 1);
      return (WARNING);
    }
  (*shapes)->limit[0] = (double)y;
  ret = get_limit_value(shapes, &line[i], y);
  if (ret == WARNING)
    (*shapes)->limit[0] = -1;
  return (ret);
}
