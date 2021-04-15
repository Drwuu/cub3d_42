/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_intersections.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 19:46:58 by lwourms           #+#    #+#             */
/*   Updated: 2021/04/10 17:17:47 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

t_bool	is_intersect_north(t_cub3d *cub, t_vec3 intersect, float distance, \
int index)
{
	int		x;
	int		y;
	
	if (intersect.y > 0 && intersect.y <= cub->player.pos.y \
	&& intersect.x >= 0 && intersect.x < cub->map.size.x - 1 \
	&& cub->map.map[(int)cub->engine.planes[0][index].D - 1] \
	[(int)(intersect.x)] == 1)
		return (TRUE);
	else
		return (FALSE);
}

t_bool	is_intersect_south(t_cub3d *cub, t_vec3 intersect, float distance, \
int index)
{
	if (intersect.y >= cub->player.pos.y && intersect.y < cub->map.size.y \
	&& intersect.x > 0 && intersect.x < cub->map.size.x - 1 \
	&& cub->map.map[(int)cub->engine.planes[1][index].D] \
	[(int)(intersect.x)] == 1)
		return (TRUE);
	else
		return (FALSE);
}

t_bool	is_intersect_east(t_cub3d *cub, t_vec3 intersect, float distance, \
int index)
{
	if (intersect.y > 0 && intersect.y < cub->map.size.y - 1 \
	&& intersect.x >= cub->player.pos.x && intersect.x < cub->map.size.x \
	&& cub->map.map[(int)(intersect.y)] \
	[(int)cub->engine.planes[2][index].D] == 1)
		return (TRUE);
	else
		return (FALSE);
}

t_bool	is_intersect_west(t_cub3d *cub, t_vec3 intersect, float distance, \
int index)
{
	if (intersect.y > 0 && intersect.y < \
	cub->map.size.y && intersect.x > 0 && \
	intersect.x <= cub->player.pos.x \
	&& cub->map.map[(int)(intersect.y)] \
	[(int)cub->engine.planes[3][index].D - 1] == 1)
		return (TRUE);
	else
		return (FALSE);
}
