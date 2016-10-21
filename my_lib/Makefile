NAME	= libmy.a

CC	= gcc

RM	= rm -f

SRC	= 	my_getnbr.c		\
		my_putchar.c		\
		my_putnbr.c		\
		my_putstr.c		\
		my_strcat.c		\
		my_strdup.c		\
		my_strlen.c		\
		my_put_tab.c		\
		my_strcmp.c		\
		my_str_to_wordtab2.c 	\
		err_putstr.c		\
		get_next_line.c		\
		str_init.c		\
		free_tab.c		\
		my_printf/my_printf.c	\
		my_printf/gere_va_arg.c	\
		my_printf/aff_ft.c	\
		my_strcpy.c		\
		my_realloc.c		\
		epur_str.c

OBJ	= $(SRC:.c=.o)

CFLAGS	= -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
