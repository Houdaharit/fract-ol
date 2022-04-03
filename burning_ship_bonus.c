/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharit <hharit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 15:38:26 by hharit            #+#    #+#             */
/*   Updated: 2022/03/19 03:15:48 by hharit           ###   ########.fr       */
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
	new_x = 0;
	fr->c_re = fr->c_re_min + fr->col * (fr->c_re_max - fr->c_re_min)
		/ (fr->width) + fr->move_re;
	fr->iteration = 0;
	while (x * x + y * y <= 4 && fr->iteration < fr->max_iter)
	{
		new_x = x * x - y * y + fr->c_re;
		y = fabs(2 * x * y) + fr->c_im;
		x = new_x;
		fr->iteration++;
	}
}

void	b_ship_set(t_fractol *fr)
{
	fr->row = 0;
	while (fr->row < fr->height)
	{
		fr->c_im = fr->c_im_min + fr->row * (fr->c_im_max - fr->c_im_min)
			/ (fr->height) + fr->move_im;
		fr->col = 0;
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
