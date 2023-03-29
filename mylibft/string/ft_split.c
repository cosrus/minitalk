/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crusu <crusu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 20:50:17 by crusu             #+#    #+#             */
/*   Updated: 2023/03/28 21:10:21 by crusu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

static char	*copy(char *s, char *str, char c)
{
	size_t	p;

	p = 0;
	while (*s && *s != c)
	{
		str[p] = *s;
		p++;
		s++;
	}
	str[p] = '\0';
	return (s);
}

static size_t	array_gen(char const *s, char c)
{
	size_t	p;

	p = 0;
	while (s[p] && s[p] != c)
		p++;
	return (p);
}

static size_t	n_point(char const *s, char c)
{
	size_t	p;
	size_t	count;
	size_t	l;

	p = 0;
	count = 0;
	l = 0;
	while (s[p])
	{
		if (s[p] != c)
		{
			if (l == 0)
			{
				count++;
				l = 1;
			}
			p++;
		}
		else
		{
			p++;
			l = 0;
		}
	}
	return (count);
}

static void	freeall(size_t p, char **ptrstr)
{
	while (p > 0)
	{
		free((char *) ptrstr[p]);
		p--;
	}
	free((char *)ptrstr[p]);
	free((char **)ptrstr);
}

char	**ft_split(char const *s, char c)
{
	char	**ptrstr;
	char	*str;
	size_t	p;

	p = 0;
	str = (char *)s;
	ptrstr = malloc(sizeof(char *) * (n_point(s, c) + 1));
	if (!ptrstr)
		return (NULL);
	while (p < n_point(s, c))
	{
		while (*str == c)
			str++;
		ptrstr[p] = malloc(sizeof(char) * (array_gen(str, c) + 1));
		if (!ptrstr[p])
		{
			freeall(p, ptrstr);
			return (NULL);
		}
		str = copy(str, ptrstr[p], c);
		p++;
	}
	ptrstr[p] = NULL;
	return (ptrstr);
}
