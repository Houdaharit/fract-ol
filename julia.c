/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 21:25:24 by hharit            #+#    #+#             */
/*   Updated: 2022/04/03 00:44:50 by hharit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	calcul_julia(t_fractol *fr)
{
	double	x0;
	double	y0;
	double	temp;

	fr->c_re = fr->c_re_min + fr->col
		* ((fr->c_re_max - fr->c_re_min) / fr->width) + fr->move_re;
	fr->c_im = fr->c_im_min + fr->row
		* ((fr->c_im_max - fr->c_im_min) / fr->height) + fr->move_im;
	x0 = fr->c_re;
	y0 = fr->c_im;
	fr->iteration = 0;
	while (x0 * x0 + y0 * y0 <= 4 && fr->iteration < fr->max_iter)
	{
		temp = x0 * x0 - y0 * y0 + fr->c_re_j;
		y0 = 2 * x0 * y0 + fr->c_im_j;
		x0 = temp;
		fr->iteration++;
	}
}

void	julia(t_fractol *fr)
{
	fr->row = 0;
	while (fr->row < fr->height)
	{
		fr->col = 0;
		while (fr->col < fr->width)
		{
			calcul_julia(fr);
			fr->color = colors()[fr->iteration % 16];
			//fr->color = fr->iteration * 5 * 255 / fr->max_iter;
			if (fr->iteration < fr->max_iter)
				my_mlx_pixel_put(fr, fr->col, fr->row, fr->color);
			else
				my_mlx_pixel_put(fr, fr->col, fr->row, 0xFFFFFF);
			fr->col++;
		}
		fr->row++;
	}
	mlx_put_image_to_window(fr->mlx, fr->win, fr->img, 0, 0);
}
