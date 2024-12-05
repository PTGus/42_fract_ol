/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calcs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumendes <gumendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:54:51 by gumendes          #+#    #+#             */
/*   Updated: 2024/12/05 12:01:40 by gumendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

unsigned int mandelbrot_iteration(t_mlx_data *data)
{
    unsigned int n = 0;
    double Z_re = data->Z_re;
    double Z_im = data->Z_im;
    double Z_re2 = Z_re * Z_re;
    double Z_im2 = Z_im * Z_im;

    while (n < MaxIter && (Z_re2 + Z_im2 <= 4))
    {
        Z_im = 2 * Z_re * Z_im + data->c_im;
        Z_re = Z_re2 - Z_im2 + data->c_re;
        Z_re2 = Z_re * Z_re;
        Z_im2 = Z_im * Z_im;
        n++;
    }
    return n;
}

unsigned int julia_iteration(double Z_re, double Z_im, double c_re, double c_im)
{
    unsigned int n;
    double Z_re2;
	double Z_im2;

	n = 0;
    while (n < MaxIter)
    {
        Z_re2 = Z_re * Z_re;
        Z_im2 = Z_im * Z_im;
        if (Z_re2 + Z_im2 > 4)
            break ;
        Z_im = 2 * Z_re * Z_im + c_im;
        Z_re = Z_re2 - Z_im2 + c_re;
        n++;
    }
    return n;
}
