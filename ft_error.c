/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumendes <gumendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 11:08:34 by gumendes          #+#    #+#             */
/*   Updated: 2025/01/02 17:43:12 by gumendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	lilerror(void)
{
	ft_printf("Too little arguments please select an available fractal\n");
	ft_printf("mandelbrot\njulia");
}

void	bigerror(void)
{
	ft_printf("Too many arguments please select an available fractal\n");
	ft_printf("mandelbrot\njulia");
}

void	ft_error(void)
{
	ft_printf("Invalid argument type!\n");
	ft_printf("Please select an available");
	ft_printf(" fractal from the following list:\n");
	ft_printf("-mandelbrot\n-julia (x) (y)\n");
	ft_printf("If no values are given for the julia set,");
	ft_printf(" the defaults values will be assumed\n");
}
