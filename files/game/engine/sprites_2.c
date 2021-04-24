/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 16:45:32 by lwourms           #+#    #+#             */
/*   Updated: 2021/04/24 18:29:44 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

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

unsigned int	get_sprt_pixel(t_cub3d *cub, t_image texture, \
t_vec3 intersect, float ratio)
{
	float	percent;

	if (intersect.z > 1)
		return (0x0000AA);
	else if (intersect.z < 0)
		return (0x8800AA);
	percent = 1 - ratio;
	return (texture.addr[(int)(percent * texture.width) \
		+ (int)(intersect.z * texture.height) * texture.width]);
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
