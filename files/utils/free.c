/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 18:35:05 by drwuu             #+#    #+#             */
/*   Updated: 2021/03/07 14:33:41 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void free_ids(t_cub3d *cub)
{
	int i;

	i = 0;
	while (i < 8)
	{
		dprintf(1, "bulma %d\n", cub->ids[i].id);
		if (cub->ids[i].id)
		{
			if (cub->ids[i].line)
				free(cub->ids[i].line);
		}
		i++;
	}
	free(cub->ids);
}

static void free_tex_path(t_cub3d *cub)
{
	int i;

	i = 0;
	while (i < 5)
	{
		if (cub->tex_path[i])
			free(cub->tex_path[i]);
		i++;
	}
}

void		free_cub(t_cub3d *cub)
{
	if (cub->ids)
		free_ids(cub);
	if (cub->tex_path)
		free_tex_path(cub);
	if (cub)
		free(cub);
}
