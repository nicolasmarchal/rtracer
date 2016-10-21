#include "raytracer.h"

int	mlx_put_pixel_to_img(t_env *e, int x, int y, int *color)
{
  int	pos;

  pos = (((e->bpp) / 8) * x) + (e->sizeline * y);
  e->data[pos] = color[0];
  e->data[pos + 1] = color[1];
  e->data[pos + 2] = color[2];
  return (0);
}

int	gere_key(int keycode, t_env *e)
{
  if (keycode == ECHAP)
    {
      mlx_destroy_window(e->mlx, e->win);
      exit(1);
    }
  return (0);
}

int	gere_expose(t_env *e)
{
  mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
  return (0);
}

int	init_env(t_env *e)
{
  if ((e->mlx = mlx_init()) == 0 ||
      (e->img = mlx_new_image(e->mlx, WIDTH, HEIGHT)) == 0 ||
      (e->data = mlx_get_data_addr(e->img, &e->bpp, &e->sizeline,
  				   &e->endian)) == 0)
    return (ERROR);
  e->cam.x_text = 0;
  e->cam.y_text = 0;
  e->cam.texture = NULL;
  return (0);
}
