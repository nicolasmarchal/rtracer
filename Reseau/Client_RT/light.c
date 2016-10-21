#include "raytracer.h"

double		power_of_light(double *n, double *l)
{
  double	norme_n;
  double	norme_l;
  double	cosa;

  norme_n = sqrt(pow(n[0], 2) + pow(n[1], 2) + pow(n[2], 2));
  norme_l = sqrt(pow(l[0], 2) + pow(l[1], 2) + pow(l[2], 2));
  cosa = ((l[0] * n[0]) + (l[1] * n[1]) + (l[2] * n[2])) / (norme_l * norme_n);
  if (cosa < 0)
    cosa = 0;
  return (cosa);
}

void	ft_light(void (**ptf)(double *, double *))
{
  ptf[PLAN] = normale_plan;
  ptf[SPHERE] = normale_sphere;
  ptf[CYLINDER] = normale_cyl;
  ptf[CONE] = normale_cone;
  ptf[HYPERBOL] = normale_hyperbol;
  ptf[BOLOIDE] = normale_hyperboloid;
}

void		fill_color(int *final_color, t_spot *light, t_list *shape,
			   double cosa, double *p)
{
  double	shine;
  unsigned char	tmp[3];
  unsigned char	tmp2[3];
  int		color;

  color = shape->color;
  if (shape->damier != -1 && ((int)floor(p[0] / 20) +
			      (int)floor(p[1] / 40)) % 2 != 0)
    color = shape->damier;
  tmp[0]= color;
  tmp[1]= color >> 8;
  tmp[2]= color >> 16;
  shine = shape->shine;
  if (cosa > 0 && shine > 0)
    {
      tmp2[0] = light->color_spot;
      tmp2[1] = light->color_spot >> 8;
      tmp2[2] = light->color_spot >> 16;
      final_color[0] = (int)(((int)(tmp[0]) * cosa * (int)(tmp2[0]))
			     / 255  + shine * tmp2[0] * cosa);
      final_color[1] = (int)(((int)(tmp[1]) * cosa * (int)(tmp2[1]))
			     / 255  + shine * tmp2[1] * cosa);
      final_color[2] = (int)(((int)(tmp[2]) * cosa * (int)(tmp2[2]))
			     / 255  + shine * tmp2[2] * cosa);
      final_color[0] = COL(final_color[0], 0, 255);
      final_color[1] = COL(final_color[1], 0, 255);
      final_color[2] = COL(final_color[2], 0, 255);
    }
  else
    {
      final_color[0] = (int)(tmp[0] * cosa);
      final_color[1] = (int)(tmp[1] * cosa);
      final_color[2] = (int)(tmp[2] * cosa);
    }
}

double	shadow(t_list *shapes, double *l, double *p,
	       double cosa, t_list *inter)
{
  calc_k(shapes, p, l);
  while (shapes != NULL)
    {
      if (shapes != inter && shapes->k > 0 && shapes->k < 1)
	return (cosa * 0.4);
      shapes = shapes->next;
    }
  return (cosa);
}

int		lighting(t_env *e, t_list *shapes, t_list *inter,
			 double *eye, double *v)
{
  t_spot	*light;
  void		(*ptf[6])(double *, double *);
  double	p[3];
  double	n[3];
  double	l[3];
  double	cosa;

  ft_light(ptf);
  light = e->light;
  p[0] = eye[0] + inter->k * v[0];
  p[1] = eye[1] + inter->k * v[1];
  p[2] = eye[2] + inter->k * v[2];
  if (inter->shape != PLAN)
    rotate_axe(p, inter->angle, 1);
  (ptf[inter->shape])(p, n);
  if (inter->shape != PLAN)
    {
      rotate_axe(n, inter->angle, 0);
      rotate_axe(p, inter->angle, 0);
    }
  translate(n, inter->coord, n);
  while (light != NULL)
    {
      l[0] = light->coord[0] - p[0];
      l[1] = light->coord[1] - p[1];
      l[2] = light->coord[2] - p[2];
      cosa = 1;
      cosa = power_of_light(n, l);
      cosa = shadow(shapes, l, p, cosa, inter);
      fill_color(light->color, light, inter, cosa, p);
      light = light->next;
    }
  return (0);
}
