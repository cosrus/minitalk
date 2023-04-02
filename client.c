/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crusu <crusu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 17:51:17 by crusu             #+#    #+#             */
/*   Updated: 2023/04/01 21:29:24 by crusu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_sender(char let, int pid)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if (let % 2)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(50);
		bit++;
		let /= 2;
	}
}

int	ft_errno(char *str)
{
	while (*str)
	{
		if (ft_isdigit(*str))
			str++;
		else
		{
			ft_printf("ERROR: Invalid PID\n");
			return (1);
		}
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	char	*str;
	int		pid;

	if (argc != 3)
	{	
		ft_printf("ERROR: Ivalid number of arguments\n");
		return (0);
	}
	str = argv[1];
	if (ft_errno(str))
		return (0);
	pid = ft_atoi(str);
	str = argv[2];
	while (*str)
	{
		ft_sender(*str, pid);
		str++;
	}
	return (0);
}
