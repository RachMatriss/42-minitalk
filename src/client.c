/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramedjra <ramedjra@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 09:23:29 by ramedjra          #+#    #+#             */
/*   Updated: 2023/03/09 10:28:43 by ramedjra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

/*
 *ft_sendbits() function ...
 * this func send message to pid in bits
 */
void	ft_sendbits(int pid, char i)
{
	int	bits;

	bits = 0;
	while (bits < 8)
	{
		if ((i & (0x01 << bits)) != '\0')
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		sleep(0.01);
		bits++;
	}
}

int	main(int argc, char *argv[])
{
	int	pid;
	int	i;

	i = 0;
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		while (argv[2][i] != '\0')
		{
			ft_sendbits(pid, argv[2][i]);
			i++;
		}
		ft_sendbits(pid, '\n');
	}
	else
	{
		ft_printf("\033[91mError: wrong format.\033[0m\n");
		ft_printf("\033[33mTry: ./client <PID> <MESSAGE>\033[0m\n");
		return (1);
	}
	return (0);
}
