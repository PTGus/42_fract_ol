/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_events.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumendes <gumendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:23:19 by gumendes          #+#    #+#             */
/*   Updated: 2025/01/03 16:31:35 by gumendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/**
 * @brief Resumes calculation of the sets after certain interactions.
 */
void	ft_resume(t_mlx_data *data)
{
	if (data->fractal_type == 0)
		mlx_loop_hook(data->mlx_ptr, mandelbrot, data);
	else if (data->fractal_type == 1)
		mlx_loop_hook(data->mlx_ptr, julia, data);
	else if (data->fractal_type == 2)
		mlx_loop_hook(data->mlx_ptr, newton, data);
	else if (data->fractal_type == 3)
		mlx_loop_hook(data->mlx_ptr, burning_ship, data);
}

/**
 * @brief Moves the set in accordance to button press.
 *  (left, up, right, down, respectively)
 */
void	ft_winmove(int keysym, t_mlx_data *data)
{
	if (keysym == 65361)
	{
		data->min_re -= 0.1 * ((data->max_re - data->min_re) * 0.1);
		data->max_re -= 0.1 * ((data->max_re - data->min_re) * 0.1);
	}
	else if (keysym == 65362)
	{
		data->min_im += 0.1 * ((data->max_im - data->min_im) * 0.1);
		data->max_im += 0.1 * ((data->max_im - data->min_im) * 0.1);
	}
	else if (keysym == 65363)
	{
		data->min_re += 0.1 * ((data->max_re - data->min_re) * 0.1);
		data->max_re += 0.1 * ((data->max_re - data->min_re) * 0.1);
	}
	else if (keysym == 65364)
	{
		data->min_im -= 0.1 * ((data->max_im - data->min_im) * 0.1);
		data->max_im -= 0.1 * ((data->max_im - data->min_im) * 0.1);
	}
	ft_resume(data);
}

/**
 * @brief Receives inputs and decides which action should be taken.
 */
int	handle_input(int keysym, t_mlx_data *data)
{
	if (keysym == XK_Escape)
	{
		ft_printf("Exiting.\n");
		cleanup(data);
		exit (0);
	}
	else if (keysym == 65361 || keysym == 65362
		|| keysym == 65363 || keysym == 65364)
	{
		ft_printf("Moving.\n");
		ft_winmove(keysym, data);
		return (0);
	}
	else if (keysym == 106 || keysym == 107)
		ft_next_color(keysym, data);
	else if (keysym >= 49 && keysym <= 52)
		ft_change_frac(data, keysym);
	else
		return (0);
	return (1);
}

/**
 * @brief Tells the program to free everything and close the window
 * when Escape or the cross to close the window is pressed.
 */
int	close_window(t_mlx_data *data)
{
	cleanup(data);
	exit (0);
}
