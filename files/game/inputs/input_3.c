/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 17:20:52 by lwourms           #+#    #+#             */
/*   Updated: 2021/05/16 19:57:08 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

void	rotate_player(t_cub3d *cub)
{
	if (cub->settings.key[KP_R_RIGHT])
	{
		cub->player.yaw += 0.1f;
		cub->player.cos_yaw = cosf(cub->player.yaw);
		cub->player.sin_yaw = sinf(cub->player.yaw);
	}
	if (cub->settings.key[KP_R_LEFT])
	{
		cub->player.yaw -= 0.1f;
		cub->player.cos_yaw = cosf(cub->player.yaw);
		cub->player.sin_yaw = sinf(cub->player.yaw);
	}
	if (cub->settings.key[KP_R_UP])
	{
		cub->player.pitch -= 0.1f;
		cub->player.cos_pitch = cosf(cub->player.pitch);
		cub->player.sin_pitch = sinf(cub->player.pitch);
	}
	if (cub->settings.key[KP_R_DOWN])
	{
		cub->player.pitch += 0.1f;
		cub->player.cos_pitch = cosf(cub->player.pitch);
		cub->player.sin_pitch = sinf(cub->player.pitch);
	}
}

void	move_player(t_cub3d *cub)
{
	if (cub->settings.key[KP_UP] || cub->settings.key[KP_DOWN] || \
		cub->settings.key[KP_LEFT] || cub->settings.key[KP_RIGHT])
	{
		if (cub->settings.key[KP_UP])
			cub->player.pos = move_player_y(cub, cub->player, 1);
		if (cub->settings.key[KP_DOWN])
			cub->player.pos = move_player_y(cub, cub->player, -1);
		if (cub->settings.key[KP_LEFT])
			cub->player.pos = move_player_x(cub, cub->player, -1);
		if (cub->settings.key[KP_RIGHT])
			cub->player.pos = move_player_x(cub, cub->player, 1);
		update_sprite(cub);
	}
}
