#include <stdlib.h>
#include "my.h"

char	*my_realloc(char *str, int size)
{
  char	*new_str;
  int	i;
  int	len;

  len = -1;
  i = -1;
  while (str[++len]);
  if ((new_str = malloc(sizeof(char) * (len + size + 1))) == NULL)
    return (NULL);
  str_init(new_str, (len + size + 1));
  while(str[++i])
    new_str[i] = str[i];
  free(str);
  return (new_str);
}
