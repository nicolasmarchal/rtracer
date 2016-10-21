#include <stdlib.h>
#include "my.h"

char	*my_strdup(char *src)
{
  int	j;
  char	*dest;

  j = -1;
  if ((dest = malloc(sizeof(char) * my_strlen(src) + 1)) == NULL)
    return (NULL);
  while (++j < my_strlen(src))
    dest[j] = src[j];
  dest[j] = 0;
  return (dest);
}
