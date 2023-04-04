/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crusu <crusu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 17:51:17 by crusu             #+#    #+#             */
/*   Updated: 2023/04/04 01:25:09 by crusu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_pidsender(char *str, int pid)
{
	int	pos;

	pos = 0;
	while (pos < 8)
	{
		if (*str)
		{
			ft_sender(*str, pid);
			str++;
		}
		else
			ft_sender(0, pid);
		pos++;
	}
}

void	ft_sender(char let, int pid)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if (let >> bit & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(1);
		bit++;
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
	ft_pidsender(str, pid);
	str = argv[2];
	if (sleep(10))
	{
		ft_printf("ERROR: Unable to reach server\nTried to send %s to %d", str, pid);
		return (0);
	}
	while (*str)
	{
		ft_sender(*str, pid);
		str++;
	}
	return (0);
}
