/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crusu <crusu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 23:48:19 by crusu             #+#    #+#             */
/*   Updated: 2023/03/28 20:59:41 by crusu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

static int	arg_proc_p2(va_list arg, char type, t_flag flag)
{
	char	*str;
	int		w;

	if (type == 'u')
	{
		str = ft_ltoa(va_arg(arg, unsigned int));
		w = int_type(str, type, flag);
	}
	else if (type == 'x' || type == 'X')
	{
		str = ft_itoh(va_arg(arg, unsigned int));
		w = hex_type(str, type, flag);
	}
	else if (type == 'p')
	{
		str = ft_itoh(va_arg(arg, unsigned long long));
		w = hex_type(str, type, flag);
	}
	return (w);
}

static int	arg_proc(va_list arg, char type, t_flag flag)
{
	char	*str;
	int		w;

	if (type == '%')
		w = write(1, "%", 1);
	else if (type == 'c' || type == 's')
		w = str_type(arg, type, flag);
	else if (type == 'd' || type == 'i')
	{
		str = ft_ltoa(va_arg(arg, int));
		w = int_type(str, type, flag);
	}
	else
		w = arg_proc_p2(arg, type, flag);
	return (w);
}

int	ft_printf(const char *str, ...)
{
	t_flag	flag;
	va_list	arg;
	int		p;
	int		w;

	p = 0;
	w = 0;
	va_start(arg, str);
	while (str[p])
	{
		if (str[p] == '%')
		{
			p++;
			flag = set_flag(str, &p);
			w += arg_proc(arg, str[p], flag);
			p++;
		}
		else
		{
			w += write(1, &str[p], 1);
			p++;
		}
	}
	va_end(arg);
	return (w);
}
