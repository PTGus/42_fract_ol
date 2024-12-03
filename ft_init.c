/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumendes <gumendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:21:11 by gumendes          #+#    #+#             */
/*   Updated: 2024/12/03 15:27:23 by gumendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_init(t_mlx_data *data)
{
    data->mlx_ptr = mlx_init();
    if (data->mlx_ptr == NULL)
    {
        ft_printf("mlx_init failed\n");
        return ;
    }
    data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, "My window");
    if (NULL == data->win_ptr)
    {
        mlx_destroy_display(data->mlx_ptr);
        free(data->mlx_ptr);
        data->mlx_ptr = NULL;
        return;
    }
    initialize_plane(data, (int)WIDTH, (int)HEIGHT);
    mandelbrot(data, data->win_ptr);
    mlx_key_hook(data->win_ptr, handle_input, data);
    mlx_mouse_hook(data->win_ptr, ft_zoom, data);
    mlx_hook(data->win_ptr, ON_DESTROY, 0, close_window, data);
    mlx_loop(data->mlx_ptr);
}
