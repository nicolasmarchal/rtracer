#include "raytracer.h"

int		inter_plan(t_list *shape, double *eye, double *v)
{
  double	pos[3];
  double	vector[3];

  translate(eye, shape->coord, pos);
  vector[0] = v[0];
  vector[1] = v[1];
  vector[2] = v[2];
  rotate_axe(pos, shape->angle, 1);
  rotate_axe(vector, shape->angle, 1);
  if (abs(vector[2]) == 0.000000000000000000001)
    shape->k = 0.000001;
  else
    shape->k = -pos[2] / vector[2];
  return (0);
}

void	normale_plan(UNU double *p, double *n)
{
  n[0] = 0;
  n[1] = 0;
  n[2] = 100;
}
