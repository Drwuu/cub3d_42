/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drwuu <drwuu@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 18:35:05 by drwuu             #+#    #+#             */
/*   Updated: 2021/03/08 01:28:01 by drwuu            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// check free with new structures

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
	if (cub)
		free(cub);
}
