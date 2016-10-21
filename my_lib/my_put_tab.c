#include "my.h"

int	my_put_tab(char **tab)
{
  int	i;

  i = -1;
  while (tab[++i])
    {
      if ((my_putstr(tab[i])) == -1 || (my_putchar('\n')) == -1)
	return (-1);
    }
  return (0);
}
