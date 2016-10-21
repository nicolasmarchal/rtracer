#include "raytracer.h"

void	decal_str(char *str)
{
  int	i;

  i = -1;
  while (str[++i])
    str[i] = str[i + 1];
}

int	epur_str(char *str)
{
  int	i;

  i = -1;
  while (str[0] && str[0] == ' ' || str[0] == '\t')
    decal_str(&str[0]);
  while (str[++i])
    {
      while (str[i] && (str[i] == ' ' || str[i] == '\t') &&
	     (str[i + 1] == ' ' || str[i + 1] == '\t'))
	decal_str(&str[i]);
    }
  if (str[i - 1] == ' ' || str[i - 1] == '\t')
    str[i - 1] = 0;
  return (0);
}
