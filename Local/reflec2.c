#include "raytracer.h"

void	norme(double v[3], double norme_v[3])
{
  double	norme;

  norme = sqrt((pow(v[0], 2)) + (pow(v[1], 2)) + (pow(v[2], 2)));
  norme_v[0] = v[0] / norme;
  norme_v[1] = v[1] / norme;
  norme_v[2] = v[2] / norme;
}

double	scal_prod(double *norme_v, double *norme_n)
{
  double scal;

  scal = (norme_v[0] * norme_n[0]) +
    (norme_v[1] * norme_n[1]) + (norme_v[2] * norme_n[2]);
  return (scal);
}

void	reflec_color(int *color, t_env *e, t_list *new_inter, UNU t_list *shapes)
{
  unsigned char	tmp[3];
  int		tmp2[3];

  tmp[0] = new_inter->color;
  tmp[1] = new_inter->color >> 8;
  tmp[2] = new_inter->color >> 16;
  tmp2[0] = (int)tmp[0];
  tmp2[1] = (int)tmp[1];
  tmp2[2] = (int)tmp[2];
  define_color(e->light, tmp2);
  if (tmp2[0] > 0)
    tmp2[0] = tmp2[0] - 240;
  if (tmp2[1] > 0)
    tmp2[1] = tmp2[1] - 240;
  if (tmp2[2] > 0)
    tmp2[2] = tmp2[2] - 240;
  color[0] = tmp2[0] * 0.5 + color[0] * (1.0 - 0.5);
  color[1] = tmp2[1] * 0.5 + color[1] * (1.0 - 0.5);
  color[2] = tmp2[2] * 0.5 + color[2] * (1.0 - 0.5);
  color[0] = COL(color[0], 0, 255);
  color[1] = COL(color[1], 0, 255);
  color[2] = COL(color[2], 0, 255);
}

t_list		*first_inter(t_list *shapes, t_list *inter)
{
  t_list	*tmp;
  t_list	*first_inter;

  tmp = shapes;
  first_inter = shapes;
  while (tmp != NULL)
    {
      if (tmp != inter && first_inter->k < 0 && tmp->k > 0)
        first_inter = tmp;
      else if (tmp != inter && tmp->k > 0 && tmp->k < first_inter->k && first_inter->k > 0)
        first_inter = tmp;
      tmp = tmp->next;
    }
  return (first_inter);
}

int	reflection(t_env *e, int *color, t_list *inter, t_list *shapes)
{
  double	norme_v[3];
  double	norme_n[3];
  double	n[3];
  double	reflec[3];
  double	scal;
  double	pos_inter[3];
  t_list	*new_inter;
  void		(*ptfunc[4])(double *, double *);

  pos_inter[0] = e->cam.eye[0] + inter->k * e->cam.v[0];
  pos_inter[1] = e->cam.eye[1] + inter->k * e->cam.v[1];
  pos_inter[2] = e->cam.eye[2] + inter->k * e->cam.v[2];
  ft_light(ptfunc);
  (*ptfunc[inter->shape])(pos_inter, n);
  norme(n, norme_n);
  norme(e->cam.v, norme_v);
  scal = scal_prod(norme_v, norme_n);
  reflec[0] = -2.0 * norme_n[0] * (scal) + norme_v[0];
  reflec[1] = -2.0 * norme_n[1] * (scal) + norme_v[1];
  reflec[2] = -2.0 * norme_n[2] * (scal) + norme_v[2];
  calc_k(shapes, pos_inter, reflec);
  new_inter = first_inter(shapes, inter);
  if (new_inter->k > 0 && (inter->shape != 0 || new_inter->shape != 0) && inter->shape == 1)
    {
      lighting(e, shapes, new_inter, pos_inter, reflec);
      reflec_color(color, e, new_inter, shapes);
    }
  return (0);
}
