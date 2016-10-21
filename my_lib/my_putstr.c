#include <unistd.h>
#include "my.h"

int	my_puterror(char *str)
{
  if ((write(2, str, my_strlen(str))) == -1)
    return (-1);
  return (0);
}

int	my_putstr(char *str)
{
  if ((write(1, str, my_strlen(str))) == -1)
    return (-1);
  return (0);
}
