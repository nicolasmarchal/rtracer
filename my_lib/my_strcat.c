#include <stdlib.h>
#include "my.h"

char	*my_strcat(char *s1, char *s2)
{
  char	*dest;
  int	i;
  int	j;

  if ((dest = malloc(sizeof(char) * (my_strlen(s1)
				     + my_strlen(s2) + 1))) == NULL)
    return (NULL);
  str_init(dest, my_strlen(s1) + my_strlen(s2) + 1);
  i = 0;
  j = 0;
  while (s1[j])
    dest[i++] = s1[j++];
  j = 0;
  while (s2[j])
    dest[i++] = s2[j++];
  return (dest);
}

char	*my_strcat2(char *s1, char c, char *s2)
{
  char	*dest;
  int	i;
  int	j;

  if ((dest = malloc(sizeof(char) * (my_strlen(s1)
				     + my_strlen(s2) + 2))) == NULL)
    return (NULL);
  str_init(dest, my_strlen(s1) + my_strlen(s2) + 2);
  i = 0;
  j = 0;
  while (s1[j])
    dest[i++] = s1[j++];
  j = 0;
  dest[i++] = c;
  while (s2[j])
    dest[i++] = s2[j++];
  return (dest);
}
