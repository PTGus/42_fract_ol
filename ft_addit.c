/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumendes <gumendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:28:56 by gumendes          #+#    #+#             */
/*   Updated: 2025/01/03 16:32:49 by gumendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	parse_fraction(const char *str, size_t i);
double	convert_to_double(const char *str);

/**
 * @brief Initializes the necessary variables
 *  for the mandelbrot set calculations.
 */
void	initialize_plane_mandelbrot(t_mlx_data *data)
{
	double	ratio;
	double	range_re;

	data->zoom_factor = 0.95;
	data->min_re = -2.1;
	data->max_re = 0.5;
	data->min_im = -1.2;
	ratio = (double)HEIGHT / (double)WIDTH;
	range_re = data->max_re - data->min_re;
	data->max_im = 1.3;
	data->re_factor = range_re / (WIDTH - 1);
	data->im_factor = (data->max_im - data->min_im) / (HEIGHT - 1);
	data->red_factor = 1;
	data->green_factor = 1;
	data->blue_factor = 1;
}

/**
 * @brief Initializes the necessary variables for the julia set calculations.
 */
void	initialize_plane_julia(t_mlx_data *data, char **argv)
{
	double	ratio;
	double	range_re;

	ratio = (double)HEIGHT / (double)WIDTH;
	data->zoom_factor = 0.95;
	data->min_re = -2.0;
	data->max_re = 2.0;
	data->min_im = -2.0 * ratio;
	data->max_im = 2.0 * ratio;
	range_re = data->max_re - data->min_re;
	data->re_factor = range_re / (WIDTH - 1);
	data->im_factor = (data->max_im - data->min_im) / (HEIGHT - 1);
	data->c_re = -0.745429;
	data->c_im = 0.05;
	if (argv[2] != NULL && argv[3] != NULL)
	{
		data->c_re = convert_to_double(argv[2]);
		data->c_im = convert_to_double(argv[3]);
	}
	data->red_factor = 1;
	data->green_factor = 1;
	data->blue_factor = 1;
}

/**
 * @brief Initializes the necessary variables for the newton set calculations.
 */
void	initialize_plane_newton(t_mlx_data *data)
{
	double	ratio;
	double	range_re;

	data->zoom_factor = 0.95;
	data->min_re = -2.0;
	data->max_re = 2.0;
	data->min_im = -2.0;
	data->max_im = 2.0;
	ratio = (double)HEIGHT / (double)WIDTH;
	range_re = data->max_re - data->min_re;
	data->re_factor = range_re / (WIDTH - 1);
	data->im_factor = (data->max_im - data->min_im) / (HEIGHT - 1);
	data->red_factor = 1;
	data->green_factor = 1;
	data->blue_factor = 1;
	data->fractal_type = 2;
	data->newt->z_re2 = 0;
	data->newt->z_im2 = 0;
	data->newt->f_re = 0;
	data->newt->f_im = 0;
	data->newt->df_re = 0;
	data->newt->df_im = 0;
	data->newt->denom = 0;
	data->newt->tmp_re = 0;
}

/**
 * @brief Analyses a string or input that represents a
 *  fraction and then converts it into usable data.
 */
double	parse_fraction(const char *str, size_t i)
{
	double	fraction;
	int		divisor;

	fraction = 0.0;
	divisor = 1;
	i++;
	while (ft_isdigit(str[i]))
	{
		fraction = fraction * 10 + (str[i] - '0');
		divisor *= 10;
		(i)++;
	}
	return (fraction / divisor);
}

/**
 * @brief Analyses a string or input that represents
 *  a fraction and then converts it into a double.
 *  (atoi for the double variable)
 */
double	convert_to_double(const char *str)
{
	double	result;
	double	fraction;
	int		sign;
	size_t	i;

	result = 0.0;
	fraction = 0.0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	if (str[i] == '.')
		fraction = parse_fraction(str, i);
	return (sign * (result + fraction));
}
