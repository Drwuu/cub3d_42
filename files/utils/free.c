/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 18:35:05 by drwuu             #+#    #+#             */
/*   Updated: 2021/04/23 13:09:02 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void		free_rays(t_cub3d *cub)
{
	int i;

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

static void		free_textures_path(t_cub3d *cub)
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
	// if (cub->win)
	// {
	// 	dprintf(1, "win ptr = %p\n", cub->win);
	// 	mlx_destroy_window(cub->mlx, cub->win);
	// }
	// if (cub->engine.game_image.image)
	// {
	// 	dprintf(1, "img ptr = %p\n", cub->engine.game_image.image);
	// 	mlx_destroy_image(cub->mlx, cub->engine.game_image.image);
	// }
	// if (cub->engine.texture[0].image)
	// {
	// 	dprintf(1, "texture ptr = %p\n", cub->engine.texture[0].image);
	// 	mlx_destroy_image(cub->mlx, cub->engine.texture[0].image);
	// }
}
