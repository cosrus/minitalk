/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crusu <crusu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 23:50:52 by crusu             #+#    #+#             */
/*   Updated: 2023/03/28 23:03:41 by crusu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

static char	*re_str(char *str, int prec)
{
	char	*n_str;
	int		len;

	len = ft_strlen(str);
	if (str[0] == '-')
		prec++;
	if (prec > len)
	{
		n_str = ft_calloc(prec + 1, sizeof(char));
		if (!str)
			return (NULL);
		while (prec >= 0)
		{
			if (len >= 0 && (str[len] != '-' || prec == 0))
				n_str[prec--] = str[len--];
			else
				n_str[prec--] = '0';
		}
		free(str);
		return (n_str);
	}
	return (str);
}

static char	*sign_ps(char *str, t_flag flag)
{
	char	*n_str;
	size_t	len;

	len = ft_strlen(str) + flag.space + flag.plus;
	if (len == ft_strlen(str) || *str == '-')
		return (str);
	n_str = ft_calloc(len + 1, sizeof(char));
	while (len >= 1)
	{
		n_str[len] = str[len - 1];
		len--;
	}	
	if (flag.space == 1)
		n_str[0] = ' ';
	else
		n_str[0] = '+';
	free(str);
	return (n_str);
}

static int	type_di(char *str, t_flag flag)
{
	int	len;
	int	w;

	w = 0;
	if (flag.zero == 1 && (*str == '-' || *str == ' ' || *str == '+'))
		w += write(1, str++, 1);
	len = ft_strlen(str);
	flag.min_w -= w;
	while (flag.min_w > 0 || len > 0)
	{
		if ((flag.dash == 1 || len >= flag.min_w) && len > 0)
		{
			w += write(1, str++, 1);
			len--;
		}
		else
		{
			if (flag.zero == 1)
				w += write(1, "0", 1);
			else
				w += write(1, " ", 1);
		}
		flag.min_w--;
	}
	return (w);
}

static int	type_u(char *str, t_flag flag)
{
	int	len;
	int	w;

	w = 0;
	len = ft_strlen(str);
	while (flag.min_w > 0 || len > 0)
	{
		if ((flag.dash == 1 || len >= flag.min_w) && len > 0)
		{
			w += write(1, str++, 1);
			len--;
		}
		else
		{
			if (flag.zero == 1)
				w += write(1, "0", 1);
			else
				w += write(1, " ", 1);
		}
		flag.min_w--;
	}
	return (w);
}

int	int_type(char *str, char type, t_flag flag)
{
	int	w;

	if (flag.prec == 0 && *str == '0')
		*str = '\0';
	str = re_str(str, flag.prec);
	if (type == 'u')
		w = type_u(str, flag);
	else
	{
		str = sign_ps(str, flag);
		w = type_di(str, flag);
	}
	free(str);
	return (w);
}
