/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumendes <gumendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:27:22 by gumendes          #+#    #+#             */
/*   Updated: 2025/01/03 17:12:05 by gumendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx/mlx.h"
# include "libft/libft.h"
# include <stdio.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>

# define WIDTH			 920
# define HEIGHT			 920
# define CMIN			-2.0
# define CMAX			2.0
# define MAXITER		50

// Structures //

typedef struct s_newt
{
	double	z_re2;
	double	z_im2;
	double	f_re;
	double	f_im;
	double	df_re;
	double	df_im;
	double	denom;
	double	tmp_re;
}	t_newt;
typedef struct s_mlx_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*img_data;
	int		bpp;
	int		line_len;
	int		endian;
	double	min_re;
	double	max_re;
	double	min_im;
	double	max_im;
	double	re_factor;
	double	im_factor;
	double	c_re;
	double	c_im;
	double	z_re;
	double	z_im;
	double	z_re2;
	double	z_im2;
	double	zoom_factor;
	int		red_factor;
	int		green_factor;
	int		blue_factor;
	int		fractal_type;
	t_newt	*newt;
}	t_mlx_data;

// ft_addit/2/3.c //
void			initialize_plane_mandelbrot(t_mlx_data *data);
void			initialize_plane_julia(t_mlx_data *data, char **argv);
void			reinitialize_plane_julia(t_mlx_data *data);
void			initialize_plane_newton(t_mlx_data *data);
void			initialize_plane_burn(t_mlx_data *data);
double			parse_fraction(const char *str, size_t i);
double			convert_to_double(const char *str);
void			ft_init_fract(t_mlx_data *data);
void			ft_discover_fract(t_mlx_data *data, int argc, char **argv);
void			clear_image(t_mlx_data *data);
int				is_valid_double(const char *str);
void			ft_change_frac(t_mlx_data *data, int keysym);
void			ft_re_init(t_mlx_data *data);
void			ft_reselec_fractal(t_mlx_data *data);

// ft_calcs.c //
unsigned int	mandelbrot_iteration(t_mlx_data *data);
unsigned int	julia_iteration(double z_re, double z_im,
					double c_re, double c_im);
unsigned int	newton_iteration(t_mlx_data *data);
int				burning_ship_iteration(t_mlx_data *data);

// ft_color.c //
int				color(int r, int g, int b, t_mlx_data *data);
void			ft_next_color(int keysym, t_mlx_data *data);

// ft_events.c //
void			ft_resume(t_mlx_data *data);
void			ft_winmove(int keysym, t_mlx_data *data);
int				handle_input(int keysym, t_mlx_data *data);
int				close_window(t_mlx_data *data);

// ft_init.c //
void			ft_init(t_mlx_data *data, char **argv);
int				ft_initimg(t_mlx_data *data);
int				ft_initwin(t_mlx_data *data);
int				ft_initmlx(t_mlx_data *data);
int				ft_selec_fractal(t_mlx_data *data, char **argv);

// ft_kill.c //
void			kill(t_mlx_data *data);
void			cleanup(t_mlx_data *data);

// ft_messages.c //
int				lilerror(void);
int				bigerror(void);
int				ft_error(t_mlx_data *data);
void			ft_controls(void);

// ft_newt_helper.c //
void			compute_newton_step(t_mlx_data *data,
					double *z_re, double *z_im);
unsigned int	detect_root(double z_re, double z_im);

// ft_sets.c //
void			putpixel(t_mlx_data *data, int x,
					unsigned int y, unsigned int color);
int				mandelbrot(t_mlx_data *data);
int				julia(t_mlx_data *data);
int				newton(t_mlx_data *data);
int				burning_ship(t_mlx_data *data);

// ft_zoom.c //
int				ft_zoom(int keysym, int x, int y, t_mlx_data *data);
void			ft_shrink(t_mlx_data *data, double re_center, double im_center);
void			ft_enlarge(t_mlx_data *data,
					double re_center, double im_center);

// main.c //
void			ft_free(t_mlx_data *data);
int				malloc_check(t_mlx_data *data);
void			ft_check_julia(t_mlx_data *data, int argc, char **argv);

// Printf //
int				ft_printf(const char *str, ...);

#endif
