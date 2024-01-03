/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 19:42:53 by lwourms           #+#    #+#             */
/*   Updated: 2021/05/12 20:09:14 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"
#ifndef M_PI_2
#define M_PI_2 1.57079632679489661923
#endif

t_vec3	get_intersect(t_cub3d *cub, t_vec3 origin, float distance)
{
	t_vec3	intersect;

	intersect.x = cub->player.pos.x + origin.x * distance;
	intersect.y = cub->player.pos.y + origin.y * distance;
	intersect.z = cub->player.pos.z + origin.z * distance;
	return (intersect);
}

t_vec3	rotate_vector_z(t_player player, t_vec3 vector)
{
	t_vec3	new_vector;

	new_vector.x = vector.x * player.cos_yaw - vector.y * player.sin_yaw;
	new_vector.y = vector.x * player.sin_yaw + vector.y * player.cos_yaw;
	new_vector.z = vector.z;
	return (new_vector);
}

t_vec3	rotate_vector_x(t_player player, t_vec3 vector)
{
	t_vec3	new_vector;

	new_vector.x = vector.x;
	new_vector.y = vector.y * player.cos_pitch - vector.z * player.sin_pitch;
	new_vector.z = vector.y * player.sin_pitch + vector.z * player.cos_pitch;
	return (new_vector);
}

t_vec3	move_player_x(t_cub3d *cub, t_player player, int direction)
{
	t_vec3	new_pos;
	int		x;
	int		y;

	new_pos.z = player.pos.z;
	if (direction == 1)
	{
		new_pos.x = player.pos.x + (sinf(player.yaw + M_PI_2) * player.speed);
		new_pos.y = player.pos.y - (cosf(player.yaw + M_PI_2) * player.speed);
	}
	else if (direction == -1)
	{
		new_pos.x = player.pos.x + (sinf(player.yaw - M_PI_2) * player.speed);
		new_pos.y = player.pos.y - (cosf(player.yaw - M_PI_2) * player.speed);
	}
	x = new_pos.x;
	y = new_pos.y;
	if (cub->settings.collide && y >= 0 && y < cub->map.size.y && x >= 0 && \
		x < cub->map.size.x)
		if (cub->map.map[y][x] == 1 || cub->map.map[y][x] == 2)
			return (player.pos);
	return (new_pos);
}

t_vec3	move_player_y(t_cub3d *cub, t_player player, int direction)
{
	t_vec3	new_player_pos;
	int		x;
	int		y;

	new_player_pos.z = player.pos.z;
	if (direction == 1)
	{
		new_player_pos.x = player.pos.x + (sinf(player.yaw) * player.speed);
		new_player_pos.y = player.pos.y - (cosf(player.yaw) * player.speed);
	}
	else
	{
		new_player_pos.x = player.pos.x - (sinf(player.yaw) * player.speed);
		new_player_pos.y = player.pos.y + (cosf(player.yaw) * player.speed);
	}
	x = new_player_pos.x;
	y = new_player_pos.y;
	if (cub->settings.collide && y >= 0 && y < cub->map.size.y && x >= 0 && \
		x < cub->map.size.x)
		if (cub->map.map[y][x] == 1 || cub->map.map[y][x] == 2)
			return (player.pos);
	return (new_player_pos);
}
