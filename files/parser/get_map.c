/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 11:11:00 by lwourms           #+#    #+#             */
/*   Updated: 2021/03/12 20:43:09 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static t_list	*get_valid_map_block(t_list *maplines)
{
	char			*str;
	int				i;

	i = 0;
	while (maplines)
	{
		str = ((t_dictionary *)maplines->content)->value;
		if (is_valid_mapline(str))
		{
			((t_dictionary *)maplines->content)->key = i++;
			if (maplines->previous)
				maplines = maplines->previous;
			else
				break ;
		}
		else
		{			
			maplines = maplines->next;
			break ;
		}
	}
	return (maplines);
}

static void		get_map_error(t_list *maplines, t_cub3d *cub)
{
	char	*str;
	int		i;

	while (maplines)
	{
		str = ((t_dictionary *)maplines->content)->value;
		if (is_valid_mapline(str) || *str == '\0') // *str == \0 ??
		{
			if (maplines->previous)
				maplines = maplines->previous;
			else
				break ;
		}
		else
		{
			cub->map.map_lines = ft_lstfirst(maplines);
			error_manager(50, cub, NULL);
		}
	}
}

static t_list	*get_end_of_map(t_list *maplines)
{
	t_list			*last;
	char			*str;

	last = ft_lstlast(maplines);
	while (last)
	{
		str = ((t_dictionary *)last->content)->value;
		if (!*str)
			last = last->previous;
		else
			break ;
	}
	return (last);
}

void			get_map(t_cub3d *cub)
{
	cub->map.map_lines = get_end_of_map(cub->map.map_lines);
	get_map_error(cub->map.map_lines, cub);
	cub->map.map_lines = get_valid_map_block(cub->map.map_lines);
	get_map_info(cub, cub->map.map_lines);
	dprintf(1, "map size = x%d y%d\n", cub->map.size.x, cub->map.size.y);

	cub->map.map_lines = ft_lstfirst(cub->map.map_lines);
}