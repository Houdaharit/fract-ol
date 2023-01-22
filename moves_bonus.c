/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 21:17:10 by hharit            #+#    #+#             */
/*   Updated: 2023/01/23 00:01:26 by hharit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	move_re(t_fractol *fr, int keycode)
{
	if (keycode == 124)
	{
		fr->move_re += fr->step;
		fr->img = mlx_new_image(fr->mlx, fr->width, fr->height);
		fr->addr = mlx_get_data_addr(fr->img, &(fr->bits_per_pixel),
				&(fr->line_length), &(fr->endian));

		draw_set(fr);
	}
	if (keycode == 123)
	{
		fr->move_re -= fr->step;
		fr->img = mlx_new_image(fr->mlx, fr->width, fr->height);
		fr->addr = mlx_get_data_addr(fr->img, &(fr->bits_per_pixel),
				&(fr->line_length), &(fr->endian));
		draw_set(fr);
	}
}

void	move_im(t_fractol *fr, int keycode)
{
	if (keycode == 125)
	{
		fr->move_im += fr->step;
		fr->img = mlx_new_image(fr->mlx, fr->width, fr->height);
		fr->addr = mlx_get_data_addr(fr->img, &(fr->bits_per_pixel),
				&(fr->line_length), &(fr->endian));

		draw_set(fr);
	}
	if (keycode == 126)
	{
		fr->move_im -= fr->step;
		fr->img = mlx_new_image(fr->mlx, fr->width, fr->height);
		fr->addr = mlx_get_data_addr(fr->img, &(fr->bits_per_pixel),
				&(fr->line_length), &(fr->endian));

		draw_set(fr);
	}
}

int	move(int keycode, t_fractol *fr)
{
	if (keycode == 53)
		destroy(fr);
	if (keycode == 124 || keycode == 123)
		move_re(fr, keycode);
	if (keycode == 125 || keycode == 126)
		move_im(fr, keycode);
	return (0);
}
