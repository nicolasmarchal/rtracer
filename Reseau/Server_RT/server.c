#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdlib.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <fcntl.h>
#include "my.h"
#include "server.h"
#include "raytracer.h"

int	query_port()
{
  int	nb;
  char	*str;

  my_putstr("Enter a port : ");
  if ((str = get_next_line(0)) == NULL)
    return (0);
  nb = my_getnbr(str);
  free(str);
  return (nb);
}

int			create_server(t_server *server)
{
  struct sockaddr_in	server_address;
  int			reuse_addr;

  reuse_addr = 1;
  my_putstr("Creation of the server\n");
  if ((server->sock_server = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    return (err_putstr("Error during creation of socket\n"));
  setsockopt(server->sock_server, SOL_SOCKET, SO_REUSEADDR,
	     &reuse_addr, sizeof(reuse_addr));
  bzero((void *)&server_address, sizeof(struct sockaddr_in *));
  server_address.sin_family = AF_INET;
  server_address.sin_addr.s_addr = htonl(INADDR_ANY);
  server_address.sin_port = htons(query_port());
  if (bind(server->sock_server, (struct sockaddr *)&server_address,
           sizeof(server_address)) < 0)
    return (err_putstr("Failed to bind\n"));
  if (listen(server->sock_server, 10) == -1)
    return (err_putstr("Failed to listen"));
  server->highsock = server->sock_server;
  memset((char *)&server->client, 0, sizeof(server->client));
  my_putstr("OK.\nWaiting for connections\n");
  return (1);
}

int	new_sock(t_server *server)
{
  int	client;
  int	i;

  i = -1;
  if ((client = accept(server->sock_server, NULL, NULL)) == -1)
    return (err_putstr("Failed to accept\n"));
  while (++i < 10 && client != -1)
    {
      if (server->client[i] == 0)
	{
	  my_printf("\nNew Connection, FD = %d Slot = %d\n", 1, client, i);
	  server->client[i] = client;
	  client = -1;
	}
    }
  if (client != -1)
    {
      my_printf("No room for the client\n", 1);
      close(client);
    }
  return (1);
}

int	send_value(int client, int *x, int *y, t_env *e)
{
  int	value;
  int	index;
  int	rec_tabl[1 + THREAD_NUMBER * COLOR_SIZE];

  index = -1;
  if (read(client, &rec_tabl[0], sizeof(int) *
	   (1 + THREAD_NUMBER * COLOR_SIZE)) == -1)
    return (err_putstr("Failed to read\n"));
  if (check_pixels(rec_tabl) == 0)
    return (err_putstr("Invalid pixels received\n"));
  if (rec_tabl[0] != -1)
    {
      while (++index < THREAD_NUMBER)
	{
	  if (rec_tabl[index * COLOR_SIZE + 1] != -1 ||
	      rec_tabl[index * COLOR_SIZE + 2] != -1 ||
	      rec_tabl[index * COLOR_SIZE + 3] != -1)
	    mlx_put_pixel_to_img(e, (rec_tabl[0] + index) % WIDTH,
				 (rec_tabl[0] + index) / WIDTH,
				 &rec_tabl[index * COLOR_SIZE + 1]);
	}
    }
  value = *y * WIDTH + *x;
  write(client, &value, sizeof(int));
  *x = *x + THREAD_NUMBER;
  return (1);
}

int	gere_sock(t_server *server, int *x, int *y, t_env *e)
{
  int	i;

  i = -1;
  if (FD_ISSET(server->sock_server, &server->sock_client))
    new_sock(server);
  while (++i < 10)
    {
      if (server->client[i] > 0 && FD_ISSET(server->client[i], &server->sock_client))
	if (send_value(server->client[i], x, y, e) == 0)
	  return (0);
    }
  return (1);
}

int	built_select_list(t_server *server)
{
  int	i;

  i = -1;
  FD_ZERO(&server->sock_client);
  FD_SET(server->sock_server, &server->sock_client);
  while (++i < 10)
    {
      if (server->client[i] != 0)
	{
	  FD_SET(server->client[i], &server->sock_client);
	  if (server->client[i] > server->highsock)
	    server->highsock = server->client[i] + 1;
	}
    }
  return (1);
}

int			main(void)
{
  t_env			e;
  t_server		server;

  bzero((void *)&server, sizeof(t_server *));
  e.light = NULL;
  if ((init_env(&e)) == ERROR)
    return (0);
  if (create_server(&server) == 0)
    return (0);
  if (raytracer_introduction_reseau(&e, &server) == 0)
    return (0);
  return (1);
}
