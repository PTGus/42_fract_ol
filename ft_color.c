/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumendes <gumendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 10:18:08 by gumendes          #+#    #+#             */
/*   Updated: 2025/01/03 17:11:14 by gumendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/**
 * @brief Tells the program to switch
 *  colors for the pixels outside the set.
 */
void	ft_next_color(int keysym, t_mlx_data *data)
{
	if (keysym == 106)
	{
		data->red_factor -= 3;
		data->green_factor -= 1;
		data->blue_factor -= 2;
	}
	if (keysym == 107)
	{
		data->red_factor += 3;
		data->green_factor += 1;
		data->blue_factor += 2;
	}
	ft_resume(data);
}

/**
 * @brief Returns the color to be used by
 *  the program for the pixels outside the set.
 */
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
