/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 00:51:53 by drwuu             #+#    #+#             */
/*   Updated: 2021/03/15 11:39:59 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content, t_type type)
{
	t_list	*new_elem;

	if (!content)
		return (NULL);
	if (!(new_elem = malloc(sizeof(*new_elem))))
		return (NULL);
	new_elem->content = content;
	new_elem->type = type;
	new_elem->next = NULL;
	new_elem->previous = NULL;
	return (new_elem);
}
