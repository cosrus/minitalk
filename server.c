/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crusu <crusu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 15:54:56 by crusu             #+#    #+#             */
/*   Updated: 2023/04/01 21:22:44 by crusu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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
	static char	let;
	static int	bit;

	bit++;
	if (sig == SIGUSR1)
		let += add_bit(bit);
	if (bit == 8)
	{
		write(1, &let, 1);
		let = 0;
		bit = 0;
	}
}

int	main(void)
{
	ft_printf("Server PID = %d\n", getpid());
	while (1)
	{
		signal(SIGUSR1, ft_decoder);
		signal(SIGUSR2, ft_decoder);
		pause();
	}
}
