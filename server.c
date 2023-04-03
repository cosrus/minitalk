/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crusu <crusu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 15:54:56 by crusu             #+#    #+#             */
/*   Updated: 2023/04/04 00:57:57 by crusu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_transpid(char n)
{
	static char	pid[8];
	static int	pos;

	if (pos < 8)
		pid[pos] = n;
	pos++;
	if (pos == 8)
		return (ft_atoi(pid));
	else
		return (0);
}

char	add_bit(int bit)
{
	char	res;

	res = 1;
	while (--bit > 0)
		res *= 2;
	return (res);
}

void	ft_decoder(int sig)
{
	static int	let;
	static int	bit;
	static int	clpid;

	bit++;
	if (sig == SIGUSR1)
		let += add_bit(bit);
	if (bit == 8 && clpid)
	{
		if (!clpid)
			clpid = ft_transpid(let);
		else
			write(1, &let, 1);
		let = 0;
		bit = 0;
	}
}

int	main(void)
{
	ft_printf("Server PID = %d\n", getpid());
	signal(SIGUSR1, ft_decoder);
	signal(SIGUSR2, ft_decoder);
	while (1)
	{
	}
}
