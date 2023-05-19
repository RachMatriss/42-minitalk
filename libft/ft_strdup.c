/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramedjra <ramedjra@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 18:41:38 by ramedjra          #+#    #+#             */
/*   Updated: 2023/01/02 18:41:38 by ramedjra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*dest;

	len = ft_strlen((char *)s) + 1;
	dest = (char *)malloc(sizeof(*s) * len);
	if (!dest)
		return (NULL);
	ft_memcpy(dest, s, len);
	return (dest);
}
