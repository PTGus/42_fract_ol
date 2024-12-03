/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sets.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumendes <gumendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 10:59:25 by gumendes          #+#    #+#             */
/*   Updated: 2024/12/03 16:07:05 by gumendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void putpixel(t_mlx_data *data, t_mlx_data *win, int x, unsigned int y, unsigned int color)
{
    mlx_pixel_put(data->mlx_ptr, win, x, y, color);
}

void mandelbrot(t_mlx_data *data, t_mlx_data *win)
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
                putpixel(data, win, x, y, color(n , n * n / 2, n * 3, n * 7));
            else
                putpixel(data, win, x, y, 0x000000);
        }
    }
}


