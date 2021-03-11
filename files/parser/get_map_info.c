/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drwuu <drwuu@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 11:11:00 by lwourms           #+#    #+#             */
/*   Updated: 2021/03/11 22:40:29 by drwuu            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	check_maplines(char *previous, char *current, char *next, \
t_cub3d *cub)
{
	int i;

	i = -1;
	while (current[++i])
	{
		if (!ft_char_ischars(current[i], " 1"))
		{
			if (is_valid_next(current, i))
			{
				if (previous)
					if (!is_valid_next(previous, i))
						return (0);
				if (next)
					if (!is_valid_next(next, i))
						return (0);
			}
			else
				return (0);
		}
		//if (ft_char_ischars(current[i], "NSEO"))
		//	cub->player.
	}
	return (1);
}

void		get_map_info(t_cub3d *cub, t_list *mapline)
{
	char	*previous;
	char	*current;
	char	*next;

	while (mapline)
	{
		previous = ((t_dictionary *)mapline->previous->content)->value;
		next = ((t_dictionary *)mapline->next->content)->value;
		current = ((t_dictionary *)mapline->content)->value;
		if (!check_maplines(previous, current, next, cub))
		{
			cub->map.map_lines = ft_lstfirst(cub->map.map_lines);
			error_manager(51, cub, NULL);
		}
		if (((t_dictionary *)mapline->content)->key == 0)
			break ;
		mapline = mapline->next;
	}
}