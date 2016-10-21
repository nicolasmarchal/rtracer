#ifndef SERVER_H_
# define SERVER_H_
# define THREAD_NUMBER 8
# define COLOR_SIZE 3
# include <sys/select.h>
# include "raytracer.h"

typedef struct	s_server
{
  int		highsock;
  int		sock_server;
  int		client[10];
  fd_set	sock_client;
}		t_server;

int	fill_image_with_client(t_env *, t_server *);
int	gere_sock(t_server *, int *, int *, t_env *);
int	built_select_list(t_server *);
int	check_pixels(int *);
int	raytracer_introduction_reseau(t_env *, t_server *);

#endif /* !SERVER_H_ */
