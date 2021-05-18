/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_textures_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 18:46:54 by lwourms           #+#    #+#             */
/*   Updated: 2021/05/12 20:14:06 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

void	draw_ceil(t_cub3d *cub, t_vec3 ray_origin, int i, int j)
{
	t_vec3	intersect;
	float	dist;

	dist = -(cub->player.pos.z - 1) / ray_origin.z;
	if (dist < 0 || dist > cub->engine.rays.dist_save[i][j])
		return ;
	intersect = get_intersect(cub, ray_origin, dist);
	if (cub->map.texture[T_CEIL])
		draw_pixel(cub->engine.game_image, i, j, \
			get_cf_color(cub->engine.texture[T_CEIL], intersect));
	else
		draw_pixel(cub->engine.game_image, i, j, cub->map.ceiling.color);
	cub->engine.rays.dist_save[i][j] = dist;
}

void	draw_floor(t_cub3d *cub, t_vec3 ray_origin, int i, int j)
{
	t_vec3	intersect;
	float	dist;

	dist = -cub->player.pos.z / ray_origin.z;
	if (dist < 0 || dist > cub->engine.rays.dist_save[i][j])
		return ;
	intersect = get_intersect(cub, ray_origin, dist);
	if (cub->map.texture[T_FLOOR])
		draw_pixel(cub->engine.game_image, i, j, \
			get_cf_color(cub->engine.texture[T_FLOOR], intersect));
	else
		draw_pixel(cub->engine.game_image, i, j, cub->map.floor.color);
	cub->engine.rays.dist_save[i][j] = dist;
}
