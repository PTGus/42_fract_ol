/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumendes <gumendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 11:08:34 by gumendes          #+#    #+#             */
/*   Updated: 2024/12/04 11:12:50 by gumendes         ###   ########.fr       */
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
