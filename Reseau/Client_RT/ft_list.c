#include "raytracer.h"

int		my_put_in_list(t_list **list, int shape)
{
  t_list	*new;

  if ((new = malloc(sizeof(*new))) == NULL)
    return (ERROR);
  new->shape = shape;
  new->coord[0] = -1;
  new->coord[1] = -1;
  new->coord[2] = -1;
  new->angle[0] = 0;
  new->angle[1] = 0;
  new->angle[2] = 0;
  new->rayon = 0;
  new->shine = 0;
  new->k = -1;
  new->damier = -1;
  new->color = 0xffffff;
  new->limit[0] = -1;
  new->limit[1] = -1;
  new->limit[2] = -1;
  new->next = *list;
  *list = new;
  return (0);
}

int		my_put_in_light(t_spot **light)
{
  t_spot	*new;

  if ((new = malloc(sizeof(*new))) == NULL)
    return (ERROR);
  new->coord[0] = 0;
  new->coord[1] = 0;
  new->coord[2] = 0;
  new->color_spot = 0;
  new->next = *light;
  *light = new;
  return (0);
}
