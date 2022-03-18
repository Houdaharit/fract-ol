/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 21:17:10 by hharit            #+#    #+#             */
/*   Updated: 2022/03/14 01:10:22 by hharit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	move_re(t_fractol *fr, int keycode)
{
	if (keycode == 124)
	{
		fr->move_re += fr->step;
		mlx_clear_window(fr->mlx, fr->win);
		draw_set(fr);
	}
	if (keycode == 123)
	{
		fr->move_re -= fr->step;
		mlx_clear_window(fr->mlx, fr->win);
		draw_set(fr);
	}
}

void	move_im(t_fractol *fr, int keycode)
{
	if (keycode == 125)
	{
		fr->move_im += fr->step;
		mlx_clear_window(fr->mlx, fr->win);
		draw_set(fr);
	}
	if (keycode == 126)
	{
		fr->move_im -= fr->step;
		mlx_clear_window(fr->mlx, fr->win);
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
