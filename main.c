/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumendes <gumendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:38:28 by gumendes          #+#    #+#             */
/*   Updated: 2024/12/03 15:08:58 by gumendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_mlx_data	data;

	(void)argv;
	if (argc != 2)
	{
		ft_printf("Invalid argument type choose an available fractal:\nmandelbrot\n");
		return (0);
	}
	ft_printf("Initializing fractal\n");
	ft_init(&data);
	if (data.mlx_ptr == NULL || data.win_ptr == NULL)
	{
		ft_printf("Init failed\n");
		return (1);
	}
	return (0);
}
