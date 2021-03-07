/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 18:35:05 by drwuu             #+#    #+#             */
/*   Updated: 2021/03/07 18:07:47 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void free_tex_path(t_cub3d *cub)
{
	int i;

	i = 0;
	while (i < 5)
	{
		if (cub->tex_path[i])
		{
			free(cub->tex_path[i]);
			cub->tex_path[i] = NULL;
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
	free_ids(cub->ids);
	free_tex_path(cub);
	if (cub)
		free(cub);
}
