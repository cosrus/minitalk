/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crusu <crusu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 17:12:13 by crusu             #+#    #+#             */
/*   Updated: 2023/03/28 21:10:59 by crusu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	p;
	size_t	bp;

	p = 0;
	bp = 0;
	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	while (s1[p])
	{
		str[bp] = s1[p];
		bp++;
		p++;
	}
	p = 0;
	while (s2[p])
	{
		str[bp] = s2[p];
		bp++;
		p++;
	}
	str[bp] = '\0';
	return (str);
}
