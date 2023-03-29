/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crusu <crusu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 20:54:49 by crusu             #+#    #+#             */
/*   Updated: 2023/03/29 00:49:05 by crusu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	p;
	size_t	i;

	i = 0;
	p = ft_strlen(dest);
	if (p < (n - 1) && n > 0)
	{
		while ((p + i) < (n - 1) && src[i] != '\0')
		{
			dest[p + i] = src[i];
			i++;
		}
		dest[p + i] = '\0';
	}
	else if (p > n)
	{
		i = ft_strlen(src);
		return (n + i);
	}
	return (p + i);
}
