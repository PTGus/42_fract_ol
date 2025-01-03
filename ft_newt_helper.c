/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newt_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumendes <gumendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 11:28:08 by gumendes          #+#    #+#             */
/*   Updated: 2025/01/03 15:04:37 by gumendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/**
 * @brief Makes all the required calculations for the
 * newton set.
 */
void	compute_newton_step(t_mlx_data *data, double *z_re, double *z_im)
{
	data->newt->z_re2 = (*z_re) * (*z_re);
	data->newt->z_im2 = (*z_im) * (*z_im);
	data->newt->f_re = (*z_re)
		* (data->newt->z_re2 - 3 * data->newt->z_im2) - 1;
	data->newt->f_im = (*z_im) * (3 * data->newt->z_re2 - data->newt->z_im2);
	data->newt->df_re = 3 * (data->newt->z_re2 - data->newt->z_im2);
	data->newt->df_im = 6 * (*z_re) * (*z_im);
	data->newt->denom = data->newt->df_re
		* data->newt->df_re + data->newt->df_im * data->newt->df_im;
	data->newt->tmp_re = (*z_re) - (data->newt->f_re
			* data->newt->df_re + data->newt->f_im
			* data->newt->df_im) / data->newt->denom;
	*z_im = (*z_im) - (data->newt->f_im * data->newt->df_re
			- data->newt->f_re * data->newt->df_im) / data->newt->denom;
	*z_re = data->newt->tmp_re;
}

/**
 * @brief Detects wether the pixel is
 *  within bounds of the newton set or not.
 */
unsigned int	detect_root(double z_re, double z_im)
{
	double	tolerance;

	tolerance = 0.000001;
	if ((z_re - 1) * (z_re - 1) + z_im * z_im < tolerance)
		return (1);
	if ((z_re + 0.5) * (z_re + 0.5)
		+ (z_im - 0.866) * (z_im - 0.866) < tolerance)
		return (2);
	if ((z_re + 0.5) * (z_re + 0.5)
		+ (z_im + 0.866) * (z_im + 0.866) < tolerance)
		return (4);
	return (0);
}
