/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crusu <crusu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 23:38:37 by crusu             #+#    #+#             */
/*   Updated: 2023/03/29 00:49:51 by crusu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t	p;

	p = 0;
	if (n > 0)
	{
		while (p < (n - 1) && src[p] != '\0')
		{
			dest[p] = src[p];
			p++;
		}
		dest[p] = '\0';
	}
	p = ft_strlen(src);
	return (p);
}
