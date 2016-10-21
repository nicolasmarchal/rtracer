#include <stdlib.h>
#include <stdio.h>
#include "my.h"

int	check_token(char foo, char *token)
{
  int	i;

  i = -1;
  while (token[++i])
    {
      if (token[i] == foo)
	return (1);
    }
  return (0);
}

int	nb_line(char *str, char *token)
{
  int	i;
  int	size;

  i = -1;
  size = 1;
  while (str[++i])
    {
      if (str[i + 1] && (check_token(str[i], token)) == 0
	  && (check_token(str[i + 1], token)) == 1)
	size = size + 1;
    }
  return (size + 2);
}

int	len_line(char *str, char *token)
{
  int	i;

  i = -1;
  while (str[++i] && (check_token(str[i], token)) == 0);
  return (i);
}

int	fill_tab(char *str, char **tab, char *token, int y)
{
  int	x;

  x = -1;
  if ((tab[y] = malloc(sizeof(char) * (len_line(str, token) + 1))) == NULL)
    return (-1);
  str_init(tab[y], len_line(str, token) + 1);
  while (str[++x] && (check_token(str[x], token)) == 0)
    tab[y][x] = str[x];
  tab[y][x] = 0;
  if (!str[x])
    return (x - 1);
  return (x);
}

char	**my_str_to_wordtab_token(char *str, char *token)
{
  char	**tab;
  int	y;
  int	i;
  int	ret;

  y = 0;
  i = -1;
  if ((tab = malloc(sizeof(char *) * nb_line(str, token) + 1)) == NULL)
    return (NULL);
  tab[y] = NULL;
  while (str[++i])
    {
      if ((check_token(str[i], token)) == 0)
	{
	  if ((ret = fill_tab(&str[i], tab, token, y)) == -1)
	    return (NULL);
	  i = i + ret;
	  y = y + 1;
	}
    }
  tab[y] = NULL;
  return (tab);
}
