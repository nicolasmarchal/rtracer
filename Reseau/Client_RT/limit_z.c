#include "raytracer.h"

void		init_ptr(double (*limit_ptr[9])
				 (double *, double, double *, double *, double *))
{
  limit_ptr[0] = &x_top;
  limit_ptr[1] = &x_bot;
  limit_ptr[2] = &x_double;
  limit_ptr[3] = &y_top;
  limit_ptr[4] = &y_bot;
  limit_ptr[5] = &y_double;
  limit_ptr[6] = &z_top;
  limit_ptr[7] = &z_bot;
  limit_ptr[8] = &z_double;
}

double		limit(t_list *shape, double delta, double *eq,
		      double *pos, double *vector)
{
  double	(*limit_ptr[9])
    (double *, double, double *, double *, double *);

  init_ptr(limit_ptr);
  if (shape->limit[0] != -1)
    return (limit_ptr[(int)shape->limit[0]]
	    (shape->limit, delta, eq, pos, vector));
  return (delta_solution(delta, eq));
}

double		z_top(double *limit, double delta, double *eq,
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
      k_pos = pos[2] + (k * vector[2]);
      k2_pos = pos[2] + (k2 * vector[2]);
      if (k > 0 && k_pos < limit[1] && ((k2 > 0 && k < k2)
					|| (k > k2 && k2_pos > limit[1])))
      	return (k);
      else if (k2 > 0 && k2_pos < limit[1] && ((k > 0 && k2 < k)
					       || (k2 > k && k_pos > limit[1])))
      	return (k2);
    }
  return (-1);
}

double		z_bot(double *limit, double delta, double *eq,
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
      k_pos = pos[2] + (k * vector[2]);
      k2_pos = pos[2] + (k2 * vector[2]);
      if (k > 0 && k_pos > limit[1] && ((k2 > 0 && k < k2) ||
					(k > k2 && k2_pos < limit[1])))
      	return (k);
      else if (k2 > 0 && k2_pos > limit[1] && ((k > 0 && k2 < k) ||
					       (k2 > k && k_pos < limit[1])))
      	return (k2);
    }
  return (-1);
}

double		z_double(double *limit, double delta, double *eq,
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
      k_pos = pos[2] + (k * vector[2]);
      k2_pos = pos[2] + (k2 * vector[2]);
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
