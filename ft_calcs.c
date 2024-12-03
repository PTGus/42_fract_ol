/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calcs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumendes <gumendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:54:51 by gumendes          #+#    #+#             */
/*   Updated: 2024/12/03 14:46:08 by gumendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

unsigned int mandelbrot_iteration(t_mlx_data *data)
{
    unsigned int n = 0;
	double Z_re2;
	double Z_im2;

    while (n < MaxIter)
    {
        Z_re2 = data->Z_re * data->Z_re;
        Z_im2 = data->Z_im * data->Z_im;
        if (Z_re2 + Z_im2 > 4)
            break;
        data->Z_im = 2 * data->Z_re * data->Z_im + data->c_im;
        data->Z_re = Z_re2 - Z_im2 + data->c_re;
        n++;
    }
    return (n);
}
