/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crusu <crusu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 17:40:53 by crusu             #+#    #+#             */
/*   Updated: 2023/03/29 00:46:19 by crusu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

void	*ft_memchr(const void *str, int c, size_t n)

{
	char	*nstr;

	nstr = (char *)str;
	while (n-- > 0 && *nstr)
	{
		if (*nstr == c)
			return (nstr);
		nstr++;
	}
	return (NULL);
}
