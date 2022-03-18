/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 01:50:56 by hharit            #+#    #+#             */
/*   Updated: 2022/03/17 01:55:08 by hharit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	*colors(void)
{
	int	*color;

	color = (int *)malloc(sizeof(int) * 16);
	color[0] = 0x0009012f;
	color[1] = 0x00040449;
	color[2] = 0x00000764;
	color[3] = 0x000c2c8a;
	color[4] = 0x001852b1;
	color[5] = 0x00397dd1;
	color[6] = 0x0086b5e5;
	color[7] = 0x00d3ecf8;
	color[8] = 0x00f1e9bf;
	color[9] = 0x00f8c95f;
	color[10] = 0x00ffaa00;
	color[11] = 0x00cc8000;
	color[12] = 0x00995700;
	color[13] = 0x006a3403;
	color[14] = 0x00421e0f;
	color[15] = 0x0019071a;
	return (color);
}
