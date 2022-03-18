/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 15:38:26 by hharit            #+#    #+#             */
/*   Updated: 2022/03/17 02:14:40 by hharit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	b_ship_calcul(t_fractol *fr)
{
	double	x;
	double	y;
	double	new_x;

	x = 0;
	y = 0;
	fr->iteration = 0;
	new_x = 0;
	fr->c_re = fr->c_re_min + fr->col * fr->pixelwidth + fr->move_re;
	while (x * x + y * y < 4 && fr->iteration < fr->max_iter)
	{
		new_x = x * x - y * y + fr->c_re;
		y = fabs(2 * x * y) + fr->c_im;
		x = new_x;
		fr->iteration++;
	}
}

void	b_ship_set(t_fractol *fr)
{
	int		color;

	color = 0xFF0000;
	fr->row = 0;
	fr->pixelwidth = (fr->c_re_max - fr->c_re_min) / (fr->width);
	fr->pixelheight = (fr->c_im_max - fr->c_im_min) / (fr->height);
	while (fr->row < fr->height)
	{
		fr->col = 0;
		fr->c_im = fr->c_im_min + fr->row * fr->pixelheight + fr->move_im;
		while (fr->col < fr->width)
		{
			b_ship_calcul(fr);
			fr->color = fr->iteration * 255 * 40 / fr->max_iter;
			if (fr->iteration < fr->max_iter)
				my_mlx_pixel_put(fr, fr->col, fr->row, fr->color);
			else
				my_mlx_pixel_put(fr, fr->col, fr->row, 0x000000);
			fr->col++;
		}
		fr->row++;
	}
	mlx_put_image_to_window(fr->mlx, fr->win, fr->img, 0, 0);
}
