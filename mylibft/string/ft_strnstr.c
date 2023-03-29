/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crusu <crusu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 22:04:05 by crusu             #+#    #+#             */
/*   Updated: 2023/03/29 00:54:52 by crusu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	p;

	p = 0;
	i = 0;
	if (!little)
		return ((char *)big);
	while (i < len && big[i] != '\0')
	{
		if (big[i] == little[p])
		{
			while (i < len && big[i] == little[p++])
				i++;
			i -= p;
			if (!little[p] && len >= p + i)
				return ((char *)&big[i]);
			else
				p = 0;
		}
		i++;
	}
	return (0);
}
