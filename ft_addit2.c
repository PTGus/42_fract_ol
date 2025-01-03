/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addit2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumendes <gumendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:37:51 by gumendes          #+#    #+#             */
/*   Updated: 2025/01/03 16:39:57 by gumendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/**
 * @brief Tells the program to start
 *  calculating the needed set.
 */
void	ft_init_fract(t_mlx_data *data)
{
	if (data->fractal_type == 0)
		mandelbrot(data);
	else if (data->fractal_type == 1)
		julia(data);
	else if (data->fractal_type == 2)
		newton(data);
	else if (data->fractal_type == 3)
		burning_ship(data);
}

/**
 * @brief Clears the image buffer.
 */
void	clear_image(t_mlx_data *data)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			putpixel(data, x, y, 0x000000);
		}
	}
}

/**
 * @brief Initializes the necessary variables for
 *  the burning ship set calculations.
 */
void	initialize_plane_burn(t_mlx_data *data)
{
	double	ratio;
	double	range_re;

	data->zoom_factor = 0.95;
	data->min_re = -2.5;
	data->max_re = 1.0;
	data->max_im = -1.5;
	data->min_im = 2.0;
	ratio = (double)HEIGHT / (double)WIDTH;
	range_re = data->max_re - data->min_re;
	data->re_factor = range_re / (WIDTH - 1);
	data->im_factor = (data->max_im - data->min_im) / (HEIGHT - 1);
	data->red_factor = 1;
	data->green_factor = 1;
	data->blue_factor = 1;
}

int	is_valid_double(const char *str)
{
	int	i;
	int	has_dot;

	i = 0;
	has_dot = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] == '.')
		{
			if (has_dot)
				return (0);
			has_dot = 1;
		}
		else if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (i > 0);
}

void	ft_change_frac(t_mlx_data *data, int keysym)
{
	if (keysym == 49)
		data->fractal_type = 0;
	if (keysym == 50)
		data->fractal_type = 1;
	if (keysym == 51)
		data->fractal_type = 2;
	if (keysym == 52)
		data->fractal_type = 3;
	ft_re_init(data);
}
