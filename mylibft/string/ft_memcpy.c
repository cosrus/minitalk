/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crusu <crusu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 18:45:53 by crusu             #+#    #+#             */
/*   Updated: 2023/03/29 00:46:44 by crusu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)

{
	char		*tdest;
	const char	*tsrc;

	tdest = (char *)dest;
	tsrc = (const char *)src;
	while (n-- > 0)
	{
		*tdest = *tsrc;
		tdest++;
		tsrc++;
	}
	return (dest);
}
