#include "raytracer.h"

double		delta_solution(double delta, double *eq)
{
  double	k;
  double	k2;

  if (delta >= 0)
    {
      k = (-eq[1] - sqrt(delta)) / (2 * eq[0]);
      k2 = (-eq[1] + sqrt(delta)) / (2 * eq[0]);
      if (k2 > EPS && (k2 < k || k < EPS))
	return (k2);
      else if (k > EPS && (k < k2 || k2 < EPS))
	return (k);
    }
  return (-1);
}
