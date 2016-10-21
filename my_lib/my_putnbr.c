#include "my.h"

int	my_put_nbr(int nb)
{
  if (nb < 0)
    {
      if ((my_putchar('-')) == -1)
	return (-1);
      nb = nb * (-1);
    }
  if (nb > 9)
    {
      if ((my_put_nbr(nb / 10)) == -1)
	return (-1);
    }
  if ((my_putchar((nb % 10) + 48)) == -1)
    return (-1);
  return (0);
}
