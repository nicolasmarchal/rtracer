CC	=	gcc

LIB	=	-L../lib -lmlx_$(HOSTTYPE) -L/usr/lib64/X11 \
		-lXext -lX11 -L../my_lib -lmy -lm

MY_LIB	=	../my_lib

NAME	=	rt

SRC	=	main.c			\
		gere_env.c		\
		introduction.c		\
		loading_bar.c		\
		ft_list.c		\
		calc_inter.c		\
		rotate.c		\
		hyperbol.c		\
		hyperboloid.c		\
		sphere.c		\
		cone.c			\
		cylinder.c		\
		plan.c			\
		translate.c		\
		delta_solution.c	\
		light.c			\
		parse.c			\
		fill_data.c		\
		fill_shapes.c		\
		fill_cam.c		\
		fill_light.c		\
		get_data.c		\
		limit_x.c		\
		limit_y.c		\
		limit_z.c		\
		gere_comment.c		\
		textured_background.c	\
		define_color.c		\
		reflec2.c		\
		def_shape.c		\
		def_shape2.c

OBJ	=	$(SRC:.c=.o)

RM	=	rm -f

CFLAGS	=	-I../my_lib -I../lib -I./include -Wall -Wextra

all:		$(NAME)

$(NAME):	$(OBJ)
		make -C $(MY_LIB)
		$(CC) $(OBJ) -o $(NAME) $(LIB)

clean:
		make clean -C $(MY_LIB)
		$(RM) $(OBJ)

fclean:		clean
		make fclean -C $(MY_LIB)
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
