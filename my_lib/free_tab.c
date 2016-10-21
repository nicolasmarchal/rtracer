#include <stdlib.h>

void	free_tab(char **tab)
{
  int	i;

  i = -1;
  while (tab[++i])
    free(tab[i]);
  free(tab);
}
