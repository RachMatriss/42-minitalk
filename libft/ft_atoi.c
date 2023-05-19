/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramedjra <ramedjra@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 16:29:17 by ramedjra          #+#    #+#             */
/*   Updated: 2022/12/21 16:29:17 by ramedjra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		i;
	int		j;
	long	rest;

	i = 0;
	j = 1;
	rest = 0;
	while ((str[i] >= '\t' && str[i] <= '\r') || (str[i] == ' '))
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			j = -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		rest = rest * 10 + str[i] - '0';
		i++;
	}
	return ((int)rest * j);
}
