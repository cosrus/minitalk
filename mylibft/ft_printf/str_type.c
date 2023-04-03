/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crusu <crusu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 20:58:16 by crusu             #+#    #+#             */
/*   Updated: 2023/04/02 22:57:36 by crusu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

static char	*null_str(int *prec)
{
	char	*str;

	str = "(null)";
	if (*prec > -1 && *prec < 6)
		*prec = 0;
	return (str);
}

static int	type_s(va_list arg, t_flag flag)
{
	char	*str;
	int		w;
	int		len;

	w = 0;
	str = va_arg(arg, char *);
	if (!str)
		str = null_str(&flag.prec);
	len = ft_strlen(str);
	if (len > flag.prec && flag.prec != -1)
		len = flag.prec;
	while (flag.min_w > 0 || len > 0)
	{
		if ((flag.dash == 1 || len >= flag.min_w) && len > 0)
		{
			w += write (1, str++, 1);
			len--;
		}
		else
			w += write (1, " ", 1);
		flag.min_w--;
	}
	return (w);
}

static int	type_c(va_list arg, t_flag flag)
{
	int	c;
	int	w;
	int	len;

	w = 0;
	len = 1;
	c = va_arg(arg, int);
	while (flag.min_w > 0 || w == 0)
	{
		if ((flag.dash == 1 || flag.min_w <= len) && len > 0)
		{	
			w += write (1, &c, 1);
			len--;
		}
		else
			w += write (1, " ", 1);
		flag.min_w -= 1;
	}
	return (w);
}

int	str_type(va_list arg, char type, t_flag flag)
{
	int	w;

	if (type == 'c')
		w = type_c(arg, flag);
	else
		w = type_s(arg, flag);
	return (w);
}
