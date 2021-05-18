/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 16:45:32 by lwourms           #+#    #+#             */
/*   Updated: 2021/05/12 20:39:03 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

static t_sprite	process_set_sprites(int i, int j)
{
	t_sprite	sprite;

	sprite.pos.x = j + 0.5f;
	sprite.pos.y = i + 0.5f;
	sprite.pos.z = 0;
	sprite.plane.C = 0;
	sprite.plane.D = 0;
	return (sprite);
}

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
				sprite[k++] = process_set_sprites(i, j);
	}
	return (sprite);
}

float	get_sprite_ratio(t_vec3 intrsct, t_sprite sprite, t_player player)
{
	t_vec3	v2;
	t_vec3	u;

	u.x = intrsct.x - sprite.pos.x;
	u.y = intrsct.y - sprite.pos.y;
	v2 = ft_vec3_normalize(ft_vec3_create(sprite.pos.y - player.pos.y, \
		player.pos.x - sprite.pos.x, 0));
	return ((u.x * v2.x) + (u.y * v2.y) + 0.5);
}

t_color	get_sprt_pixel_color(t_image texture, t_vec3 intersect, float ratio)
{
	int				x;
	int				y;
	unsigned char	*pos;
	t_color			color;

	x = (1 - ratio) * texture.width;
	y = (1 - intersect.z) * texture.height;
	pos = ((unsigned char *)texture.addr) + x * 4 + y * texture.line_size;
	color = ft_create_color(pos[3], pos[2], pos[1], pos[0]);
	return (color);
}

t_bool	is_sprt_intrsct(t_cub3d *cub, t_sprite sprt, t_vec3 intrsct)
{
	if (intrsct.y >= 0 && intrsct.y <= cub->map.size.y \
		&& intrsct.x >= 0 && intrsct.x <= cub->map.size.x \
		&& (int)intrsct.y == (int)sprt.pos.y && \
		(int)intrsct.x == (int)sprt.pos.x)
		return (TRUE);
	else
		return (FALSE);
}
