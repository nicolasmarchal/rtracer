#include "raytracer.h"

int		inter_cone(t_list *shape, double *eye, double *v)
{
  double	delta;
  double	pos[3];
  double	vector[3];
  double	eq[3];
  double	angle;

  angle = (shape->rayon * M_PI) / 180;
  vector[0] = v[0];
  vector[1] = v[1];
  vector[2] = v[2];
  translate(eye, shape->coord, pos);
  rotate_axe(pos, shape->angle, 1);
  rotate_axe(vector, shape->angle, 1);
  eq[0] = pow(vector[0], 2) + pow(vector[1], 2) - pow(vector[2], 2) * angle;
  eq[1] = 2 * (pos[0] * vector[0] + vector[1] * pos[1] - pos[2] * vector[2] * angle);
  eq[2] = pow(pos[0], 2) + pow(pos[1], 2) - pow(pos[2], 2) * angle;
  delta = pow(eq[1], 2) - (4 * eq[0] * eq[2]);
  shape->k = limit(shape, delta, eq, pos, vector);
  return (0);
}

void	normale_cone(double *p, double *n)
{
  n[0] = p[0];
  n[1] = p[1];
  n[2] = p[2] * 0.05;
}
