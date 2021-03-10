/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drwuu <drwuu@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 18:35:05 by drwuu             #+#    #+#             */
/*   Updated: 2021/03/10 23:40:00 by drwuu            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void free_tex_path(t_cub3d *cub)
{
	int i;

	i = 0;
	while (i < 5)
	{
		if (cub->map.wall[i].texture)
		{
			free(cub->map.wall[i].texture);
			cub->map.wall[i].texture = NULL;
		}
		if (cub->map.enemy.texture)
		{
			free(cub->map.enemy.texture);
			cub->map.enemy.texture = NULL;
		}
		i++;
	}
}

static void free_map_lines(t_list *map_lines)
{
	t_dictionary	*mapline;
	t_list			*save;

	save = map_lines;
	while (map_lines)
	{
		mapline = map_lines->content;
		free(mapline->value);
		map_lines = map_lines->next;
	}
	ft_lstclear(&save, free);
}

void free_ids(t_ids *ids)
{
	int i;

	i = 0;
	while (i < 8)
	{
		if (ids[i].id)
		{
			if (ids[i].line)
			{
				free(ids[i].line);
				ids[i].line = NULL;
			}
		}
		i++;
	}
}


void		free_cub(t_cub3d *cub)
{
	free_ids(cub->map.ids);
	free_tex_path(cub);
	free_map_lines(cub->map.map_lines);
	if (cub)
		free(cub);
}
