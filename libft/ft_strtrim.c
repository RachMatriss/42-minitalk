/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramedjra <ramedjra@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 16:35:22 by ramedjra          #+#    #+#             */
/*   Updated: 2022/12/21 16:35:22 by ramedjra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_chek_insetchar(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*strrest;

	start = 0;
	while (s1[start] && ft_chek_insetchar(s1[start], set))
		start++;
	end = ft_strlen((char *)s1);
	while (end > start && ft_chek_insetchar(s1[end - 1], set))
		end--;
	strrest = ft_substr(s1, start, end - start);
	return (strrest);
}
