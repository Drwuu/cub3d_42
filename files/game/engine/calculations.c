/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 19:42:53 by lwourms           #+#    #+#             */
/*   Updated: 2021/04/21 17:36:57 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

t_vec3	get_intersect(t_cub3d *cub, t_vec3 origin, float distance)
{
	t_vec3	intersect;

	intersect.x = cub->player.pos.x + (origin.x * distance);
	intersect.y = cub->player.pos.y + (origin.y * distance);
	intersect.z = cub->player.pos.z + (origin.z * distance);
	return (intersect);
}

t_vec3	rotate_z(t_player player, t_vec3 vector)
{
	t_vec3	new_vector;

	new_vector.x = vector.x * player.cos_yaw - vector.y * player.sin_yaw;
	new_vector.y = vector.x * player.sin_yaw + vector.y * player.cos_yaw;
	new_vector.z = vector.z;
	return (new_vector);
}

t_vec3	rotate_x(t_player player, t_vec3 vector)
{
	t_vec3	new_vector;

	new_vector.x = vector.x;
	new_vector.y = vector.y * player.cos_yaw - vector.z * player.sin_yaw;
	new_vector.z = vector.y * player.sin_yaw +  vector.z * player.cos_yaw;
	return (new_vector);
}

t_vec3	move_player_x(t_player player, int direction)
{
	t_vec3	new_player_pos;

	new_player_pos.z = player.pos.z;
	if (direction == 1)
	{
		new_player_pos.x = player.pos.x + (sinf(player.yaw + M_PI_2) * player.speed);
		new_player_pos.y = player.pos.y - (cosf(player.yaw + M_PI_2) * player.speed);
	}
	else if (direction == -1)
	{
		new_player_pos.x = player.pos.x + (sinf(player.yaw - M_PI_2) * player.speed);
		new_player_pos.y = player.pos.y - (cosf(player.yaw - M_PI_2) * player.speed);
	}
	return (new_player_pos);
}

t_vec3	move_player_y(t_player player, int direction)
{
	t_vec3	new_player_pos;

	new_player_pos.z = player.pos.z;
	if (direction == 1)
	{
		new_player_pos.x = player.pos.x + (sinf(player.yaw) * player.speed);
		new_player_pos.y = player.pos.y - (cosf(player.yaw) * player.speed);
	}
	else if (direction == -1)
	{
		new_player_pos.x = player.pos.x - (sinf(player.yaw) * player.speed);
		new_player_pos.y = player.pos.y + (cosf(player.yaw) * player.speed);
	}
	return (new_player_pos);
}
