# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlangloi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/18 13:01:35 by mlangloi          #+#    #+#              #
#    Updated: 2023/04/18 14:26:44 by mlangloi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -rf

SRC =  ft_hex_len \
	ft_num_len \
	ft_printchar \
	ft_printf \
	ft_printhex \
	ft_printnbr \
	ft_printpercent \
	ft_printptr \
	ft_printstr \
	ft_printunsigned \
	ft_ptrlen \
	ft_puthex \
	ft_putptr \
	ft_putstr \
	ft_uitoa \
	ft_itoa \
	ft_intlen \
	ft_putchar \
	ft_ifzero \
	ft_ifinfzero \

SRCS = $(addsuffix .c, $(SRC))

OBJS = $(addsuffix .o, $(SRC))

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all bonus clean fclean re
