/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramedjra <ramedjra@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 10:49:28 by ramedjra          #+#    #+#             */
/*   Updated: 2022/12/29 10:49:28 by ramedjra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*list1;
	t_list	*list2;
	t_list	*list3;

	if (!lst || !f)
		return (NULL);
	list1 = lst;
	list2 = ft_lstnew(f(lst->content));
	if (!list2)
		return (NULL);
	while (list1->next)
	{
		list3 = ft_lstnew(f(list1->next->content));
		if (!list3)
		{
			ft_lstclear(&list2, del);
			return (NULL);
		}
		ft_lstadd_back(&list2, list3);
		list1 = list1->next;
	}
	return (list2);
}
