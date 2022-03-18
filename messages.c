/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharit <hharit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 02:08:12 by hharit            #+#    #+#             */
/*   Updated: 2022/03/17 01:37:23 by hharit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	message(int argc, char **argv)
{
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
