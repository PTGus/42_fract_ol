/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumendes <gumendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:21:11 by gumendes          #+#    #+#             */
/*   Updated: 2024/12/05 15:52:58 by gumendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_initmlx(t_mlx_data *data)
{
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
	{
		return (1);
	}
	return (0);
}

int	ft_initwin(t_mlx_data *data)
{
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, "My window");
	if (NULL == data->win_ptr)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		data->mlx_ptr = NULL;
		return (1);
	}
	return (0);
}

int	ft_initimg(t_mlx_data *data)
{
	data->img_ptr = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	if (!data->img_ptr)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		return (1);
	}
	data->img_data = mlx_get_data_addr(data->img_ptr, &data->bpp, &data->line_len, &data->endian);
	return (0);
}

int	ft_selec_fractal(t_mlx_data *data, char **argv)
{
	if (ft_strncmp(argv[1], "mandelbrot",
			ft_strlen((const char *)argv[1])) == 0)
	{
		data->fractal_type = 0;
		initialize_plane_mandelbrot(data);
		return (0);
	}
	else if (ft_strncmp(argv[1], "julia",
			ft_strlen((const char *)argv[1])) == 0)
	{
		data->fractal_type = 1;
		initialize_plane_julia(data, argv);
		return (0);
	}
	else
	{
		ft_error();
		return (1);
	}
}

void	ft_init(t_mlx_data *data, char **argv)
{
	int	i;

	i = ft_selec_fractal(data, argv);
	if (i == 0)
	{
		if (ft_initmlx(data) == 1)
			return ;
		if (ft_initwin(data) == 1)
			return ;
		if (ft_initimg(data) == 1)
			return ;
		mlx_key_hook(data->win_ptr, handle_input, data);
		mlx_mouse_hook(data->win_ptr, ft_zoom, data);
		mlx_hook(data->win_ptr, ON_DESTROY, 0, close_window, data);
		ft_init_fract(data);
		mlx_loop(data->mlx_ptr);
	}
	else if (i == 1)
		cleanup(data);
}
