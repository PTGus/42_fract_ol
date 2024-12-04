/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumendes <gumendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:38:28 by gumendes          #+#    #+#             */
/*   Updated: 2024/12/04 15:03:48 by gumendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_mlx_data	data;
	(void)argc;
	// if (argc != 2)
	// {
	// 	if (argc == 1)
	// 		lilerror();
	// 	// else if ()
	// 	// 	bigerror();
	// 	return (0);
	// }
	ft_init(&data, argv);
	if (data.mlx_ptr == NULL || data.win_ptr == NULL)
	{
		ft_printf("Init failed\n");
		return (1);
	}
	return (0);
}
