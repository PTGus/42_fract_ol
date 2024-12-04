/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumendes <gumendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:28:56 by gumendes          #+#    #+#             */
/*   Updated: 2024/12/04 14:59:58 by gumendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void initialize_plane_mandelbrot(t_mlx_data *data)
{
    double ratio;
    double rangeRe;
	data->zoom_factor = 0.95;
    data->MinRe = -2.1;
    data->MaxRe = 0.5;
    data->MinIm = -1.2;
    ratio = (double)HEIGHT / (double)WIDTH;
    rangeRe = data->MaxRe - data->MinRe;
    data->MaxIm = 1.3;
    data->Re_factor = rangeRe / (WIDTH - 1);
    data->Im_factor = (data->MaxIm - data->MinIm) / (HEIGHT - 1);
	data->Red_factor = 0;
	data->Green_factor = 0;
	data->Blue_factor = 0;
}

void initialize_plane_julia(t_mlx_data *data, char **argv)
{
    double ratio = (double)HEIGHT / (double)WIDTH;
    double rangeRe;

    data->zoom_factor = 0.95;
    data->MinRe = -2.0;
    data->MaxRe = 2.0;
    data->MinIm = -2.0 * ratio;
    data->MaxIm = 2.0 * ratio;
    rangeRe = data->MaxRe - data->MinRe;
    data->Re_factor = rangeRe / (WIDTH - 1);
    data->Im_factor = (data->MaxIm - data->MinIm) / (HEIGHT - 1);
    data->c_re = (double)ft_atoi(argv[2]);
    data->c_im = (double)ft_atoi(argv[3]);
}
