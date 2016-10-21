void	str_init(char *str, int size)
{
  int	i;

  i = -1;
  while (++i < size)
    str[i] = 0;
}
