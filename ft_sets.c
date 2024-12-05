/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sets.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumendes <gumendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 10:59:25 by gumendes          #+#    #+#             */
/*   Updated: 2024/12/05 15:41:47 by gumendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	putpixel(t_mlx_data *data, int x, unsigned int y, unsigned int color)
{
	char	*dst;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		dst = data->img_data + (y * data->line_len + x * (data->bpp / 8));
		*(unsigned int *)dst = color;
	}
}

int	mandelbrot(t_mlx_data *data)
{
	size_t			x;
	size_t			y;
	unsigned int	n;

	y = -1;
	while (++y < HEIGHT)
	{
		data->c_im = data->MaxIm - y * data->Im_factor;
		x = -1;
		while (++x < WIDTH)
		{
			data->c_re = data->MinRe + x * data->Re_factor;
			data->Z_re = data->c_re;
			data->Z_im = data->c_im;
			n = 0;
			n = mandelbrot_iteration(data);
			if (n < MaxIter)
				putpixel(data, x, y, color(n * n / 2, n * 4, n * 7, data));
			else
				putpixel(data, x, y, 0x000000);
		}
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
	return (0);
}

int	julia(t_mlx_data *data)
{
	size_t			x;
	size_t			y;
	unsigned int	n;
	double			z_re;
	double			z_im;

	y = 0;
	while (y < HEIGHT)
	{
		z_im = data->MaxIm - y * data->Im_factor;
		x = 0;
		while (x < WIDTH)
		{
			z_re = data->MinRe + x * data->Re_factor;
			n = julia_iteration(z_re, z_im, data->c_re, data->c_im);
			if (n < MaxIter)
				putpixel(data, x, y, color(n * n / 2, n * 3, n * 7, data));
			else
				putpixel(data, x, y, 0x000000);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
	return (1);
}
