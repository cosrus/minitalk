
all: server client

server:
		make -C mylibft 
		gcc -Wall -Wextra -Werror server.c mylibft/mylibft.a -o server

client: 
		make -C mylibft
		gcc -Wall -Wextra -Werror client.c mylibft/mylibft.a -o client

clean:
		make -C mylibft clean

fclean: clean
		rm -f server client 
		make -C mylibft fclean

re: fclean all

.PHONY: bonus all clean fclean re
