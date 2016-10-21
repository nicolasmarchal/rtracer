#include "raytracer.h"

int	check_match(char *s1, char *s2)
{
  int	i;

  i = -1;
  while (s1[++i] && s2[i] && s2[i] != ' ')
    {
      if (s1[i] != s2[i])
	return (s1[i] - s2[i]);
    }
  if (s1[i])
    return (s1[i] - s2[i]);
  return (0);
}

int	which_data(char *line)
{
  char	*type[8];
  int	i;

  i = -1;
  type[0] = "POSITION";
  type[1] = "ANGLE";
  type[2] = "RAYON";
  type[3] = "SHINE";
  type[4] = "COLOR";
  type[5] = "DAMIER";
  type[6] = "LIMIT";
  type[7] = NULL;
  while (type[++i] && check_match(type[i], line) != 0);
  if (i == 7)
    {
      my_printf("Use --help for the config file\n", 2);
      my_printf("\033[1;5;31mError:\033[0m Bad Data type ", 2);
      return (ERROR);
    }
  return (i);
}

int	fill_shapes(char *line, t_list **shapes)
{
  int	which_ft;
  int	ret;
  int	(*ptf[7])(char *, t_list **);

  ptf[0] = def_position;
  ptf[1] = def_angle;
  ptf[2] = def_rayon;
  ptf[3] = def_shine;
  ptf[4] = def_color;
  ptf[5] = def_damier;
  ptf[6] = def_limit;
  if ((which_ft = which_data(line)) == ERROR)
    return (ERROR);
  ret = (*ptf[which_ft])(line, shapes);
  return (ret);
}
