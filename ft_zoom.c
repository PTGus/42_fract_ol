/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zoom.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumendes <gumendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 13:48:03 by gumendes          #+#    #+#             */
/*   Updated: 2025/01/03 16:12:30 by gumendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/**
 * @brief Zooms in.
 */
void	ft_enlarge(t_mlx_data *data, double re_center, double im_center)
{
	data->min_re = re_center + (data->min_re - re_center) * data->zoom_factor;
	data->max_re = re_center + (data->max_re - re_center) * data->zoom_factor;
	data->min_im = im_center + (data->min_im - im_center) * data->zoom_factor;
	data->max_im = im_center + (data->max_im - im_center) * data->zoom_factor;
}

/**
 * @brief Zooms out.
 */
void	ft_shrink(t_mlx_data *data, double re_center, double im_center)
{
	data->min_re = re_center + (data->min_re - re_center) / data->zoom_factor;
	data->max_re = re_center + (data->max_re - re_center) / data->zoom_factor;
	data->min_im = im_center + (data->min_im - im_center) / data->zoom_factor;
	data->max_im = im_center + (data->max_im - im_center) / data->zoom_factor;
}

/**
 * @brief Selects whether to Zoom in or out of the cursor's position
 *  based on input.
 */
int	ft_zoom(int keysym, int x, int y, t_mlx_data *data)
{
	double	re_center;
	double	im_center;

	re_center = data->min_re + x * data->re_factor;
	im_center = data->max_im - y * data->im_factor;
	if (keysym == 4)
		ft_enlarge(data, re_center, im_center);
	else if (keysym == 5)
		ft_shrink(data, re_center, im_center);
	data->re_factor = (data->max_re - data->min_re) / (WIDTH - 1);
	data->im_factor = (data->max_im - data->min_im) / (HEIGHT - 1);
	ft_resume(data);
	return (1);
}
