/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumendes <gumendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 10:18:08 by gumendes          #+#    #+#             */
/*   Updated: 2025/01/02 17:31:27 by gumendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_next_color(int keysym, t_mlx_data *data)
{
	if (keysym == 106 && data->red_factor >0 && data->green_factor > 0 && data->blue_factor > 0)
	{
		data->red_factor -= 3;
		data->green_factor -= 1;
		data->blue_factor -= 2;
		return ;
	}
	if (keysym == 107)
	{
		data->red_factor += 3;
		data->green_factor += 1;
		data->blue_factor += 2;
		return ;
	}
}

int	color(int r, int g, int b, t_mlx_data *data)
{
	int	rr;
	int	gg;
	int	bb;

	rr = data->red_factor;
	gg = data->green_factor;
	bb = data->blue_factor;
	return (*(int *)(unsigned char [4]){b * bb, g * gg, r * rr});
}
