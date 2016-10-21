#include "raytracer.h"

int	send_pixel(t_env *e, t_list *shapes, int x, int y)
{
  int	xy[2];
  int	color[3];

  xy[0] = x;
  xy[1] = y;
  color[0] = 0;
  color[1] = 0;
  color[2] = 0;
  calc_color_pixel(e, shapes, xy, color);
  mlx_put_pixel_to_img(e, x, y, color);
  return (0);
}

int	fill_pixel_image(t_env *e, t_list *shapes)
{
  int	x;
  int	y;
  int	ratio;
  char	*loading;

  y = -1;
  ratio = 0;
  if ((loading = my_strdup("[                    ]")) == NULL)
    return (ERROR);
  while (++y <= HEIGHT)
    {
      x = -1;
      while (++x <= WIDTH)
	send_pixel(e, shapes, x, y);
      print_loading_bar(y, &ratio, loading);
    }
  my_printf("\n\033[27;32mDone !\033[0m\n", 1);
  free(loading);
  return (0);
}

int	raytracer_introduction(t_env *e, t_list *shapes)
{
  if ((fill_pixel_image(e, shapes)) == ERROR)
    return (ERROR);
  if ((e->win = mlx_new_window(e->mlx, WIDTH, HEIGHT, WINDOWS_NAME)) == 0)
    return (ERROR);
  mlx_hook(e->win, KeyPress, KeyRelease, gere_key, e);
  mlx_expose_hook(e->win, gere_expose, e);
  mlx_loop(e->mlx);
  return (0);
}
