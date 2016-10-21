#include "raytracer.h"

void	transp_color(int *color, t_env *e, t_list *new_inter, t_list *shapes)
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
  color[0] = tmp2[0] * 0.4 + color[0] * (1 - 0.4);
  color[1] = tmp2[1] * 0.4 + color[1] * (1 - 0.4);
  color[2] = tmp2[2] * 0.4 + color[2] * (1 - 0.4);
  color[0] = COL(color[0], 0, 255);
  color[1] = COL(color[1], 0, 255);
  color[2] = COL(color[2], 0, 255);
}

int	transparence(t_env *e, int *color, t_list *inter, t_list *shapes)
{
  double	norme_v[3];
  double	norme_n[3];
  double	scal;
  double	n[3];
  double	trans[3];
  double	tmp;
  double	indice;
  t_list	*new_inter;
  double	pos_inter[3];
  void		(*ptfunc[4])(t_list *, double *, double *);

  pos_inter[0] = e->cam.eye[0] + inter->k * e->cam.v[0];
  pos_inter[1] = e->cam.eye[1] + inter->k * e->cam.v[1];
  pos_inter[2] = e->cam.eye[2] + inter->k * e->cam.v[2];
  ft_light(&ptfunc);
  (*ptfunc[inter->shape])(inter, pos_inter, n);
  norme(n, norme_n);
  norme(e->cam.v, norme_v);
  scal = scal_prod(norme_v, norme_n);
  indice = 1.517;
  tmp = 1.0 + (indice * indice) * ((scal * scal) - 1.0);
  tmp = (tmp > 0) ? sqrt(tmp) : 0;
  trans[0] = indice * norme_v[0] +
    (indice * scal - tmp) * norme_n[0];
  trans[1] = indice * norme_v[1] +
    (indice * scal - tmp) * norme_n[1];
  trans[2] = indice * norme_v[2] +
    (indice * scal - tmp) * norme_n[2];
  calc_k(shapes, pos_inter, trans);
  new_inter = first_inter(shapes, inter);
  if (new_inter->k > 0 && inter->shape != 0 && inter->shape != new_inter->shape && inter->shape == SPHERE)
    {
      lighting(e, shapes, new_inter, pos_inter, trans);
      transp_color(color, e, new_inter, shapes);
    }
  return (0);
}
