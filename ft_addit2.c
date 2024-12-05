/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addit2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumendes <gumendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:37:51 by gumendes          #+#    #+#             */
/*   Updated: 2024/12/05 15:44:24 by gumendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_init_fract(t_mlx_data *data)
{
	if (data->fractal_type == 0)
		mandelbrot(data);
	else if (data->fractal_type == 1)
		julia(data);
}
