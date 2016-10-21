#include <sys/types.h>
#include <sys/ioctl.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdlib.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include "my.h"
#include "client.h"

char	*find_ip()
{
  char	*sip;

  write(1, "Enter IP Address : ", 19);
  sip = get_next_line(0);
  return (sip);
}

int	find_port()
{
  int	nb;
  char	*sip;

  write(1, "Enter Port : ", 13);
  sip = get_next_line(0);
  if (!sip || my_strlen(sip) > 8)
    return (0);
  if ((nb = my_getnbr(sip)) < 0)
    nb = 0;
  if (nb > 65535)
    nb = 0;
  free(sip);
  return (nb);
}

int			create_client(t_client *client)
{
  struct hostent	*host;
  struct sockaddr_in	sin;

  my_putstr("Creation of client\n");
  if ((host = gethostbyname(find_ip())) == NULL)
    return (err_putstr("The host doesn't exist\n"));
  if ((client->sock = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    return (err_putstr("Failed to socket\n"));
  sin.sin_addr = *((struct in_addr *)host->h_addr);
  sin.sin_port = htons(find_port());
  sin.sin_family = AF_INET;
  if (connect(client->sock, (struct sockaddr *)&sin,
	      sizeof(struct sockaddr)) == -1)
    return (err_putstr("Failed to connect\n"));
  my_putstr("Client OK.\n");
  return (1);
}

int			main(int ac, UNU char **av)
{
  t_client		client;
  t_env			e;
  t_list		*shapes;

  shapes = NULL;
  e.light = NULL;
  if (ac < 2)
    return (my_printf("Usage: ./rt [--help] config.rt\n", 1));
  if (init_env(&e) == ERROR ||
      get_scene_from_files(av[1], &e, &shapes) == -1)
    return (ERROR);
  if (create_client(&client) == 0)
    return (0);
  if (send_and_receive_pixels(&client, &e, shapes) == 0)
    return (0);
  close(client.sock);
  return (1);
}
