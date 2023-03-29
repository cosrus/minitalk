/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crusu <crusu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 22:45:36 by crusu             #+#    #+#             */
/*   Updated: 2023/03/28 21:09:27 by crusu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

void	ft_bzero(void *str, size_t n)
{
	char	*nstr;

	nstr = str;
	nstr = (char *)str;
	while (*nstr && n-- > 0)
	{
		*nstr = '\0';
		nstr++;
	}
}
