#include "my.h"

int	my_getnbr(char *str)
{
  int	i;
  int	nb;

  i = -1;
  nb = 0;
  if (str[i + 1] == '-' || str[i + 1] == '+')
    ++i;
  while ((str[++i] >= '0' && str[i] <= '9'))
    nb = nb * 10 + (str[i] - 48);
  if (str[0] == '-')
    return (-nb);
  return (nb);
}

static int	nb_is_base(char c, char *base)
{
  int		i;

  i = -1;
  while (base[++i] && base[i] != c);
  if (!base[i])
    return (-1);
  return (i);
}

int	my_getnbr_base(char *str, char *base)
{
  int	nb;
  int	i;
  int	idx;

  nb = 0;
  i = -1;
  idx = 0;
  while ((str[++i]) && (idx = nb_is_base(str[i], base)) != -1)
    nb = nb * my_strlen(base) + idx;
  return (nb);
}
