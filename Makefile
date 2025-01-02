# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gumendes <gumendes@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/19 15:23:37 by gumendes          #+#    #+#              #
#    Updated: 2025/01/02 17:15:36 by gumendes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	cc
RM			=	rm -f
CFLAGS		=	-Wall -Wextra -Werror -g
MLXFLAGS	=	-lX11 -lXext -lm

# Library Paths
LIBFT_PATH		=	libft
PRINTF_PATH		=	printf
MLX_PATH		=	mlx

# Libraries
LIBFT		=	$(LIBFT_PATH)/libft.a
PRINTF		=	$(PRINTF_PATH)/libftprintf.a
MLX_LIB		=	$(MLX_PATH)/libmlx_Linux.a

# Includes
INCLUDES = -I$(LIBFT_PATH) -I$(PRINTF_PATH) -I$(MLX_PATH)

NAME		=	fract_ol

SRC			=	main.c ft_sets.c ft_events.c ft_color.c \
				ft_init.c ft_addit.c ft_calcs.c ft_zoom.c \
				ft_error.c ft_kill.c ft_addit2.c
OBJ			=	$(SRC:.c=.o)

# Targets
all: checker $(MLX_LIB) $(LIBFT) $(PRINTF) $(NAME)

# Build the libft library
$(LIBFT):
	$(MAKE) -C $(LIBFT_PATH)

# Build the printf library
$(PRINTF):
	$(MAKE) -C $(PRINTF_PATH)

$(MLX_LIB):
	make -C mlx

checker:
	@if [ -d "mlx" ]; then echo "$(GREEN)[MLX FOLDER FOUND]$(END)"; else make download; fi

download:
	git clone git@github.com:42Paris/minilibx-linux.git mlx

# Build the fractol program
$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(MLXFLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(PRINTF) $(MLX_LIB)

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
	rm -rf mlx

re: fclean all

.PHONY: all clean fclean re
