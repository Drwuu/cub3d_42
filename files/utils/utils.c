/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drwuu <drwuu@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 21:02:26 by lwourms           #+#    #+#             */
/*   Updated: 2021/03/01 00:54:18 by drwuu            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

const char 	*get_enum_name(t_map_value map_val)
{
    const char	*enum_name[9];
	
	enum_name[0] = NULL;
	enum_name[1] = "R";
	enum_name[2] = "NO";
	enum_name[3] = "SO";
	enum_name[4] = "WE";
	enum_name[5] = "EA";
	enum_name[6] = "S";
	enum_name[7] = "F";
	enum_name[8] = "C";
    return (enum_name[map_val]);
}

t_type 		get_type(t_type type)
{
	t_type	a_type[6];
	
	a_type[0] = CHAR;
	a_type[1] = CHARS;
	a_type[2] = INT;
	a_type[3] = LONG;
	a_type[4] = LONG_LONG;
	a_type[5] = DICT;
    return (a_type[type]);
}

void		check_allocation(void *alloc, t_list *lst_to_free)
{
	if (!alloc)
		error_manager(-1, lst_to_free);
}

void		alloc_to_lst(void **content, t_type type, int alloc_size, int size)
{
	t_list *element;

	if (size > 0)
	{
		*content = ft_calloc(alloc_size, size);
		ft_bzero(*content, size);
	}
	if (!*content)
		error_manager(-1, NULL);
	element = ft_lstnew(*content, type);
	check_allocation(element, g_alloc_lst);
	ft_lstadd_back(&g_alloc_lst, element);
}
