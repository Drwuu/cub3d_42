/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_addback.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 00:51:53 by drwuu             #+#    #+#             */
/*   Updated: 2021/01/11 12:02:26 by lwourms          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew_addback(t_list **alst, void *content)
{
	t_list	*new;

	if (!(new = malloc(sizeof(*new))))
		return (NULL);
	new->content = content;
	new->next = NULL;
	if (*alst)
		ft_lstlast(*alst)->next = new;
	else
		*alst = new;
	return (new);
}
