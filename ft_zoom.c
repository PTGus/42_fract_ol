/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zoom.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumendes <gumendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 13:48:03 by gumendes          #+#    #+#             */
/*   Updated: 2024/12/03 15:44:00 by gumendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int ft_zoom(int keysym, int x, int y, t_mlx_data *data)
{
    (void)x;
    (void)y;

    double re_center = (data->MinRe + data->MaxRe) / 2.0;
    double im_center = (data->MinIm + data->MaxIm) / 2.0;

    if (keysym == 4) // Zoom in
    {
        data->MinRe = re_center + (data->MinRe - re_center) * data->zoom_factor;
        data->MaxRe = re_center + (data->MaxRe - re_center) * data->zoom_factor;
        data->MinIm = im_center + (data->MinIm - im_center) * data->zoom_factor;
        data->MaxIm = im_center + (data->MaxIm - im_center) * data->zoom_factor;
    }
    else if (keysym == 5) // Zoom out
    {
        data->MinRe = re_center + (data->MinRe - re_center) / data->zoom_factor;
        data->MaxRe = re_center + (data->MaxRe - re_center) / data->zoom_factor;
        data->MinIm = im_center + (data->MinIm - im_center) / data->zoom_factor;
        data->MaxIm = im_center + (data->MaxIm - im_center) / data->zoom_factor;
    }

    data->Re_factor = (data->MaxRe - data->MinRe) / (WIDTH - 1);
    data->Im_factor = (data->MaxIm - data->MinIm) / (HEIGHT - 1);

    mandelbrot(data, data->win_ptr);
    return (1);
}