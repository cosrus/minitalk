/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crusu <crusu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 19:58:47 by crusu             #+#    #+#             */
/*   Updated: 2023/03/29 00:46:29 by crusu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)

{
	unsigned char	*cs1;
	unsigned char	*cs2;
	int				res;

	cs1 = (unsigned char *)s1;
	cs2 = (unsigned char *)s2;
	while (n-- > 0)
	{
		res = *cs1 - *cs2;
		if (res != 0)
			return (res);
		cs1++;
		cs2++;
	}
	return (0);
}
