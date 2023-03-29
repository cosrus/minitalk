/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crusu <crusu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 22:38:36 by crusu             #+#    #+#             */
/*   Updated: 2023/03/29 00:46:53 by crusu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*tdest;
	const char	*tsrc;
	size_t		i;

	tdest = (char *)dest;
	tsrc = (const char *)src;
	i = 0;
	if (tdest < tsrc)
	{
		while (i < n)
		{
			tdest[i] = tsrc[i];
			i++;
		}
	}
	else
	{
		while (n-- > 0)
			tdest[n] = tsrc[n];
	}
	return (dest);
}
