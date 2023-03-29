/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crusu <crusu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 20:27:03 by crusu             #+#    #+#             */
/*   Updated: 2023/03/29 00:45:27 by crusu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

char	*ft_ltoa(long n)
{
	char	*str;
	long	s;

	s = ft_size(n, 10);
	str = ft_calloc(s + 1, sizeof(char));
	if (!str)
		return (NULL);
	if (n == 0)
		str[0] = '0';
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	str[s] = '\0';
	s--;
	while (n != 0)
	{
		str[s] = (n % 10) + '0';
		n /= 10;
		s--;
	}
	return (str);
}
