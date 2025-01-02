/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calcs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumendes <gumendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:54:51 by gumendes          #+#    #+#             */
/*   Updated: 2025/01/02 16:44:48 by gumendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

unsigned int mandelbrot_iteration(t_mlx_data *data)
{
    unsigned int n = 0;
    double z_re = data->z_re;
    double z_im = data->z_im;
    double z_re2 = z_re * z_re;
    double z_im2 = z_im * z_im;

    while (n < MaxIter && (z_re2 + z_im2 <= 4))
    {
        z_im = 2 * z_re * z_im + data->c_im;
        z_re = z_re2 - z_im2 + data->c_re;
        z_re2 = z_re * z_re;
        z_im2 = z_im * z_im;
        n++;
    }
    return n;
}

unsigned int julia_iteration(double z_re, double z_im, double c_re, double c_im)
{
    unsigned int n;
    double z_re2;
	double z_im2;

	n = 0;
    while (n < MaxIter)
    {
        z_re2 = z_re * z_re;
        z_im2 = z_im * z_im;
        if (z_re2 + z_im2 > 4)
            break ;
        z_im = 2 * z_re * z_im + c_im;
        z_re = z_re2 - z_im2 + c_re;
        n++;
    }
    return n;
}
