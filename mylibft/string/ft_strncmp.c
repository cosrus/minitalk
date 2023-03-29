/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crusu <crusu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 21:00:54 by crusu             #+#    #+#             */
/*   Updated: 2023/03/28 21:11:52 by crusu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int				res;

	while (n-- > 0)
	{
		res = s1 - s2;
		if (res != 0)
			return (res);
		s1++;
		s2++;
	}
	return (0);
}
