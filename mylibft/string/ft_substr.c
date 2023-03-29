/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crusu <crusu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 19:28:01 by crusu             #+#    #+#             */
/*   Updated: 2023/03/29 00:57:04 by crusu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{	
	char	*str;
	size_t	p;

	p = ft_strlen(s);
	if (p < start)
		len = 0;
	p = 0;
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	while (s[p + start] && p < len)
	{
		str[p] = s[p + start];
		p++;
	}
	str[p] = '\0';
	return (str);
}
