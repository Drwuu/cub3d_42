/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_resolution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drwuu <drwuu@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 14:26:34 by lwourms           #+#    #+#             */
/*   Updated: 2021/03/01 02:06:16 by drwuu            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static t_window_size	get_size(const char *line)
{
	t_window_size	window;
	int				i;

	window.width = 0;
	window.height = 0;
	i = 0;
	while (line[i] && !ft_isdigit(line[i]))
		i++;
	while (line[i] && ft_isdigit(line[i]))
		window.width = (window.width * 10) + (line[i++] - '0');
	while (line[i] && !ft_isdigit(line[i]))
		i++;
	while (line[i] && ft_isdigit(line[i]))
		window.height = (window.height * 10) + (line[i++] - '0');
	if (!window.width || !window.height)
		error_manager(20, g_alloc_lst);
	return (window);
}

t_window_size			get_resolution(t_list *lst)
{
	t_window_size	window;
	t_dictionary	*dict;
	t_list			*lst_cp;

	lst_cp = lst;
	window.height = 0;
	window.width = 0;
	while (lst)
	{
		if (lst->type == DICT)
		{
			dict = lst->content;
			if (dict->key == R)
			{
				window = get_size(dict->str);
				return (window);
			}
		}
		lst = lst->next;
	}
	lst = lst_cp;
	return (window);
}