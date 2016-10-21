SERVER		= ./server

LIB		= -L../../lib -lmlx_$(HOSTTYPE) -L/usr/lib64/X11 \
		-lXext -lX11 -L../../my_lib -lmy -lm

SERVERSRC	= ./server.c \
		introduction_reseau.c \
		loading_bar.c \
		gere_env.c

CFLAGS		= -I../../include/ -I../../lib -W -Wall -Wextra -Werror -pedantic

SERVEROBJ	= $(SERVERSRC:.c=.o)


all:		$(SERVER)

$(SERVER):	$(SERVEROBJ)
		cc -o $(SERVER) $(SERVEROBJ) $(LIB)

clean:
		rm -f $(SERVEROBJ)

fclean:		clean
		rm -f $(SERVER)

re:		fclean all
