/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crusu <crusu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 18:32:07 by crusu             #+#    #+#             */
/*   Updated: 2023/03/28 21:12:14 by crusu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

static int	ft_ccomp(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static size_t	ft_cs(char const *s1, char const *set)
{
	size_t	c;

	c = 0;
	while (ft_ccomp(s1[c], set) == 1)
		c++;
	return (c);
}

static size_t	ft_ce(char const *s1, char const *set)
{
	size_t	c;

	c = ft_strlen(s1) - 1;
	while (ft_ccomp(s1[c], set) == 1)
		c--;
	return (c);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	i;
	size_t	k;
	size_t	j;

	j = 0;
	i = ft_cs(s1, set);
	k = ft_strlen(s1) - ft_ce(s1, set) - 1;
	if (i == ft_strlen(s1))
	{
		str = ft_calloc(1, 1);
		return (str);
	}
	else
		str = ft_calloc((ft_strlen(s1) - k - i + 1) * sizeof(char), 1);
	if (!str)
		return (NULL);
	while (s1[i + k] != '\0')
	{
		str[j] = s1[i];
		i++;
		j++;
	}
	return (str);
}
