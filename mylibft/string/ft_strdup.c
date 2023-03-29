/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crusu <crusu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 22:44:14 by crusu             #+#    #+#             */
/*   Updated: 2023/03/29 00:47:30 by crusu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

char	*ft_strdup(const char *str)
{
	char	*tstr;
	int		len;

	len = ft_strlen(str);
	tstr = malloc(len);
	while (len-- > 0)
		tstr[len] = str[len];
	return (tstr);
}
