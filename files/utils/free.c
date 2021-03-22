/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 18:35:05 by drwuu             #+#    #+#             */
/*   Updated: 2021/03/22 17:03:11 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void		free_rays(t_cub3d *cub)
{
	int i;

	i = -1;
	if (cub->rays.vector)
	{
		while (++i < cub->window.height)
			if (cub->rays.vector[i])
				free(cub->map.wall_tex[i]);
		free (cub->rays.vector);
	}
}

static void		free_textures(t_cub3d *cub)
{
	int i;

	i = -1;
	while (++i < 4)
		if (cub->map.wall_tex[i])
			free(cub->map.wall_tex[i]);
	if (cub->map.sprite_tex)
		free(cub->map.sprite_tex);
}

void		free_cub(t_cub3d *cub)
{
	ft_lstclear(&cub->map.garbage_idlines, free);
	ft_lstclear(&cub->map.garbage_maplines, free);
	free_textures(cub);
	free_rays(cub);
	if (cub->map.map)
		ft_free_dbl_array((void **)cub->map.map, cub->map.size.y);
	free(cub);
}
