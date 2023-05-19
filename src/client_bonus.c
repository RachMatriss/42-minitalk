/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramedjra <ramedjra@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 12:41:48 by ramedjra          #+#    #+#             */
/*   Updated: 2023/03/09 10:28:51 by ramedjra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

/*
 * ft_confirm ()
 * function confirm after send message !
 */
void	ft_confirm(int signal)
{
	if (signal == SIGUSR1)
		ft_printf("\033[0;32mQSL!\033[0;32m\n", 1);
	else
		ft_printf("\033[0;32mQSL!\033[0;32m\n", 1);
}

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
			signal(SIGUSR1, ft_confirm);
			signal(SIGUSR2, ft_confirm);
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
