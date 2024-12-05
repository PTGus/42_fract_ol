/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_events.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumendes <gumendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:23:19 by gumendes          #+#    #+#             */
/*   Updated: 2024/12/05 15:52:58 by gumendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_resume(t_mlx_data *data)
{
	if (data->fractal_type == 0)
		mlx_loop_hook(data->mlx_ptr, mandelbrot, data);
	else if (data->fractal_type == 1)
		mlx_loop_hook(data->mlx_ptr, julia, data);
}

void	ft_winmove(int keysym, t_mlx_data *data)
{
	double re_step = (data->MaxRe - data->MinRe) * 0.1;
    double im_step = (data->MaxIm - data->MinIm) * 0.1;
	if (keysym == 65361)
	{
		data->MinRe -= 0.1 * re_step;
		data->MaxRe -= 0.1 * re_step;
	}
	else if (keysym == 65362)
	{
		data->MinIm += 0.1 * im_step;
		data->MaxIm += 0.1 * im_step;
	}
	else if (keysym == 65363)
	{
		data->MinRe += 0.1 * re_step;
		data->MaxRe += 0.1 * re_step;
	}
	else if (keysym == 65364)
	{
		data->MinIm -= 0.1 * im_step;
		data->MaxIm -= 0.1 * im_step;
	}
	ft_resume(data);
}

int	handle_input(int keysym, t_mlx_data *data)
{
	if (keysym == XK_Escape)
	{
		ft_printf("Exiting.");
		cleanup(data);
		exit (0);
	}
	else if (keysym == 65361 || keysym == 65362 || keysym == 65363 || keysym == 65364)
	{
		ft_winmove(keysym, data);
	}
	else
	return (0);
}

int	close_window(t_mlx_data *data)
{
	cleanup(data);
    exit (0);
}
