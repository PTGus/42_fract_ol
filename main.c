/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumendes <gumendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:38:28 by gumendes          #+#    #+#             */
/*   Updated: 2025/01/03 17:05:34 by gumendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_free(t_mlx_data *data);
int		mal_check(t_mlx_data *data);
void	ft_discover_fract(t_mlx_data *data, int argc, char **argv);
void	ft_check_julia(t_mlx_data *data, int argc, char **argv);

int	main(int argc, char **argv)
{
	t_mlx_data	*data;

	if (argc > 4)
		bigerror();
	else if (argc < 2)
		lilerror();
	data = malloc(sizeof(t_mlx_data));
	data->newt = malloc(sizeof(t_newt));
	if (mal_check(data) == 1)
		return (1);
	ft_discover_fract(data, argc, argv);
	if ((data->fractal_type == 0 || data->fractal_type == 2
			|| data->fractal_type == 3) && argc > 2)
	{
		bigerror();
		return (1);
	}
	ft_controls();
	ft_init(data, argv);
	ft_free(data);
	if (data->mlx_ptr == NULL || data->win_ptr == NULL)
		return (1);
	return (0);
}

void	ft_check_julia(t_mlx_data *data, int argc, char **argv)
{
	if (argc == 2)
	{
		data->fractal_type = 1;
		return ;
	}
	else if (argc != 4 || !is_valid_double(argv[2])
		|| !is_valid_double(argv[3]))
	{
		ft_printf("Error: Invalid parameters for Julia set.\n");
		ft_printf("Please use only numbers for example:");
		ft_printf("-0.2 1\n");
		exit (1);
	}
	data->fractal_type = 1;
}

/**
 * @brief Tells the program which set it should calculate.
 */
void	ft_discover_fract(t_mlx_data *data, int argc, char **argv)
{
	if (ft_strlen(argv[1]) == ft_strlen("mandelbrot")
		&& ft_strncmp(argv[1], "mandelbrot", ft_strlen("mandelbrot")) == 0)
	{
		data->fractal_type = 0;
		return ;
	}
	else if (ft_strlen(argv[1]) == ft_strlen("julia")
		&& ft_strncmp(argv[1], "julia", ft_strlen("julia")) == 0)
	{
		ft_check_julia(data, argc, argv);
		return ;
	}
	if (ft_strlen(argv[1]) == ft_strlen("newton")
		&& ft_strncmp(argv[1], "newton", ft_strlen("newton")) == 0)
	{
		data->fractal_type = 2;
		return ;
	}
	if (ft_strlen(argv[1]) == ft_strlen("ship")
		&& ft_strncmp(argv[1], "ship", ft_strlen("ship")) == 0)
	{
		data->fractal_type = 3;
		return ;
	}
	ft_error(data);
}

/**
 * @brief Checks wether the allocation
 *  of memory was successful or not.
 */
int	mal_check(t_mlx_data *data)
{
	if (!data || data->newt == NULL)
	{
		ft_free(data);
		return (1);
	}
	return (0);
}

/**
 * @brief Frees the memory allocated to the structs.
 */
void	ft_free(t_mlx_data *data)
{
	if (data->newt != NULL)
		free(data->newt);
	if (data != NULL)
		free(data);
	exit (0);
}
