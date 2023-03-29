/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crusu <crusu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:37:35 by crusu             #+#    #+#             */
/*   Updated: 2023/03/28 23:04:41 by crusu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char		*str;
	long long	i;

	i = nmemb * size;
	if (i == 0)
		return (NULL);
	str = malloc(i);
	if (!str)
		return (NULL);
	while (--i >= 0)
		str[i] = '\0';
	return (str);
}
