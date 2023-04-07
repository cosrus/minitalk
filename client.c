/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crusu <crusu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 17:51:17 by crusu             #+#    #+#             */
/*   Updated: 2023/04/05 19:04:43 by crusu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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
		usleep(30);
		bit++;
	}
}

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

void	ft_getping(int sig)
{
	static int	status;

	if (sig == SIGUSR1)
	{
		write(1, "Sending message\n", 17);
		status = sig;
	}
	else if (sig == SIGUSR2)
	{
		status = sig;
		write(1, "Message received by server\n", 28);
	}
	else
	{
		if (status == SIGUSR1)
			ft_printf("ERROR: Something went wrong\n")
		if (!status)
			ft_printf("ERROR: Unable to comunicate with server\n");
	}
}

int	ft_errno(int argc, char **argv)
{
	char	*str;

	if (argc != 3)
	{	
		ft_printf("ERROR: Ivalid number of arguments\n");
		return (1);
	}
	str = argv[1];
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

	signal(SIGUSR1, ft_getping);
	signal(SIGUSR2, ft_getping);
	if (ft_errno(argc, argv))
		return (0);
	pid = ft_atoi(argv[1]);
	ft_pidsender(ft_itoa(getpid()), pid);
	str = argv[2];
	while (*str)
	{
		ft_sender(*str, pid);
		str++;
	}
	ft_sender(0, pid);
	ft_getping(0);
	return (0);
}
