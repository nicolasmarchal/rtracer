#include "my_printf.h"

int		(*flag(char id))(va_list *, int)
{
  int		(*ptr_ft[12])(va_list *, int);
  char		base[] = "%csd";
  int		i;

  i = -1;
  ptr_ft[0] = &print_modulo;
  ptr_ft[1] = &print_char;
  ptr_ft[2] = &print_str;
  ptr_ft[3] = &print_int;
  while (base[++i] && id != base[i]);
  if (i > 3)
    return (NULL);
  return (ptr_ft[i]);
}

int		my_printf(const char *format, int fd, ...)
{
  va_list	list;
  int		i;
  int		(*ptr_ft)(va_list *, int);

  i = -1;
  va_start(list, fd);
  while (format[++i])
    {
      if (format[i] == '%')
	{
	  if ((ptr_ft = flag(format[i + 1])) != NULL)
	    {
	      if (((*ptr_ft)(&list, fd)) == -1)
		return (-1);
	      i = i + 1;
	    }
	  else
	    if ((my_putchar_fd(format[i], fd)) == -1)
	      return (-1);
	}
      else
	if ((my_putchar_fd(format[i], fd)) == -1)
	  return (-1);
    }
  return (0);
}
