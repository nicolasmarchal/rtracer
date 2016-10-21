#include "raytracer.h"
#include "client.h"

void	init_vector(t_env *e, int x, int y)
{
  e->cam.v[0] = 300;
  e->cam.v[1] = WIDTH / 2 - (double)x;
  e->cam.v[2] = HEIGHT /2 - (double)y;
}

void	ft_shape(int (**ptf)(t_list *, double *, double *))
{
  ptf[PLAN] = inter_plan;
  ptf[SPHERE] = inter_sphere;
  ptf[CYLINDER] = inter_cyl;
  ptf[CONE] = inter_cone;
  ptf[HYPERBOL] = inter_hyperbol;
  ptf[BOLOIDE] = inter_hyperboloid;
}

int		calc_k(t_list *shapes, double *eye, double *v)
{
  t_list	*tmp;
  int		(*ptf[6])(t_list *, double *, double *);

  tmp = shapes;
  ft_shape(ptf);
  while (tmp != NULL)
    {
      (*ptf[tmp->shape])(tmp, eye, v);
      tmp = tmp->next;
    }
  return (0);
}

t_list		*find_first_inter(t_list *shapes)
{
  t_list	*tmp;
  t_list	*first_inter;

  tmp = shapes;
  first_inter = shapes;
  while (tmp != NULL)
    {
      if (first_inter->k < 0 && tmp->k > 0)
	first_inter = tmp;
      else if (tmp->k > 0 && tmp->k < first_inter->k)
	first_inter = tmp;
      tmp = tmp->next;
    }
  return (first_inter);
}

void		*calc_color_pixel(void *tmp)
{
  t_trd		*st;
  t_env		*e;
  t_list	*shapes;
  int		*xy;
  int		*color;
  t_list	*inter;

  inter = NULL;
  st = (t_trd *)tmp;
  e = st->e;
  shapes = st->shapes;
  xy = &st->xy_full[st->index * 2];
  color = &st->tabl[st->index * COLOR_SIZE + 1];
  init_vector(e, xy[0], xy[1]);
  rotate_axe(e->cam.v, e->cam.angle, 0);
  if (shapes != NULL)
    {
      calc_k(shapes, e->cam.eye, e->cam.v);
      inter = find_first_inter(shapes);
    }
  if (inter && inter->k > 0)
    {
      lighting(e, shapes, inter, e->cam.eye, e->cam.v);
      define_color(e->light, color);
      //    reflection(e, color, inter, shapes);
      //transparence(e, color, inter, shapes);
    }
  else
    set_background(e, xy, color);
  return (tmp);
}
