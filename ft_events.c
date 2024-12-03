/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_events.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumendes <gumendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:23:19 by gumendes          #+#    #+#             */
/*   Updated: 2024/12/03 15:57:21 by gumendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_winmove(int keysym, t_mlx_data *data)
{
	double re_step = (data->MaxRe - data->MinRe) * 0.1;
    double im_step = (data->MaxIm - data->MinIm) * 0.1;
	if (keysym == 65361)
	{
		data->MinRe -= re_step;
		data->MaxRe -= re_step;
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
	mandelbrot(data, data->win_ptr);
}

int	handle_input(int keysym, t_mlx_data *data)
{
	if (keysym == XK_Escape)
	{
		printf("The %d key (ESC) was pressed\n", keysym);
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_display(data->mlx_ptr);
        free(data->mlx_ptr);
		exit (1);
	}
	else if (keysym == 65361 || keysym == 65362 || keysym == 65363 || keysym == 65364)
	{
		ft_winmove(keysym, data);
	}
	else
	printf("The %d key was pressed\n", keysym);
	return (0);
}


int	close_window(t_mlx_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
    free(data->mlx_ptr);
	exit (1);
}


