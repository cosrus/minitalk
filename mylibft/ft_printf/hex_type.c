/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crusu <crusu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:55:11 by crusu             #+#    #+#             */
/*   Updated: 2023/03/29 00:45:07 by crusu            ###   ########.fr       */
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

static char	*sign_ox(char *str, char type, int htag)
{
	char	*n_str;
	int		len;

	len = 0;
	if (type == 'X')
	{
		while (n_str[len])
		{
			n_str[len] = ft_toupper(n_str[len]);
			len++;
		}
	}
	len = ft_strlen(str) + 2;
	if (htag == 0 || len == 2)
		return (str);
	n_str = ft_calloc(len + 1, sizeof(char));
	while (len >= 2)
	{
		n_str[len] = str[len - 2];
		len--;
	}
	n_str[len--] = type;
	n_str[len] = '0';
	free(str);
	return (n_str);
}	

static int	type_x(char *str, t_flag flag)
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

static int	type_p(char *str, t_flag flag)
{
	int	len;
	int	w;

	w = 0;
	if (str[2] == '0')
		str = "(nil)";
	len = ft_strlen(str);
	while (flag.min_w > 0 || len > 0)
	{
		if ((flag.dash == 1 || len >= flag.min_w) && len > 0)
		{
			w += write(1, str++, 1);
			len--;
		}
		else
			w += write(1, " ", 1);
		flag.min_w--;
	}
	return (w);
}

int	hex_type(char *str, char type, t_flag flag)
{
	int	w;

	if (type == 'p')
	{
		str = sign_ox(str, 'x', 1);
		w = type_p(str, flag);
	}
	else
	{	
		if (*str == '0')
		{
			flag.htag = 0;
			if (flag.prec == 0)
				*str = '\0';
		}
		str = re_str(str, flag.prec);
		str = sign_ox(str, type, flag.htag);
		w = type_x(str, flag);
	}
	free(str);
	return (w);
}
