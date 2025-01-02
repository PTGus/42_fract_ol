/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_events.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumendes <gumendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:23:19 by gumendes          #+#    #+#             */
/*   Updated: 2025/01/02 17:36:19 by gumendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_resume(t_mlx_data *data, int type)
{
	if (type == 0)
		mlx_loop_hook(data->mlx_ptr, mandelbrot, data);
	else if (type == 1)
		mlx_loop_hook(data->mlx_ptr, julia, data);
}

void	ft_winmove(int keysym, t_mlx_data *data)
{
	double re_step = (data->max_re - data->min_re) * 0.1;
    double im_step = (data->max_im - data->min_im) * 0.1;
	if (keysym == 65361)
	{
		data->min_re -= 0.1 * re_step;
		data->max_re -= 0.1 * re_step;
	}
	else if (keysym == 65362)
	{
		data->min_im += 0.1 * im_step;
		data->max_im += 0.1 * im_step;
	}
	else if (keysym == 65363)
	{
		data->min_re += 0.1 * re_step;
		data->max_re += 0.1 * re_step;
	}
	else if (keysym == 65364)
	{
		data->min_im -= 0.1 * im_step;
		data->max_im -= 0.1 * im_step;
	}
	ft_resume(data, data->fractal_type);
}

int	handle_input(int keysym, t_mlx_data *data)
{
	ft_printf("%i\n", keysym);
	if (keysym == XK_Escape)
	{
		ft_printf("Exiting.\n");
		cleanup(data);
		exit (0);
	}
	else if (keysym == 65361 || keysym == 65362 || keysym == 65363 || keysym == 65364)
	{
		ft_winmove(keysym, data);
		return (0);
	}
	else if (keysym == 106 || keysym == 107)
		ft_next_color(keysym, data);
	else
		return (0);
	return (1);
}

int	close_window(t_mlx_data *data)
{
	cleanup(data);
    exit (0);
}
