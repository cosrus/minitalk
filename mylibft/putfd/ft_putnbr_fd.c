/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crusu <crusu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 20:26:12 by crusu             #+#    #+#             */
/*   Updated: 2023/03/28 21:09:07 by crusu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

static void	ft_prev(char *num, int i, int fd)
{
	while (i >= 0)
	{
		write(fd, &num[i], 1);
		i--;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	char	num[10];
	int		i;

	i = 0;
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			write(fd, "-", 1);
			n = n * -1;
		}
		else if (n == 0)
			write(fd, "0", 1);
		while (n > 0)
		{
			num[i] = n % 10 + 48;
			i++;
			n = n / 10;
		}
		ft_prev(num, i - 1, fd);
	}
}
