/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crusu <crusu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 21:39:23 by crusu             #+#    #+#             */
/*   Updated: 2023/03/28 21:09:17 by crusu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

char	*ft_itoa(int n)
{
	char	*str;
	size_t	nc;
	size_t	s;

	nc = (long int)n;
	s = ft_size(nc, 10);
	str = malloc(sizeof(char) * (s + 1));
	if (!str)
		return (NULL);
	if (n == 0)
		str[0] = '0';
	if (n < 0)
	{
		str[0] = '-';
		nc = nc * -1;
	}
	str[s] = '\0';
	s--;
	while (nc != 0)
	{
		str[s] = (nc % 10) + 48;
		s--;
		nc = nc / 10;
	}
	return (str);
}
