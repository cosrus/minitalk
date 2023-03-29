/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crusu <crusu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 23:21:23 by crusu             #+#    #+#             */
/*   Updated: 2023/03/29 00:55:12 by crusu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	p;

	p = ft_strlen(str);
	while (str[--p] != c)
	{
		if (p == 0)
			return (NULL);
	}
	return ((char *)&str[p]);
}
