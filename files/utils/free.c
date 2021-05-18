/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 18:35:05 by drwuu             #+#    #+#             */
/*   Updated: 2021/05/12 20:55:04 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	free_rays(t_cub3d *cub)
{
	int	i;

	i = -1;
	if (cub->engine.rays.vector)
	{
		while (++i < cub->settings.window.height)
			if (cub->engine.rays.vector[i])
				free(cub->engine.rays.vector[i]);
		free(cub->engine.rays.vector);
	}
	i = -1;
	if (cub->engine.rays.dist_save)
	{
		while (++i < cub->settings.window.height)
			if (cub->engine.rays.dist_save[i])
				free(cub->engine.rays.dist_save[i]);
		free(cub->engine.rays.dist_save);
	}
}

static void	free_textures_path(t_cub3d *cub)
{
	int	i;

	i = -1;
	while (++i < TEXTURE_NB)
		if (cub->map.texture[i])
			free(cub->map.texture[i]);
}

void	free_cub(t_cub3d *cub)
{
	ft_lstclear(&cub->map.idlines, free);
	ft_lstclear(&cub->map.maplines, free);
	free_textures_path(cub);
	free_rays(cub);
	if (cub->map.map)
		ft_free_dbl_array((void **)cub->map.map, cub->map.size.y);
	if (cub->engine.planes)
		ft_free_dbl_array((void **)cub->engine.planes, 4);
	if (cub->engine.fps.join)
		free(cub->engine.fps.join);
	if (cub->sprite)
		free(cub->sprite);
}
