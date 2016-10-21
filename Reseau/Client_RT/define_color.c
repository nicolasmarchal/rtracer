#include "raytracer.h"

int	nb_light(t_spot *light)
{
  int	i;

  i = 0;
  while (light != NULL)
    {
      ++i;
      light = light->next;
    }
  return (i);
}

int	define_color(t_spot *light, int *color)
{
  int	len;

  len = nb_light(light);
  while (light != NULL)
    {
      color[0] += light->color[0];
      color[1] += light->color[1];
      color[2] += light->color[2];
      light = light->next;
    }
  color[0] /= len;
  color[1] /= len;
  color[2] /= len;
  return (0);
}
