# include "raytracer.h"

int	set_background(t_env *e, int *xy, int *color)
{
  int	pos;

  if (e->cam.texture != NULL && xy[0] <= e->cam.x_text && xy[1]
      <= e->cam.y_text)
    {
      pos = (((e->bpp2) / 8) * xy[0]) + (e->sizeline2 * xy[1]);
      color[0] = e->cam.texture[pos];
      color[1] = e->cam.texture[pos + 1];
      color[2] = e->cam.texture[pos + 2];
      return (0);
    }
  color[0] = 0;
  color[1] = 0;
  color[2] = 0;
  return (0);
}
