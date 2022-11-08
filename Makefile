SERVER =	server.c

CLIENT =	client.c

LIB =	Libft/libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SERVEROBJ = $(SERVER:.c=.o)

CLIENTOBJ = $(CLIENT:.c=.o)

all: server client

$(LIB):
	make -C Libft

server: $(SERVEROBJ) $(LIB)
	$(CC) $(CFLAGS) $(SERVEROBJ) $(LIB) -o server

client: $(CLIENTOBJ) $(LIB)
	$(CC) $(CFLAGS) $(CLIENTOBJ) $(LIB) -o client

clean:
	rm -f $(SERVEROBJ) $(CLIENTOBJ)
	make -C Libft clean

fclean: clean
	rm -f server client
	make -C Libft fclean

re: fclean all