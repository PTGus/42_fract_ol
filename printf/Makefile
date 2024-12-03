# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gumendes <gumendes@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/15 09:43:19 by gumendes          #+#    #+#              #
#    Updated: 2024/11/12 11:47:29 by gumendes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -g

NAME = libftprintf.a

SRC = ft_printf.c ft_printlowhexa.c ft_printnbr.c ft_printptr.c \
	  ft_printstr.c ft_printuphexa.c ft_printutils.c ft_printunbr.c \
	  ft_putchar_fd.c ft_putstr_fd.c ft_strlen.c \
	  ft_calloc.c ft_bzero.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
