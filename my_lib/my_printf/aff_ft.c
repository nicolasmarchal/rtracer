#include "my_printf.h"

int	my_putchar_fd(char c, int fd)
{
  if ((write(fd, &c, 1)) == -1)
    return (-1);
  return (0);
}

int	my_putnbr_fd(int nb, int fd)
{
  if (nb < 0)
    {
      if ((my_putchar_fd('-', fd)) == -1)
	return (-1);
      nb = nb * (-1);
    }
  if (nb > 9)
    if ((my_putnbr_fd(nb / 10, fd)) == -1)
      return (-1);
  if ((my_putchar_fd((nb % 10) + 48, fd)) == -1)
    return (-1);
  return (0);
}

int	my_putstr_fd(char *str, int fd)
{
  int	i;

  i = -1;
  while (str[++i])
    {
      if ((my_putchar_fd(str[i], fd)) == -1)
	return (-1);
    }
  return (0);
}
