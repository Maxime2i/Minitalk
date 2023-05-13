# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlangloi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/12 18:55:33 by mlangloi          #+#    #+#              #
#    Updated: 2023/05/13 15:09:01 by mlangloi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFTPRINTF = ./ft_printf/libftprintf.a
RM = rm -f

SERVER = server
CLIENT = client

SERVER_SRCS = server.c
SERVER_OBJS = $(SERVER_SRCS:.c=.o)

CLIENT_SRCS = client.c
CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)

all: $(SERVER) $(CLIENT)

$(LIBFTPRINTF):
	$(MAKE) -C ./ft_printf
$(SERVER): $(SERVER_OBJS) $(LIBFTPRINTF)
	$(CC) $(CFLAGS) $(SERVER_OBJS) $(LIBFTPRINTF) -o server
$(CLIENT): $(CLIENT_OBJS) $(LIBFTPRINTF)
	$(CC) $(CFLAGS) $(CLIENT_OBJS) $(LIBFTPRINTF) -o client

clean:
	$(MAKE) clean -C ./ft_printf
	$(RM) $(SERVER_OBJS) $(CLIENT_OBJS)
	$(RM) libftprintf.a

fclean: clean
	$(MAKE) fclean -C ./ft_printf
	$(RM) $(SERVER) $(CLIENT)

re: fclean all
