/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 17:57:53 by hharit            #+#    #+#             */
/*   Updated: 2022/03/19 04:44:18 by hharit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_fractol
{
	void	*mlx;
	void	*win;
	void	*img;
	void	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	double	c_re;
	double	c_im;
	double	c_re_max;
	double	c_re_min;
	double	c_im_max;
	double	c_im_min;
	double	mouse_re;
	double	mouse_im;
	int		mouse_x;
	int		mouse_y;
	double	pixelheight;
	double	pixelwidth;
	int		max_iter;
	int		height;
	int		width;
	int		iteration;
	int		color;
	double	zoom;
	double	step;
	double	col;
	double	row;
	double	c_re_j;
	double	c_im_j;
	double	move_re;
	double	move_im;
	int		set;
	char	*name;
}	t_fractol;

void	init(t_fractol *fr);
int		ft_close(int keycode, t_fractol *vars);
double	interpolate(double start, double end, double interpolation);
void	ft_zoom(t_fractol *vars);
void	my_mlx_pixel_put(t_fractol	*img, int x, int y, int color);
int		mouse_hook(int x, int y, t_fractol *vars);
void	mandelbrot_set(t_fractol *fr);
void	mandelbrot_calcul(t_fractol *fr);
int		hook_mouse(int button, int x, int y, t_fractol *vars);
int		destroy(t_fractol *fr);
void	julia(t_fractol *fr);
int		*colors(void);
int		move(int keycode, t_fractol *fr);
void	hooks(t_fractol *fr);
void	draw_set(t_fractol *fr);
void	sets(t_fractol *fr, int argc, char **argv);
void	init_julia(t_fractol *fr, char **argv);
int		ft_strcmp(char *s1, char *s);
void	initialize(t_fractol *fr);
void	mouse_c(t_fractol *fr);
void	message(int argc, char **argv);
void	message_j(void);
void	ft_putendl_fd(char *s, int fd);
void	b_ship_calcul(t_fractol *fr);
void	b_ship_set(t_fractol *fr);
void	calcul_julia(t_fractol *fr);
void	check_args(int argc, char **argv);
void	check_args_b(int argc, char **argv);
#endif
