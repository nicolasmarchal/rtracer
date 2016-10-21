#include "raytracer.h"

void		rotate_z(double *v, double angle)
{
  double	tmp_x;
  double	tmp_y;

  tmp_x = v[0];
  tmp_y = v[1];
  angle = (angle * M_PI) / 180;
  v[0] = cos(angle) * tmp_x + (-sin(angle)) * tmp_y;
  v[1] = sin(angle) * tmp_x + cos(angle) * tmp_y;
}

void		rotate_y(double *v, double angle)
{
  double	tmp_x;

  tmp_x = v[0];
  angle = (angle * M_PI) / 180;
  v[0] = cos(angle) * tmp_x + sin(angle) * v[2];
  v[2] = -sin(angle) * tmp_x + cos(angle) * v[2];
}

void		rotate_x(double *v, double angle)
{
  double	tmp_y;

  tmp_y = v[1];
  angle = (angle * M_PI) / 180;
  v[1] = cos(angle) * tmp_y + (-sin(angle)) * v[2];
  v[2] = sin(angle) * tmp_y + cos(angle) * v[2];
}

void	rotate_axe(double *v, double *angle, char inverse)
{
  if (inverse == 0)
    {
      rotate_x(v, angle[0]);
      rotate_y(v, angle[1]);
      rotate_z(v, angle[2]);
    }
  else if (inverse == 1)
    {
      rotate_z(v, -angle[2]);
      rotate_y(v, -angle[1]);
      rotate_x(v, -angle[0]);
    }
}
