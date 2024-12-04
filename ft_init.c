/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumendes <gumendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:21:11 by gumendes          #+#    #+#             */
/*   Updated: 2024/12/04 14:50:48 by gumendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_initmlx(t_mlx_data *data)
{
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
	{
		ft_printf("mlx_init failed\n");
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
		ft_printf("Image creation failed\n");
		return (1);
	}
	data->img_data = mlx_get_data_addr(data->img_ptr, &data->bpp, &data->line_len, &data->endian);
	return (0);
}

void	ft_init(t_mlx_data *data, char **argv)
{
	if (ft_initmlx(data) == 1)
		return ;
	if (ft_initwin(data) == 1)
		return ;
	if (ft_initimg(data) == 1)
		return ;
	if (ft_strncmp(argv[1], "mandelbrot", ft_strlen((const char *)argv[1])) == 0)
	{
		initialize_plane_mandelbrot(data);
		mandelbrot(data);
	}
	else if (ft_strncmp(argv[1], "julia", ft_strlen((const char *)argv[1])) == 0)
	{
		initialize_plane_julia(data, argv);
		julia(data);
	}
	mlx_key_hook(data->win_ptr, handle_input, data);
	ft_printf("starting mouse hook\n");
	mlx_mouse_hook(data->win_ptr, ft_zoom, data);
	mlx_hook(data->win_ptr, ON_DESTROY, 0, close_window, data);
	mlx_loop(data->mlx_ptr);
}
