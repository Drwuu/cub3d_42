/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 16:45:32 by lwourms           #+#    #+#             */
/*   Updated: 2021/04/24 18:29:36 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

t_sprite	*set_sprites(t_cub3d *cub)
{
	t_sprite	*sprite;
	int			i;
	int			j;
	int			k;
	
	sprite = ft_calloc(sizeof(*sprite), cub->map.sprites_nb);
	if (!sprite)
		error_manager(-1, cub, NULL, NULL);
	k = 0;
	i = -1;
	while (++i < cub->map.size.y)
	{
		j = -1;
		while (++j < cub->map.size.x)
			if (cub->map.map[i][j] == 2)
			{
				sprite[k].pos.x = j + 0.5f;
				sprite[k].pos.y = i + 0.5f;
				sprite[k].pos.z = 0;
				sprite[k].plane.C = 0;
				sprite[k++].plane.D = 0;
			}	
	}
	return (sprite);
}

void	update_sprite(t_cub3d *cub)
{
	t_plane	plane;
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

void	draw_sprites(t_cub3d *cub, t_vec3 ray_origin, int i, int j)
{
	t_vec3	intersect;
	float	div;
	float	dist;
	float	ratio;
	int		k;

	k = -1;
	while (++k < cub->map.sprites_nb)
	{
		div = cub->sprite[k].plane.A * ray_origin.x \
			+ cub->sprite[k].plane.B * ray_origin.y;
		if (div == 0)
			continue ;
		dist = \
			-(cub->sprite[k].plane.A * cub->player.pos.x \
			+ cub->sprite[k].plane.B * cub->player.pos.y \
			+ cub->sprite[k].plane.D) / div;
		if (dist < 0 || dist > cub->engine.rays.dist_save[i][j])
			continue ;
		intersect = get_intersect(cub, ray_origin, dist);
		if (is_sprt_intrsct(cub, cub->sprite[k], intersect))
		{
			ratio = get_sprite_ratio(intersect, cub->sprite[k], cub->player);
			if (ratio < 0 || ratio > 1)
				continue ;
			cub->engine.rays.dist_save[i][j] = dist;
			draw_pixel(cub->engine.game_image, i, j, \
				get_sprt_pixel(cub, cub->engine.texture[0], intersect, ratio));
		}
	}
}
