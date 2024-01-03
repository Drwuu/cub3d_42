/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wr_malloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 15:34:17 by lwourms           #+#    #+#             */
/*   Updated: 2021/10/24 13:17:05 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/wr_malloc.h"
#include "../../includes/libft.h"

static t_list	**wrgetter(void)
{
	static t_list	*wrm;

	return (&wrm);
}

void	*wrmalloc(unsigned long size)
{
	char	*buffer;
	t_list	*new_elem;

	buffer = malloc(size);
	if (!buffer)
	{
		wrdestroy();
		return (NULL);
	}
	new_elem = malloc(sizeof(t_list));
	if (!new_elem)
	{
		free(buffer);
		wrdestroy();
		return (NULL);
	}
	new_elem->content = buffer;
	new_elem->next = NULL;
	ft_lstadd_back(wrgetter(), new_elem);
	return (buffer);
}

static int	wr_free_process(void *to_free, t_list **wrstart)
{
	t_list	*current;
	t_list	*next;
	t_list	*prev;

	prev = NULL;
	current = *wrstart;
	while (current)
	{
		next = current->next;
		if (current->content == to_free)
		{
			free(to_free);
			to_free = NULL;
			free(current);
			current = NULL;
			if (prev)
				prev->next = next;
			else
				*wrstart = next;
			return (1);
		}
		prev = current;
		current = current->next;
	}
	return (0);
}

int	wrfree(void *to_free)
{
	t_list	**wrstart;

	wrstart = wrgetter();
	if (wr_free_process(to_free, wrstart))
		return (1);
	return (0);
}

void	wrdestroy(void)
{
	t_list	*current;
	t_list	*next;
	t_list	**wrstart;

	wrstart = wrgetter();
	current = *wrstart;
	while (current)
	{
		next = current->next;
		free(current->content);
		free(current);
		current = next;
	}
	*wrstart = NULL;
}
