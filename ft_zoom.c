/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zoom.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumendes <gumendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 13:48:03 by gumendes          #+#    #+#             */
/*   Updated: 2024/12/05 12:41:40 by gumendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_enlarge(t_mlx_data *data, double re_center, double im_center)
{
	data->MinRe = re_center + (data->MinRe - re_center) * data->zoom_factor;
	data->MaxRe = re_center + (data->MaxRe - re_center) * data->zoom_factor;
	data->MinIm = im_center + (data->MinIm - im_center) * data->zoom_factor;
	data->MaxIm = im_center + (data->MaxIm - im_center) * data->zoom_factor;
}

void	ft_shrink(t_mlx_data *data, double re_center, double im_center)
{
	data->MinRe = re_center + (data->MinRe - re_center) / data->zoom_factor;
	data->MaxRe = re_center + (data->MaxRe - re_center) / data->zoom_factor;
	data->MinIm = im_center + (data->MinIm - im_center) / data->zoom_factor;
	data->MaxIm = im_center + (data->MaxIm - im_center) / data->zoom_factor;
}

int	ft_zoom(int keysym, int x, int y, t_mlx_data *data)
{
	double	re_center;
	double	im_center;

	(void)x;
	(void)y;
	re_center = (data->MinRe + data->MaxRe) / 2.0;
	im_center = (data->MinIm + data->MaxIm) / 2.0;
	if (keysym == 4)
		ft_enlarge(data, re_center, im_center);
	else if (keysym == 5)
		ft_shrink(data, re_center, im_center);
	data->Re_factor = (data->MaxRe - data->MinRe) / (WIDTH - 1);
	data->Im_factor = (data->MaxIm - data->MinIm) / (HEIGHT - 1);
	ft_resume(data);
	return (1);
}
