/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumendes <gumendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:38:28 by gumendes          #+#    #+#             */
/*   Updated: 2025/01/02 17:45:03 by gumendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_mlx_data	*data;

	if (argc < 2 || argc > 4)
	{
		if (argc > 4)
			bigerror();
		else
			lilerror();
		return (1);
	}
	data = malloc(sizeof(t_mlx_data));
	if (!data)
		return (1);
	ft_init(data, argv);
	if (data->mlx_ptr == NULL || data->win_ptr == NULL)
		return (1);
	return (0);
}
