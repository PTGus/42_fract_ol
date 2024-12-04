/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumendes <gumendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:27:22 by gumendes          #+#    #+#             */
/*   Updated: 2024/12/04 14:51:15 by gumendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "minilibx-linux/mlx.h"
# include "libft/libft.h"
# include <stdio.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>

# define WIDTH			 920
# define HEIGHT			 920
# define CMIN			-2.0
# define CMAX			2.0
# define MaxIter		50

// Structures //

typedef struct s_mlx_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*img_data;
	int		bpp;
    int		line_len;
    int		endian;
    double	MinRe;
    double	MaxRe;
    double	MinIm;
    double	MaxIm;
    double	Re_factor;
    double	Im_factor;
    double	c_re;
    double	c_im;
    double	Z_re;
    double	Z_im;
    double	Z_re2;
    double	Z_im2;
	double  zoom_factor;
	double	Red_factor;
	double	Green_factor;
	double	Blue_factor;
}	t_mlx_data;

enum
{
	A_LEFT = 65361,
	A_UP = 65362,
	A_RIGHT = 65363,
	A_DOWN = 65364,
	ON_DESTROY = 17
};

// Main funtions //
void			putpixel(t_mlx_data *data, int x, unsigned int y, unsigned int color);
int				close_window(t_mlx_data *data);
int				handle_input(int keysym, t_mlx_data *data);
void			mandelbrot(t_mlx_data *data);
void			ft_init(t_mlx_data *data, char **argv);
void 			initialize_plane_mandelbrot(t_mlx_data *data);
unsigned int	mandelbrot_iteration(t_mlx_data *data);
int				color(int t, int r, int g, int b, t_mlx_data *data);
int 			ft_zoom(int keysym, int x, int y, t_mlx_data *data);
void			lilerror(void);
void			bigerror(void);
int				ft_initimg(t_mlx_data *data);
int				ft_initwin(t_mlx_data *data);
int				ft_initmlx(t_mlx_data *data);
void 			initialize_plane_julia(t_mlx_data *data, char **argv);
void			julia(t_mlx_data *data);
unsigned int	julia_iteration(double Z_re, double Z_im, double c_re, double c_im);

// Printf //
int	ft_printf(const char *str, ...);

#endif