/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addit3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumendes <gumendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 16:35:53 by gumendes          #+#    #+#             */
/*   Updated: 2025/01/03 17:07:08 by gumendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	reinitialize_plane_julia(t_mlx_data *data)
{
	double	ratio;
	double	range_re;

	ratio = (double)HEIGHT / (double)WIDTH;
	data->zoom_factor = 0.95;
	data->min_re = -2.0;
	data->max_re = 2.0;
	data->min_im = -2.0 * ratio;
	data->max_im = 2.0 * ratio;
	range_re = data->max_re - data->min_re;
	data->re_factor = range_re / (WIDTH - 1);
	data->im_factor = (data->max_im - data->min_im) / (HEIGHT - 1);
	data->c_re = -0.745429;
	data->c_im = 0.05;
	data->red_factor = 1;
	data->green_factor = 1;
	data->blue_factor = 1;
}

void	ft_reselec_fractal(t_mlx_data *data)
{
	if (data->fractal_type == 0)
	{
		initialize_plane_mandelbrot(data);
		return ;
	}
	else if (data->fractal_type == 1)
	{
		reinitialize_plane_julia(data);
		return ;
	}
	else if (data->fractal_type == 2)
	{
		initialize_plane_newton(data);
		return ;
	}
	else if (data->fractal_type == 3)
	{
		initialize_plane_burn(data);
		return ;
	}
	else
	{
		ft_error(data);
		return ;
	}
}

void	ft_re_init(t_mlx_data *data)
{
	if (data->img_ptr)
		mlx_destroy_image(data->mlx_ptr, data->img_ptr);
	data->img_ptr = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	data->img_data = mlx_get_data_addr(data->img_ptr, &data->bpp,
			&data->line_len, &data->endian);
	ft_reselec_fractal(data);
	ft_resume(data);
}
