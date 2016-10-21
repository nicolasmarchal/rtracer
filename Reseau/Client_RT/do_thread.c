#include <pthread.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include "client.h"
#include "server.h"
#include "raytracer.h"

int		do_threading(t_trd *st)
{
  int		i;
  pthread_t	threads[THREAD_NUMBER];

  i = -1;
  while (++i < THREAD_NUMBER)
    {
      if (pthread_create(&threads[i], NULL, calc_color_pixel, (void *)st) == -1)
	return (0);
      pthread_join(threads[i], NULL);
      ++st->index;
    }
  return (1);
}
