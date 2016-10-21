CLIENT		= ./client

LIB             = -L../../lib -lmlx_$(HOSTTYPE) -L/usr/lib64/X11 \
		-lXext -lX11 -L../../my_lib -lmy -lm

TRD_LIB		= -lpthread

MY_LIB		= ../../my_lib

CLIENTSRC	= ./client.c			\
		send_and_receive_pixels.c 	\
		gere_env.c             		\
		loading_bar.c           	\
		ft_list.c               	\
		calc_inter.c            	\
		rotate.c                	\
		hyperbol.c			\
		hyperboloid.c			\
		sphere.c                	\
		cone.c                  	\
		cylinder.c              	\
		limit_x.c			\
		limit_y.c			\
		limit_z.c			\
		plan.c                  	\
		translate.c             	\
		delta_solution.c        	\
		get_data.c			\
		light.c                 	\
		parse.c                 	\
		fill_data.c             	\
		fill_shapes.c           	\
		fill_cam.c              	\
		fill_light.c            	\
		gere_comment.c			\
		textured_background.c		\
		define_color.c			\
		reflec2.c			\
		def_shape.c			\
		def_shape2.c			\
		do_thread.c

CLIENTOBJ	= $(CLIENTSRC:.c=.o)

CFLAGS		= -I../../include/ -I../../lib/ -Werror -W -Wall -Wextra

$(CLIENT):	$(CLIENTOBJ)
		make -C $(MY_LIB)
		cc -o $(CLIENT) $(CLIENTOBJ) $(TRD_LIB) $(LIB)

all:		$(CLIENT)

clean:
		rm -f $(CLIENTOBJ)

fclean:		clean
		rm -f $(CLIENT)

re:		fclean all
