/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_flag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crusu <crusu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 19:51:58 by crusu             #+#    #+#             */
/*   Updated: 2023/03/28 20:59:45 by crusu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

static t_flag	flag_init(void)
{
	t_flag	flag;

	flag.htag = 0;
	flag.zero = 0;
	flag.dash = 0;
	flag.space = 0;
	flag.plus = 0;
	flag.min_w = -1;
	flag.prec = -1;
	return (flag);
}

static int	flag_size(const char *str, int *p)
{
	int	tot;

	tot = 0;
	if (str[*p] == '.')
		*p += 1;
	while (str[*p] >= '0' && str[*p] <= '9')
	{
		if (tot > 0)
			tot *= 10;
		tot += str[*p] - '0';
		*p += 1;
	}
	*p -= 1;
	return (tot);
}

static t_flag	flag_man(t_flag flag)
{
	if (flag.plus == 1)
		flag.space = 0;
	if (flag.dash == 1 || flag.prec > -1)
		flag.zero = 0;
	return (flag);
}

t_flag	set_flag(const char *str, int *p)
{
	t_flag	flag;

	flag = flag_init();
	while (str[*p])
	{
		if (str[*p] == '#')
			flag.htag = 1;
		else if (str[*p] == '0')
			flag.zero = 1;
		else if (str[*p] == '-')
			flag.dash = 1;
		else if (str[*p] == ' ')
			flag.space = 1;
		else if (str[*p] == '+')
			flag.plus = 1;
		else if (str[*p] > '0' && str[*p] <= '9')
			flag.min_w = flag_size(str, p);
		else if (str[*p] == '.')
			flag.prec = flag_size(str, p);
		else
			break ;
		*p += 1;
	}
	flag = flag_man(flag);
	return (flag);
}
