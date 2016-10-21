#include "raytracer.h"

void	reload_loading(char *str)
{
  int	i;

  i = -1;
  while (str[++i])
    {
      if (str[i] == ' ')
	{
	  str[i] = '#';
	  return;
	}
    }
}

int	print_loading_bar(int y, int *tmp, char *loading)
{
  int	ratio;

  ratio = (int)(100 * ((double)y / (double)HEIGHT));
  if (ratio == (*tmp + 1))
    {
      ++(*tmp);
      if (ratio % 5 == 0)
	reload_loading(loading);
      my_printf("\rLoading \033[20;33m%s\033[0m %d%%", 1, loading, ratio);
    }
  return (0);
}
