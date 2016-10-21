#include "raytracer.h"

double		y_top(double *limit, double delta, double *eq,
		      double *pos, double *vector)
{
  double	k;
  double	k2;
  double	k_pos;
  double	k2_pos;

  if (delta >= 0)
    {
      k = (-eq[1] - sqrt(delta)) / (2 * eq[0]);
      k2 = (-eq[1] + sqrt(delta)) / (2 * eq[0]);
      k_pos = pos[1] + (k * vector[1]);
      k2_pos = pos[1] + (k2 * vector[1]);
      if (k > 0 && k_pos < limit[1] && ((k2 > 0 && k < k2) ||
					(k > k2 && k2_pos > limit[1])))
        return (k);
      else if (k2 > 0 && k2_pos < limit[1] && ((k > 0 && k2 < k) ||
					       (k2 > k && k_pos > limit[1])))
        return (k2);
    }
  return (-1);
}

double		y_bot(double *limit, double delta, double *eq,
		      double *pos, double *vector)
{
  double	k;
  double	k2;
  double	k_pos;
  double	k2_pos;

  if (delta >= 0)
    {
      k = (-eq[1] - sqrt(delta)) / (2 * eq[0]);
      k2 = (-eq[1] + sqrt(delta)) / (2 * eq[0]);
      k_pos = pos[1] + (k * vector[1]);
      k2_pos = pos[1] + (k2 * vector[1]);
      if (k > 0 && k_pos > limit[1] && ((k2 > 0 && k < k2) ||
					(k > k2 && k2_pos < limit[1])))
        return (k);
      else if (k2 > 0 && k2_pos > limit[1] && ((k > 0 && k2 < k) ||
					       (k2 > k && k_pos < limit[1])))
        return (k2);
    }
  return (-1);
}

double		y_double(double *limit, double delta, double *eq,
			 double *pos, double *vector)
{
  double	k;
  double	k2;
  double	k_pos;
  double	k2_pos;

  if (delta >= 0)
    {
      k = (-eq[1] - sqrt(delta)) / (2 * eq[0]);
      k2 = (-eq[1] + sqrt(delta)) / (2 * eq[0]);
      k_pos = pos[1] + (k * vector[1]);
      k2_pos = pos[1] + (k2 * vector[1]);
      if (k > 0 && k_pos < limit[1] && k_pos > limit[2] &&
          ((k2 > 0 && k < k2) || (k > k2 && (k2_pos > limit[1]
                                             || k2_pos < limit[2]))))
        return (k);
      else if (k2 > 0 && k2_pos < limit[1] && k2_pos > limit[2] &&
	       ((k > 0 && k2 < k) || (k2 > k && (k_pos > limit[1]
						 || k_pos < limit[2]))))
        return (k2);
    }
  return (-1);
}
