/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crusu <crusu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 12:14:42 by crusu             #+#    #+#             */
/*   Updated: 2023/03/29 00:47:02 by crusu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	char	*tstr;

	tstr = (char *)str;
	while (n-- > 0)
	{
		*tstr = c;
		tstr++;
	}
	return (str);
}
