/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 22:29:42 by hharit            #+#    #+#             */
/*   Updated: 2022/03/14 02:04:02 by hharit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i ++;
	return (i);
}

int	ft_strcmp(char *s1, char *s2)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	if (!ft_strlen(s1) && !ft_strlen(s2))
		return (0);
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}
