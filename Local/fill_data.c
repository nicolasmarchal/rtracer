#include "raytracer.h"

int	define_type(char *line, t_env *e, t_list **shapes)
{
  int	i;
  char	*type[8];

  i = -1;
  type[0] = "PLAN";
  type[1] = "SPHERE";
  type[2] = "CYLINDER";
  type[3] = "CONE";
  type[4] = "HYPERBOL";
  type[5] = "BOLOIDE";
  type[6] = "EYE";
  type[7] = "LIGHT";
  type[8] = NULL;
  while (type[++i] && my_strcmp(type[i], line) != 0);
  if (i >= 0 && i <= 5)
    {
      if ((my_put_in_list(shapes, i)) == ERROR)
	return (ERROR);
    }
  else if (i == 7)
    {
      if ((my_put_in_light(&e->light)) == ERROR)
	return (ERROR);
    }
  return (i);
}

int	fill_data(char *line, t_env *e, t_list **shapes, int *ident)
{
  int	ret;

  epur_str(line);
  if ((ret = define_type(line, e, shapes)) != 8)
    {
      *ident = ret;
      return (ret);
    }
  if (*ident >= 0 && *ident <= 5)
    ret = fill_shapes(line, shapes);
  if (*ident == 6)
    ret = fill_cam(line, e);
  else if (*ident == 7)
    ret = fill_light(line, e->light);
  return (ret);
}

int	get_scene(int fd, t_env *e, t_list **shapes)
{
  char	*line;
  int	ident;
  int	n_line;
  int	ret;

  ident = 0;
  n_line = 0;
  while ((line = get_next_line(fd)))
    {
      ++n_line;
      delete_comment(line);
      if ((line[0] != 0) && ((ret = fill_data(line, e, shapes, &ident))
			     == ERROR || ret == WARNING))
	{
	  my_printf("on line %d\n", 1, n_line);
	  if (ret == ERROR)
	    return (ERROR);
	}
      free(line);
    }
  return (0);
}
