
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

SERVER_SRCS	= src/server.c
CLIENT_SRCS	= src/client.c
HEADERS		= include/minitalk.h

CC			= gcc -Wall -Werror -Wextra
CC_FLAGS	= -Llibft -lft

%.o: %.c ${HEADERS} libft/libft.a
			${CC} $< -c -o $@

all:		libft server client
			@echo "Compilado con éxito"

libft:
			@make --no-print-directory -C libft

server:		${SERVER_SRCS:.c=.o} ${HEADERS}
			@${CC} ${SERVER_SRCS} ${CC_FLAGS} -o server

client:		${CLIENT_SRCS:.c=.o} ${HEADERS}
			@${CC} ${CLIENT_SRCS} ${CC_FLAGS} -o client

clean:
			rm -rdf ${SERVER_SRCS:.c=.o} ${CLIENT_SRCS:.c=.o}
			@make clean -C libft

fclean:		clean
			@make fclean -C libft
			@rm -rf client server

.PHONY:		all libft clean fclean

