/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 19:47:21 by hharit            #+#    #+#             */
/*   Updated: 2022/03/17 02:00:39 by hharit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_j(t_fractol *fr, char **argv)
{
	if (!ft_strcmp(argv[2], "0.285") && !ft_strcmp(argv[3], "0"))
	{
		fr->c_re_j = 0.285;
		fr->c_im_j = 0.0;
	}
	else if (!ft_strcmp(argv[2], "0.285") && !ft_strcmp(argv[3], "0.01"))
	{
		fr->c_re_j = 0.285;
		fr->c_im_j = 0.01;
	}
	else if (!ft_strcmp(argv[2], "0.45") && !ft_strcmp(argv[3], "0.1428"))
	{
		fr->c_re_j = 0.45;
		fr->c_im_j = 0.1428;
	}
	else
		message_j();
}

void	draw_set(t_fractol *fr)
{
	if (fr->set == 1)
		mandelbrot_set(fr);
	if (fr->set == 2)
		julia(fr);
	if (fr->set == 3)
		b_ship_set(fr);
}

void	sets(t_fractol *fr, int argc, char **argv)
{
	if (argc == 2)
	{
		if (!ft_strcmp(argv[1], "Mandelbrot"))
		{
			fr->set = 1;
			draw_set(fr);
		}
		if (!ft_strcmp(argv[1], "Burning ship"))
		{
			fr->set = 3;
			draw_set(fr);
		}
	}
	if (argc == 4
		&& !ft_strcmp(argv[1], "Julia"))
	{
		init_j(fr, argv);
		fr->set = 2;
		draw_set(fr);
	}
}

int	main(int argc, char **argv)
{
	t_fractol	*fr;

	message(argc, argv);
	fr = (t_fractol *)malloc(sizeof(t_fractol));
	fr->name = argv[1];
	init(fr);
	initialize(fr);
	sets(fr, argc, argv);
	mlx_hook(fr->win, 2, 1L >> 0, move, (void *)fr);
	mlx_hook(fr->win, 17, 0, destroy, (void *)fr);
	mlx_hook(fr->win, 6, 0, mouse_hook, (void *)fr);
	mlx_hook(fr->win, 4, 0, hook_mouse, (void *)fr);
	mlx_put_image_to_window(fr->mlx, fr->win, fr->img, 0, 0);
	mlx_loop(fr->mlx);
}
