/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumendes <gumendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:28:56 by gumendes          #+#    #+#             */
/*   Updated: 2024/12/03 15:43:59 by gumendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void initialize_plane(t_mlx_data *data, int width, int height)
{
    double ratio;
    double rangeRe;
	data->zoom_factor = 0.95;
    data->MinRe = -2.1;
    data->MaxRe = 0.5;
    data->MinIm = -1.2;
    ratio = (double)height / (double)width;
    rangeRe = data->MaxRe - data->MinRe;
    data->MaxIm = 1.3;
    data->Re_factor = rangeRe / (width - 1);
    data->Im_factor = (data->MaxIm - data->MinIm) / (height - 1);
}
