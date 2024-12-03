# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gumendes <gumendes@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/19 15:23:37 by gumendes          #+#    #+#              #
#    Updated: 2024/12/03 16:16:33 by gumendes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	cc
RM			=	rm -f
CFLAGS		=	-Wall -Wextra -Werror -g

# Library Paths
LIBFT_PATH		=	libft
PRINTF_PATH		=	printf
MLX_PATH		=	minilibx-linux

# Libraries
LIBFT		=	$(LIBFT_PATH)/libft.a
PRINTF		=	$(PRINTF_PATH)/libftprintf.a
MLX_LIB		=	-L$(MLX_PATH) -lmlx_Linux -lX11 -lXext -lm

# Includes
INCLUDES = -I$(LIBFT_PATH) -I$(PRINTF_PATH) -I$(MLX_PATH)

NAME		=	fract_ol

SRC			=	main.c ft_sets.c ft_events.c ft_color.c ft_init.c ft_addit.c ft_calcs.c ft_zoom.c
OBJ			=	$(SRC:.c=.o)

# Targets
all: $(LIBFT) $(PRINTF) $(NAME)

# Build the libft library
$(LIBFT):
	$(MAKE) -C $(LIBFT_PATH)

# Build the printf library
$(PRINTF):
	$(MAKE) -C $(PRINTF_PATH)

# Build the fractol program
$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJ) $(LIBFT) $(PRINTF) $(MLX_LIB) -o $(NAME)

# Clean object files
clean:
	$(RM) $(OBJ)
	$(MAKE) -C $(LIBFT_PATH) clean
	$(MAKE) -C $(PRINTF_PATH) clean

# Full clean
fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_PATH) fclean
	$(MAKE) -C $(PRINTF_PATH) clean

re: fclean all

.PHONY: all clean fclean re
