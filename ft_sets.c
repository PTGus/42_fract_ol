/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sets.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumendes <gumendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 10:59:25 by gumendes          #+#    #+#             */
/*   Updated: 2024/12/04 14:39:44 by gumendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void putpixel(t_mlx_data *data, int x, unsigned int y, unsigned int color)
{
    if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
    {
        char *dst = data->img_data + (y * data->line_len + x * (data->bpp / 8));
        *(unsigned int *)dst = color;
    }
}

void mandelbrot(t_mlx_data *data)
{
    size_t x;
    size_t y;
    unsigned int n;

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
                putpixel(data, x, y, color(0 , n * n / 2, n * 4, n * 7, data));
            else
                putpixel(data, x, y, 0x000000);
        }
    }
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
}

void julia(t_mlx_data *data)
{
    size_t x;
	size_t y;
    unsigned int n;
	double Z_re;

    y = 0;
    while (y < HEIGHT)
    {
        double Z_im = data->MaxIm - y * data->Im_factor;
        x = 0;
        while (x < WIDTH)
        {
            Z_re = data->MinRe + x * data->Re_factor;
            n = julia_iteration(Z_re, Z_im, data->c_re, data->c_im);
            if (n < MaxIter)
                putpixel(data, x, y, color(0, n * n / 2, n * 3, n * 7, data));
            else
                putpixel(data, x, y, 0x000000);
            x++;
        }
        y++;
    }
    mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
}
