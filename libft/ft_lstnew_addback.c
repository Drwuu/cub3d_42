/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_addback.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drwuu <drwuu@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 00:51:53 by drwuu             #+#    #+#             */
/*   Updated: 2021/03/11 01:05:55 by drwuu            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew_addback(t_list **alst, void *content)
{
	t_list	*new;
	t_list	*last;

	if (!(new = malloc(sizeof(*new))))
		return (NULL);
	new->content = content;
	new->next = NULL;
	new->previous = NULL;
	if (*alst)
	{
		last = ft_lstlast(*alst);
		last->next = new;
		new->previous = last;
	}
	else
		*alst = new;
	return (new);
}
