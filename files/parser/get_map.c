/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drwuu <drwuu@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 11:11:00 by lwourms           #+#    #+#             */
/*   Updated: 2021/03/11 03:25:41 by drwuu            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static t_list	*get_valid_map(t_list *maplines)
{
	char			*str;
	int				i;

	i = 0;
	while (maplines)
	{
		str = ((t_dictionary *)maplines->content)->value;
		dprintf(1, "str = %s\n", str);
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
	dprintf(1, "first str = %s\n", ((t_dictionary *)maplines->content)->value);
	return (maplines);
}

static void		get_map_error(t_list *maplines, t_cub3d *cub)
{
	char			*str;

	while (maplines)
	{
		str = ((t_dictionary *)maplines->content)->value;
		if (is_valid_mapline(str) || *str == '\0')
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

int				is_valid_mapline(char *line)
{
	int i;

	i = 0;
	if (!ft_ischar(line, " 102NSOE"))
		return (0);
	return (1);
}

void			get_map(t_cub3d *cub)
{
	cub->map.map_lines = get_end_of_map(cub->map.map_lines);
	get_map_error(cub->map.map_lines, cub);
	cub->map.map_lines = get_valid_map(cub->map.map_lines);
	cub->map.map_lines = ft_lstfirst(cub->map.map_lines);
}