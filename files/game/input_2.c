/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 17:20:52 by lwourms           #+#    #+#             */
/*   Updated: 2021/04/24 15:37:16 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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
}

void	move_player(t_cub3d *cub)
{
	if (cub->settings.key[KP_UP] || cub->settings.key[KP_DOWN] || \
		cub->settings.key[KP_LEFT] || cub->settings.key[KP_RIGHT])
	{
		if (cub->settings.key[KP_UP])
			cub->player.pos = move_player_y(cub->player, 1);
		if (cub->settings.key[KP_DOWN])
			cub->player.pos = move_player_y(cub->player, -1);
		if (cub->settings.key[KP_LEFT])
			cub->player.pos = move_player_x(cub->player, -1);
		if (cub->settings.key[KP_RIGHT])
			cub->player.pos = move_player_x(cub->player, 1);
		update_sprite(cub);
	}
}

int	key_pressed(int key, t_cub3d *cub)
{
	if (key == KEY_UP || key == KEY_W)
		cub->settings.key[KP_UP] = 1;
	if (key == KEY_DOWN || key == KEY_S)
		cub->settings.key[KP_DOWN] = 1;
	if (key == KEY_A)
		cub->settings.key[KP_LEFT] = 1;
	if (key == KEY_D)
		cub->settings.key[KP_RIGHT] = 1;
	if (key == KEY_RIGHT)
		cub->settings.key[KP_R_RIGHT] = 1;
	if (key == KEY_LEFT)
		cub->settings.key[KP_R_LEFT] = 1;
	if (key == KEY_M && !cub->settings.multi_thread)
		cub->settings.multi_thread = TRUE;
	else if (key == KEY_M && cub->settings.multi_thread)
		cub->settings.multi_thread = FALSE;
	if (key == KEY_ZERO)
		cub->player.pos = cub->player.start_pos;
	if (key == KEY_ESCAPE)
	{
		mlx_clear_window(cub->mlx, cub->win);
		mlx_destroy_window(cub->mlx, cub->win);
		free_cub(cub);
		exit(0);
	}
	return (0);
}

int	key_released(int key, t_cub3d *cub)
{
	if (key == KEY_UP || key == KEY_W)
		cub->settings.key[0] = 0;
	if (key == KEY_DOWN || key == KEY_S)
		cub->settings.key[1] = 0;
	if (key == KEY_A)
		cub->settings.key[2] = 0;
	if (key == KEY_D)
		cub->settings.key[3] = 0;
	if (key == KEY_RIGHT)
		cub->settings.key[4] = 0;
	if (key == KEY_LEFT)
		cub->settings.key[5] = 0;
	return (0);
}
