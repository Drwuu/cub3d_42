/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 16:45:32 by lwourms           #+#    #+#             */
/*   Updated: 2021/05/12 20:35:53 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

void	update_sprite(t_cub3d *cub)
{
	int		i;

	i = -1;
	while (++i < cub->map.sprites_nb)
	{
		cub->sprite[i].v = ft_vec3_sub(cub->sprite[i].pos, cub->player.pos);
		cub->sprite[i].plane.A = cub->sprite[i].v.x;
		cub->sprite[i].plane.B = cub->sprite[i].v.y;
		cub->sprite[i].plane.C = 0;
		cub->sprite[i].plane.D = \
			-(cub->sprite[i].v.x * cub->sprite[i].pos.x) - \
				(cub->sprite[i].v.y * cub->sprite[i].pos.y);
	}
}

static float	get_sprite_dist(t_cub3d *cub, float div, int k)
{
	float	dist;

	dist = \
		-(cub->sprite[k].plane.A * cub->player.pos.x \
		+ cub->sprite[k].plane.B * cub->player.pos.y \
		+ cub->sprite[k].plane.D) / div;
	return (dist);
}

static float	get_div(t_cub3d *cub, t_vec3 ray_origin, int k)
{
	return (cub->sprite[k].plane.A * ray_origin.x \
		+ cub->sprite[k].plane.B * ray_origin.y);
}

void	draw_sprites(t_cub3d *cub, t_vec3 ray_origin, int i, int j)
{
	t_vec3	intersect;
	float	dist;
	float	ratio;
	int		k;

	k = -1;
	while (++k < cub->map.sprites_nb)
	{
		dist = get_sprite_dist(cub, get_div(cub, ray_origin, k), k);
		if (dist < 0 || dist > cub->engine.rays.dist_save[i][j])
			continue ;
		intersect = get_intersect(cub, ray_origin, dist);
		if (intersect.z > 1 || intersect.z < 0)
			continue ;
		if (is_sprt_intrsct(cub, cub->sprite[k], intersect))
		{
			ratio = get_sprite_ratio(intersect, cub->sprite[k], cub->player);
			if (ratio < 0 || ratio > 1)
				continue ;
			if (draw_pixel(cub->engine.game_image, i, j, get_sprt_pixel_color(
						cub->engine.texture[T_SPRITE1], intersect, ratio)))
				cub->engine.rays.dist_save[i][j] = dist;
		}
	}
}
