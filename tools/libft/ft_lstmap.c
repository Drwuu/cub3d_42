/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 00:51:53 by drwuu             #+#    #+#             */
/*   Updated: 2021/03/15 11:52:24 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*first_elem;

	if (!lst)
		return (NULL);
	if (!(new_list = ft_lstnew(f(lst->content), lst->type)))
		return (NULL);
	first_elem = new_list;
	lst->previous = lst;
	lst = lst->next;
	while (lst)
	{
		if (!(new_list->next = ft_lstnew(f(lst->content), lst->type)))
		{
			ft_lstclear(&first_elem, del);
			return (NULL);
		}
		lst->previous = lst;
		lst = lst->next;
		new_list->previous = new_list;
		new_list = new_list->next;
	}
	new_list->next = NULL;
	return (first_elem);
}
