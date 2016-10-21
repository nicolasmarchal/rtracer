#include <unistd.h>
#include <sys/time.h>
#include <sys/select.h>
#include <sys/types.h>
#include "my.h"
#include "server.h"
#include "raytracer.h"

int	check_pixels(int *rec_tabl)
{
  int	i;
  int	lim;

  i = 0;
  lim = 1 + THREAD_NUMBER * COLOR_SIZE;
  if (rec_tabl[0] < -1)
    return (0);
  while (++i < lim)
    {
      if (rec_tabl[i] < -1 || rec_tabl[i] > 255)
        return (0);
    }
  return (1);
}

int			fill_image_with_client(t_env *e, t_server *server)
{
  struct timeval	timeout;
  char			*loading;
  int			ratio;
  int			ret;
  int			y;
  int			x;

  ratio = 0;
  if ((loading = my_strdup("[                    ]")) == NULL)
    return (0);
  y = -1;
  while (++y <= WIDTH)
    {
      x = 0;
      while (x <= HEIGHT)
	{
          built_select_list(server);
          timeout.tv_sec = 1;
          timeout.tv_usec = 0;
          if ((ret = select(server->highsock + 1, &server->sock_client, NULL,
			    NULL, &timeout)) == -1)
            return (err_putstr("Error on select\n"));
          if (ret == 0)
	    write(1, "#", 1);
          else
            {
              if (gere_sock(server, &x, &y, e) == 0)
		return (0);
            }
	}
      print_loading_bar(y, &ratio, loading);
    }
  my_printf("\n\033[27;32mDone !\033[0m\n", 1);
  free(loading);
  return (1);
}

int	raytracer_introduction_reseau(t_env *e, t_server *server)
{
  if (fill_image_with_client(e, server) == 0)
    return (0);
  if ((e->win = mlx_new_window(e->mlx, WIDTH, HEIGHT, WINDOWS_NAME)) == 0)
    return (0);
  mlx_hook(e->win, KeyPress, KeyRelease, gere_key, e);
  mlx_expose_hook(e->win, gere_expose, e);
  mlx_loop(e->mlx);
  return (1);
}
