/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumendes <gumendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 10:18:08 by gumendes          #+#    #+#             */
/*   Updated: 2024/12/05 15:09:12 by gumendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// void	ft_colorselect(t_mlx_data *data)
// {

// }

int	color(int r, int g, int b, t_mlx_data *data)
{
	(void)data;
	return (*(int *)(unsigned char [4]){b, g, r});
}
