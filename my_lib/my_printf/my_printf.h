#ifndef MY_PRINTF_H_
# define MY_PRINTF_H_

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

# define UNU __attribute__((unused))

int	my_printf(const char *, int fd, ...);
int	(*flag(char))(va_list *, int);
int	print_modulo(va_list *, int);
int	print_int(va_list *, int);
int	print_char(va_list *, int);
int	print_str(va_list *, int);
int	my_putchar_fd(char, int);
int	my_putnbr_fd(int, int);
int	my_putstr_fd(char *, int);

#endif /* !MY_PRINTF_H_ */
