#include "raytracer.h"

int		main(int ac, char **av)
{
  t_env		e;
  t_list	*shapes;

  shapes = NULL;
  e.light = NULL;
  if (ac < 2)
    {
      my_printf("Usage: ./rt config.rt\n", 1);
      return (0);
    }
  my_printf("\n\tRaytracer\nMinilibx initialisation...", 1);
  if ((init_env(&e)) == ERROR)
    return (ERROR);
  my_printf("Done\nParsing Scene...\n", 1);
  if (get_scene_from_files(av[1], &e, &shapes) == ERROR)
    return (ERROR);
  my_printf("Parsing Done !\n", 1);
  raytracer_introduction(&e, shapes);
  return (0);
}
