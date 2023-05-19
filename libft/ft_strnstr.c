/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramedjra <ramedjra@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 16:35:01 by ramedjra          #+#    #+#             */
/*   Updated: 2022/12/21 16:35:01 by ramedjra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t blen)
{
	size_t	i;
	size_t	j;

	if (ft_strlen((char *) little) < 1)
		return ((char *)big);
	i = 0;
	while (big[i] && i < blen)
	{
		j = 0;
		while (little[j] == big[i + j] && i + j < blen)
		{
			if (little[j] == big[i + j])
			{	
				if (little[j + 1] == '\0')
					return ((char *)&big[i]);
			}
			else
				break ;
			j++;
		}
		i++;
	}
	return (0);
}
