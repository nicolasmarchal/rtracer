#include "raytracer.h"

int	check_name(char *file)
{
  int	i;

  i = my_strlen(file);
  while (--i >= 0 && file[i] != '.');
  ++i;
  if (file[i] == 'r' && file[i + 1] == 't' && file[i + 2] == 0)
    return (1);
  if (file[i] == 'o' && file[i + 1] == 'b' &&
      file[i + 2] == 'j' && file[i + 3] == 0)
    return (2);
  return (ERROR);
}

int	get_scene_from_files(char *file, t_env *e, t_list **shapes)
{
  int	fd;
  int	file_type;

  if ((file_type = check_name(file)) == ERROR)
    {
      my_printf("\033[1;5;31mError:\033[0m Bad Extention !\n", 2);
      return (ERROR);
    }
  if ((fd = open(file, O_RDONLY)) == ERROR)
    {
      my_printf("\033[1;5;31mError:\033[0m File %s is not accessible !\n"
		, 2, file);
      return (ERROR);
    }
  if ((get_scene(fd, e, shapes)) == ERROR)
    return (ERROR);
  close(fd);
  return (file_type);
}
