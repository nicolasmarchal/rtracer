#include <stdlib.h>
#include <stdio.h>
#include "my.h"

int	nb_line(char *str, char c)
{
  int	i;
  int	size;

  i = -1;
  size = 1;
  while (str[++i])
    {
      if (str[i] != c && str[i + 1] == c)
	size = size + 1;
    }
  return (size + 2);
}

int	len_line(char *str, char c)
{
  int	i;

  i = -1;
  while (str[++i] && str[i] != c);
  return (i);
}

int	fill_tab(char *str, char **tab, char c, int y)
{
  int	x;

  x = -1;
  if ((tab[y] = malloc(sizeof(char) * (len_line(str, c) + 1))) == NULL)
    return (-1);
  str_init(tab[y], len_line(str, c) + 1);
  while (str[++x] && str[x] != c)
    tab[y][x] = str[x];
  if (str[x] == c)
    {
      tab[y][x] = 0;
      return (x);
    }
  tab[y][x] = 0;
  return (x - 1);
}

char	**my_str_to_wordtab(char *str, char c)
{
  char	**tab;
  int	y;
  int	i;
  int	ret;

  y = 0;
  i = -1;
  if ((tab = malloc(sizeof(char *) * nb_line(str, c) + 1)) == NULL)
    return (NULL);
  tab[y] = NULL;
  while (str[++i])
    {
      if (str[i] != c)
	{
	  if ((ret = fill_tab(&str[i], tab, c, y)) == -1)
	    return (NULL);
	  i = i + ret;
	  y = y + 1;
	}
    }
  tab[y] = NULL;
  return (tab);
}
