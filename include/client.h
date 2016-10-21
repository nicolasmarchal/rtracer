#ifndef CLIENT_H_
# define CLIENT_H_
# define THREAD_NUMBER 8
# define COLOR_SIZE 3
# include "raytracer.h"

typedef struct	s_client
{
  int		values[4];
  int		sock;
  fd_set	set;
}		t_client;

typedef struct	s_thread
{
  t_client	*client;
  t_env		*e;
  t_list	*shapes;
  int		xy_full[2 * THREAD_NUMBER];
  int		tabl[1 + THREAD_NUMBER * COLOR_SIZE];
  int		index;
}		t_trd;

void	init_tabl(int *);
char	*find_ip();
int	create_client(t_client *);
int	send_and_receive_pixels(t_client *, t_env *, t_list *);
int	do_threading(t_trd *);

#endif /* !CLIENT_H_ */
