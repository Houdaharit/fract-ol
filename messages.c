/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharit <hharit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 02:08:12 by hharit            #+#    #+#             */
/*   Updated: 2022/03/19 04:44:26 by hharit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	check_args(int argc, char **argv)
{
	if (argc > 2 && !ft_strcmp(argv[1], "Mandelbrot"))
	{
		ft_putendl_fd("Only 1 argument (Mandelbrot)!", 1);
		exit(1);
	}
	if (argc == 4 && !ft_strcmp(argv[1], "Julia"))
	{
		if (ft_strcmp(argv[2], "0.285") && ft_strcmp(argv[2], "0.45"))
			message_j();
		if (ft_strcmp(argv[3], "0") && ft_strcmp(argv[3], "0.01")
			&& ft_strcmp(argv[3], "0.1428"))
			message_j();
	}
}

void	message(int argc, char **argv)
{
	check_args(argc, argv);
	if ((argc < 2 || argc > 4)
		|| (ft_strcmp(argv[1], "Mandelbrot")))
	{
		if (argc == 2 && !ft_strcmp(argv[1], "Julia"))
			message_j();
		if (argc == 4 && !ft_strcmp(argv[1], "Julia"))
			return ;
		ft_putendl_fd("sets: ", 1);
		ft_putendl_fd("\t1. Mandelbrot", 1);
		ft_putendl_fd("\t2. Julia:", 1);
		ft_putendl_fd("\t\t0.285  0", 1);
		ft_putendl_fd("\t\t0.285  0.01", 1);
		ft_putendl_fd("\t\t0.45  0.1428", 1);
		exit(1);
	}
}

void	message_j(void)
{
	ft_putendl_fd("Julia:", 1);
	ft_putendl_fd("\t0.285  0", 1);
	ft_putendl_fd("\t0.285  0.01", 1);
	ft_putendl_fd("\t0.45  0.1428", 1);
	exit(1);
}
