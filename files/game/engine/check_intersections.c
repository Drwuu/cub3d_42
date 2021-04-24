/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_intersections.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 19:46:58 by lwourms           #+#    #+#             */
/*   Updated: 2021/04/21 17:51:59 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

t_bool	is_intersect_north(t_cub3d *cub, t_vec3 intersect, int y)
{
	if (intersect.y > 0 && intersect.y <= cub->player.pos.y \
		&& intersect.x >= 0 && intersect.x < cub->map.size.x - 1 \
		&& cub->map.map[y][(int)(intersect.x)] == 1)
		return (TRUE);
	else
		return (FALSE);
}

t_bool	is_intersect_south(t_cub3d *cub, t_vec3 intersect, int y)
{
	if (intersect.y >= cub->player.pos.y && intersect.y < cub->map.size.y \
		&& intersect.x > 0 && intersect.x < cub->map.size.x - 1 \
		&& cub->map.map[y][(int)(intersect.x)] == 1)
		return (TRUE);
	else
		return (FALSE);
}

t_bool	is_intersect_east(t_cub3d *cub, t_vec3 intersect, int x)
{
	if (intersect.y > 0 && intersect.y < cub->map.size.y - 1 \
		&& intersect.x >= cub->player.pos.x && intersect.x < cub->map.size.x \
		&& cub->map.map[(int)(intersect.y)][x] == 1)
		return (TRUE);
	else
		return (FALSE);
}

t_bool	is_intersect_west(t_cub3d *cub, t_vec3 intersect, int x)
{
	if (intersect.y > 0 && intersect.y < cub->map.size.y \
		&& intersect.x > 0 && intersect.x <= cub->player.pos.x \
		&& cub->map.map[(int)(intersect.y)][x] == 1)
		return (TRUE);
	else
		return (FALSE);
}
