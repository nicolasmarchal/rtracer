#include <unistd.h>
#include "raytracer.h"
#include "my.h"
#include "client.h"

void	init_tabl(int *tabl)
{
  int	i;

  tabl[0] = -1;
  i = 0;
  while (++i <= THREAD_NUMBER * COLOR_SIZE)
    tabl[i] = 0;
}

void	init_xy(int *xy, int tabl)
{
  int	index;

  index = -1;
  while (++index < THREAD_NUMBER)
    {
      xy[index * 2] = (tabl + index) % WIDTH;
      xy[index * 2 + 1] = (tabl + index) / WIDTH;
      if ((tabl + index) > WIDTH * HEIGHT)
	{
	  xy[index * 2] = -1;
	  xy[index * 2 + 1] = -1;
	}
    }
}

int	send_and_receive_pixels(t_client *client, t_env *e, t_list *shapes)
{
  t_trd	st;
  int	ret;

  st.client = client;
  st.e = e;
  st.shapes = shapes;
  init_tabl(st.tabl);
  while (42)
    {
      st.index = 0;
      if (st.tabl[0] != -1)
	{
	  if (do_threading(&st) == 0)
	    return (0);
	}
      if (write(client->sock, &st.tabl[0], sizeof(int) *
		(1 + COLOR_SIZE * THREAD_NUMBER)) == -1)
        return (err_putstr("Failed to write\n"));
      init_tabl(st.tabl);
      if ((ret = read(client->sock, &st.tabl[0], sizeof(int))) <= 0)
        return (err_putstr("Connection lost with server\n"));
      init_xy(st.xy_full, st.tabl[0]);
    }
  return (1);
}
