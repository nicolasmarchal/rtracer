int	my_strcpy(char *dest, char *src)
{
  int	i;

  i = -1;
  while (src[++i])
    dest[i] = src[i];
  dest[i] = 0;
  return (0);
}
