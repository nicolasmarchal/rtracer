#include <unistd.h>
#include "my.h"

int	err_putstr(char *str)
{
  if (write(2, str, my_strlen(str)) == -1)
    return (0);
  return (0);
}
