/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crusu <crusu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 20:52:02 by crusu             #+#    #+#             */
/*   Updated: 2023/03/29 00:38:16 by crusu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

char	*ft_itoh(unsigned long long n)
{
	unsigned long	s;
	char			*str;

	s = ft_usize(n, 16);
	str = ft_calloc(s + 1, sizeof(char));
	if (!str)
		return (NULL);
	if (n == 0)
		str[0] = '0';
	str[s] = '\0';
	s--;
	while (n != 0)
	{
		if (n % 16 > 9)
			str[s] = (n % 16) + ('a' - 10);
		else
			str[s] = (n % 16) + '0';
		s--;
		n /= 16;
	}
	return (str);
}
