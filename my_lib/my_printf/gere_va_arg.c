#include "my_printf.h"

int	print_modulo(va_list UNU *list, int fd)
{
  if ((my_putchar_fd('%', fd)) == -1)
    return (-1);
  return (0);
}

int	print_int(va_list *list, int fd)
{
  int	foo;

  foo = va_arg(*list, int);
  if ((my_putnbr_fd(foo, fd)) == -1)
    return (-1);
  return (0);
}

int	print_char(va_list *list, int fd)
{
  int	foo;

  foo = va_arg(*list, int);
  if ((my_putchar_fd(foo, fd)) == -1)
    return (-1);
  return (0);
}

int	print_str(va_list *list, int fd)
{
  char	*foo;

  foo = va_arg(*list, char *);
  if ((my_putstr_fd(foo, fd)) == -1)
    return (-1);
  return (0);
}
