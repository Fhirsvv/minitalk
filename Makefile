
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ecortes- <ecortes-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/19 11:36:33 by ecortes-          #+#    #+#              #
#    Updated: 2023/12/19 11:39:50 by ecortes-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT = client
SERVER = server

LIBFT = ./libft/libft.a
LIBFT_DIR = ./libft

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC1 = client.c
SRC2 = server.c

OBJ1 = $(SRC1:.c=.o)
OBJ2 = $(SRC2:.c=.o)

all: $(CLIENT) $(SERVER)

$(OBJ1): $(SRC1)
	$(CC) $(CFLAGS) -c $(SRC1) -o $(OBJ1)

$(OBJ2): $(SRC2)
	$(CC) $(CFLAGS) -c $(SRC2) -o $(OBJ2)

$(CLIENT): $(OBJ1)
	$(CC) $(CFLAGS) -o $(CLIENT) $(OBJ1) $(LIBFT)

$(SERVER): $(OBJ2)
	$(CC) $(CFLAGS) -o $(SERVER) $(OBJ2) $(LIBFT)

clean:
	rm -f $(OBJ1) $(OBJ2)

fclean: clean
	rm -f $(CLIENT) $(SERVER)

re: fclean all

.PHONY: all clean fclean re
