/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramedjra <ramedjra@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 16:33:08 by ramedjra          #+#    #+#             */
/*   Updated: 2022/12/21 16:33:08 by ramedjra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long long int	t;

	t = n;
	if (t < 0)
	{
		t = (t * -1);
		ft_putchar_fd('-', fd);
	}
	if (t > 9)
	{
		ft_putnbr_fd(t / 10, fd);
		ft_putchar_fd(t % 10 + '0', fd);
	}
	else
		ft_putchar_fd(t + '0', fd);
}
