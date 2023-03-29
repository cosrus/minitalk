/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crusu <crusu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 22:32:13 by crusu             #+#    #+#             */
/*   Updated: 2023/03/29 00:50:37 by crusu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	size_t	p;

	p = 0;
	if (!s)
		return (NULL);
	p = ft_strlen(s);
	str = malloc(sizeof(char) * (p + 1));
	if (!str)
		return (NULL);
	p = 0;
	while (s[p])
	{
		str[p] = (*f)(p, s[p]);
		p++;
	}
	str[p] = '\0';
	return (str);
}
