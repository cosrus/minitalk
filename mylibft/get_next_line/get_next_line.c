/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crusu <crusu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 23:21:31 by crusu             #+#    #+#             */
/*   Updated: 2023/03/28 21:08:31 by crusu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

static char	*free_str(char *str, char *out)
{
	char	*new_str;
	size_t	p1;
	size_t	p2;

	p1 = ft_strlen(out);
	p2 = 0;
	new_str = ft_calloc(ft_strlen(str) - p1, sizeof(char));
	if (!new_str)
	{
		free(str);
		return (NULL);
	}
	while (str[p1])
	{
		new_str[p2] = str[p1];
		p1++;
		p2++;
	}
	free(str);
	return (new_str);
}

static char	*make_out(char *str)
{
	char	*out;
	size_t	p;

	p = 0;
	out = ft_calloc(str - ft_strchr(str, '\0'), sizeof(char));
	if (!out)
		return (NULL);
	while (str[p] != '\n' && str[p])
	{
		out[p] = str[p];
		p++;
	}
	if (str[p] == '\n')
		out[p] = str[p];
	return (out);
}

static char	*re_str(char *str)
{
	char	*new_str;
	size_t	p;

	p = 0;
	new_str = ft_calloc(ft_strlen(str) + BUFFER_SIZE, sizeof(char));
	if (!new_str)
		return (NULL);
	while (str[p])
	{
		new_str[p] = str[p];
		p++;
	}
	free(str);
	return (new_str);
}

static char	*str_start(int fd)
{
	char	*str;
	int		r;

	str = ft_calloc(BUFFER_SIZE, sizeof(char));
	r = read(fd, str, BUFFER_SIZE);
	if (!str || r <= 0)
	{
		if (r <= 0)
			free(str);
		return (NULL);
	}
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str[1024];
	char		*out;
	size_t		p;
	int			r;

	p = 0;
	if (BUFFER_SIZE <= 0 || fd < 0 || fd > 1024)
		return (NULL);
	if (!str[fd])
	{
		str[fd] = str_start(fd);
		if (!str[fd])
			return (NULL);
	}
	r = ft_strlen(str[fd]);
	while (!ft_strchr(str[fd], '\0') && r > 0)
	{
		str[fd] = re_str(str[fd]);
		p += r;
		r = read(fd, &str[fd][p], BUFFER_SIZE);
	}
	out = make_out(str[fd]);
	str[fd] = free_str(str[fd], out);
	return (out);
}
