/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharit <hharit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 18:06:21 by hharit            #+#    #+#             */
/*   Updated: 2022/04/03 00:43:53 by hharit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_fractol *fr, int x, int y, int color)
{
	char	*dst;

	dst = fr->addr + (y * fr->line_length + x * (fr->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	destroy(t_fractol *fr)
{
	mlx_destroy_window(fr->mlx, fr->win);
	free(fr->mlx);
	exit(0);
	return (0);
}

int	ft_close(int keycode, t_fractol *fr)
{
	if (keycode == 53)
	{
		destroy(fr);
		free(fr->win);
	}
	return (0);
}

void	init(t_fractol *fr)
{
	fr->zoom = 1.0;
	fr->step = 1.5;
	fr->c_re_max = 2.0;
	fr->c_re_min = -2.0;
	fr->c_im_min = -2.0;
	fr->c_im_max = 2.0;
	fr->height = 650;
	fr->width = 650;
	fr->max_iter = 1000;
	fr->move_re = 0.0;
	fr->move_im = 0.0;
}

void	initialize(t_fractol *fr)
{
	fr->mlx = mlx_init();
	fr->win = mlx_new_window(fr->mlx, fr->width, fr->height, fr->name);
	fr->img = mlx_new_image(fr->mlx, fr->width, fr->height);
	fr->addr = mlx_get_data_addr(fr->img, &(fr->bits_per_pixel),
			&(fr->line_length), &(fr->endian));
}
