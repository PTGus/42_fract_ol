/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calcs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumendes <gumendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:54:51 by gumendes          #+#    #+#             */
/*   Updated: 2025/01/03 17:06:49 by gumendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/**
 * @brief Iterates through a certain number in order to find out if
 *  it belongs in the mandelbrot set.
 */
unsigned int	mandelbrot_iteration(t_mlx_data *data)
{
	unsigned int	n;
	double			z_re;
	double			z_im;
	double			z_re2;
	double			z_im2;

	n = 0;
	z_re = data->z_re;
	z_im = data->z_im;
	z_re2 = z_re * z_re;
	z_im2 = z_im * z_im;
	while (n < MAXITER && (z_re2 + z_im2 <= 4))
	{
		z_im = 2 * z_re * z_im + data->c_im;
		z_re = z_re2 - z_im2 + data->c_re;
		z_re2 = z_re * z_re;
		z_im2 = z_im * z_im;
		n++;
	}
	return (n);
}

/**
 * @brief Iterates through a certain number in order to find out if
 *  it belongs in the julia set.
 */
unsigned int	julia_iteration(double z_re, double z_im,
					double c_re, double c_im)
{
	unsigned int	n;
	double			z_re2;
	double			z_im2;

	n = 0;
	while (n < MAXITER)
	{
		z_re2 = z_re * z_re;
		z_im2 = z_im * z_im;
		if (z_re2 + z_im2 > 4)
			break ;
		z_im = 2 * z_re * z_im + c_im;
		z_re = z_re2 - z_im2 + c_re;
		n++;
	}
	return (n);
}

/**
 * @brief Iterates through a certain number in order to find out if
 *  it belongs in the newton set.
 */
unsigned int	newton_iteration(t_mlx_data *data)
{
	double			z_re;
	double			z_im;
	unsigned int	n;
	unsigned int	root;

	z_re = data->z_re;
	z_im = data->c_im;
	n = 0;
	while (n++ < MAXITER)
	{
		compute_newton_step(data, &z_re, &z_im);
		root = detect_root(z_re, z_im);
		if (root > 0)
			return (n | root);
	}
	return (0);
}

int	burning_ship_iteration(t_mlx_data *data)
{
	unsigned int	n;
	double			z_re2;
	double			z_im2;
	double			new_re;
	double			new_im;

	n = 0;
	z_re2 = data->z_re * data->z_re;
	z_im2 = data->z_im * data->z_im;
	while (n < MAXITER && (z_re2 + z_im2 <= 4))
	{
		new_re = z_re2 - z_im2 + data->c_re;
		new_im = 2 * fabs(data->z_re) * fabs(data->z_im) + data->c_im;
		data->z_re = new_re;
		data->z_im = new_im;
		z_re2 = data->z_re * data->z_re;
		z_im2 = data->z_im * data->z_im;
		n++;
	}
	return (n);
}
