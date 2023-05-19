/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramedjra <ramedjra@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 16:31:35 by ramedjra          #+#    #+#             */
/*   Updated: 2022/12/21 16:31:35 by ramedjra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(const int nbr)
{
	unsigned int	len;
	unsigned int	nb;

	len = 0;
	if (nbr <= 0)
	{
		nb = -(int)nbr;
		len++;
	}
	else
		nb = (int)nbr;
	while (nb / 10 > 0)
	{
		nb = nb / 10;
		len++;
	}
	if (nb > 0 && nb < 10)
		len++;
	return (len);
}

char	*ft_itoa(int n)
{
	unsigned int	nbr;
	unsigned int	len;
	char			*alpha;

	len = ft_len(n);
	if (n < 0)
		nbr = -n;
	else
		nbr = n;
	alpha = ft_calloc(len + 1, sizeof(char));
	if (!alpha)
		return (NULL);
	while (len > 0)
	{
		if (len == 1 && n < 0)
			alpha[len - 1] = '-';
		else
			alpha[len - 1] = nbr % 10 + '0' ;
		nbr = nbr / 10;
		len--;
	}
	return (alpha);
}
