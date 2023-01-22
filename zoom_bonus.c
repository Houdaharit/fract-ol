/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharit <hharit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 03:30:29 by hharit            #+#    #+#             */
/*   Updated: 2023/01/23 00:01:58 by hharit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mouse_hook(int x, int y, t_fractol *fr)
{
	fr->mouse_re = (double)x / (fr->width
			/ (fr->c_re_max - fr->c_re_min)) + fr->c_re_min;
	fr->mouse_im = (double)y / (fr->height
			/ (fr->c_im_max - fr->c_im_min)) + fr->c_im_min;
	return (0);
}

double	interpolate(double start, double end, double interpolation)
{
	return (start + ((end - start) * interpolation));
}

void	ft_zoom(t_fractol *fr)
{
	fr->zoom = 1.0 / fr->zoom;
	fr->c_re_min = interpolate(fr->mouse_re, fr->c_re_min, fr->zoom);
	fr->c_re_max = interpolate(fr->mouse_re, fr->c_re_max, fr->zoom);
	fr->c_im_min = interpolate(fr->mouse_im, fr->c_im_min, fr->zoom);
	fr->c_im_max = interpolate(fr->mouse_im, fr->c_im_max, fr->zoom);
	if (fr->zoom > 1)
		fr->step /= fr->zoom;
	else if (fr->zoom < 1)
		fr->step *= fr->zoom;
}

int	hook_mouse(int button, int x, int y, t_fractol *fr)
{
	(void)x, (void)y;
	if (button == 1)
	{
		init(fr);
		fr->img = mlx_new_image(fr->mlx, fr->width, fr->height);
		fr->addr = mlx_get_data_addr(fr->img, &(fr->bits_per_pixel),
				&(fr->line_length), &(fr->endian));
		ft_zoom(fr);
		draw_set(fr);
	}
	if (button == 4)
	{
		fr->zoom = 1.0 / 2.0;
		fr->img = mlx_new_image(fr->mlx, fr->width, fr->height);
		fr->addr = mlx_get_data_addr(fr->img, &(fr->bits_per_pixel),
				&(fr->line_length), &(fr->endian));
		ft_zoom(fr);
		draw_set(fr);
	}
	if (button == 5)
	{
		fr->zoom = 2.0;
		fr->img = mlx_new_image(fr->mlx, fr->width, fr->height);
		fr->addr = mlx_get_data_addr(fr->img, &(fr->bits_per_pixel),
				&(fr->line_length), &(fr->endian));
		ft_zoom(fr);
		draw_set(fr);
	}
	return (0);
}
