/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_messages.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumendes <gumendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 16:21:52 by gumendes          #+#    #+#             */
/*   Updated: 2025/01/03 17:07:57 by gumendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/**
 * @brief Displays an error message in the
 *  terminal and frees all allocated memory if needed.
 */
int	lilerror(void)
{
	ft_printf("Too little arguments given. ");
	ft_printf("Please select an available");
	ft_printf(" fractal from the following list ");
	ft_printf("while following the shown format:\n");
	ft_printf("mandelbrot\njulia (x) (y)\nnewton\nship\n");
	ft_printf("If no values are given for the julia set,");
	ft_printf(" the default values will be assumed.\n");
	exit (1);
}

/**
 * @brief Displays an error message in the
 *  terminal and frees all allocated memory if needed.
 */
int	bigerror(void)
{
	ft_printf("Too many arguments given. ");
	ft_printf("Please select an available");
	ft_printf(" fractal from the following list ");
	ft_printf("while following the shown format:\n");
	ft_printf("mandelbrot\njulia (x) (y)\nnewton\nship\n");
	ft_printf("If no values are given for the julia set,");
	ft_printf(" the default values will be assumed.\n");
	exit (1);
}

/**
 * @brief Displays an error message in the
 *  terminal and frees all allocated memory if needed.
 */
int	ft_error(t_mlx_data *data)
{
	ft_printf("Invalid argument type!\n");
	ft_printf("Please select an available");
	ft_printf(" fractal from the following list");
	ft_printf("while following the shown format:\n");
	ft_printf("mandelbrot\njulia (x) (y)\nnewton\nship\n");
	ft_printf("If no values are given for the julia set,");
	ft_printf(" the default values will be assumed.\n");
	cleanup(data);
	ft_free(data);
	exit (1);
}

void	ft_controls(void)
{
	ft_printf("Welcome to my fract'ol!\n");
	ft_printf("You can zoom in/out using the scroll wheel,");
	ft_printf(" it will also zoom in/out on the position of the mouse\n");
	ft_printf("You can move the picture around using the arrow keys.\n");
	ft_printf("You can change the color palette using j and k.\n");
	ft_printf("Youcan also change the fractal being ");
	ft_printf("rendered at will by pressing the nurbers 1, 2, 3 or 4.\n");
	ft_printf("Pressing Esc or the cross will close the window.\n");
	ft_printf("That's all, enjoy!\n");
}
