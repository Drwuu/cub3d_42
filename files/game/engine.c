/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 19:42:53 by lwourms           #+#    #+#             */
/*   Updated: 2021/03/27 15:19:30 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_vec3	rotate_z(t_vec3 vector, float angle_rad)
{
	t_vec3	new_vector;

	new_vector.x = vector.x * cosf(angle_rad) - vector.y * sinf(angle_rad);
	new_vector.y = vector.x * sinf(angle_rad) + vector.y * cosf(angle_rad);
	new_vector.z = vector.z;
	return (new_vector);
}

t_vec3	rotate_x(t_vec3 vector, float angle_rad)
{
	t_vec3	new_vector;

	new_vector.x = vector.x;
	new_vector.y = vector.y * cosf(angle_rad) - vector.z * sinf(angle_rad);
	new_vector.z = vector.y * sinf(angle_rad) +  vector.z * cosf(angle_rad);
	return (new_vector);
}

void	find_distance_until_wall(t_cub3d *cub)
{
	// float	distance;
	// float	direction;
	// t_vec3	wall;

	// direction = cub->player.yaw;
	// if (direction >= 0 && direction <= M_PI_2)
	// 	distance = plane[k].A * rays.x + plane[k].B * rays.y + plane[k].C * rays.z;
	// else if (direction >= -M_PI_2 && direction <= 0)
	// 	wall = find_nw_wall(cub, cub->map.map);
	// else if (direction >= M_PI_2 && direction <= M_PI)
	// 	wall = find_se_wall(cub, cub->map.map);
	// else
	// 	wall = find_sw_wall(cub, cub->map.map);
	// wall = get_wall_intersection(cub, cub->player.yaw);
}
