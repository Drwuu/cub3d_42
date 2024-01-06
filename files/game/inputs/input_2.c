/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 17:20:52 by lwourms           #+#    #+#             */
/*   Updated: 2021/05/16 19:57:08 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

static int	key_pressed_3(int key, t_cub3d *cub)
{
	if (key == KEY_C)
	{
		if (cub->settings.collide)
			cub->settings.collide = FALSE;
		else
			cub->settings.collide = TRUE;
	}
	if (key == KEY_F)
	{
		if (!cub->settings.fly)
		{
			cub->settings.fly = TRUE;
			cub->settings.collide = FALSE;
		}
		else
		{
			cub->settings.fly = FALSE;
			cub->settings.collide = TRUE;
		}
	}
	return (0);
}

static int	key_pressed_2(int key, t_cub3d *cub)
{
	if (key == KEY_M && !cub->settings.multi_thread)
		cub->settings.multi_thread = TRUE;
	else if (key == KEY_M && cub->settings.multi_thread)
		cub->settings.multi_thread = FALSE;
	if (key == KEY_P)
		cub->settings.screen_shot = TRUE;
	if (key == KEY_ZERO)
		cub->player.pos = cub->player.start_pos;
	if (key == KEY_SPACE)
	{
		cub->engine.time.start = ft_get_time();
		cub->settings.key[KP_SPACE] = 1;
	}
	if (key == KEY_PLUS)
		cub->settings.key[KP_PLUS] = 1;
	if (key == KEY_MINUS)
		cub->settings.key[KP_MINUS] = 1;
	if (key == KEY_ESCAPE)
	{
		mlx_clear_window(cub->mlx, cub->win);
		mlx_destroy_window(cub->mlx, cub->win);
		free_cub(cub);
		exit(0);
	}
	return (0);
}

int	key_pressed(int key, t_cub3d *cub)
{
	if (key == KEY_W)
		cub->settings.key[KP_UP] = 1;
	if (key == KEY_S)
		cub->settings.key[KP_DOWN] = 1;
	if (key == KEY_A)
		cub->settings.key[KP_LEFT] = 1;
	if (key == KEY_D)
		cub->settings.key[KP_RIGHT] = 1;
	if (key == KEY_RIGHT)
		cub->settings.key[KP_R_RIGHT] = 1;
	if (key == KEY_LEFT)
		cub->settings.key[KP_R_LEFT] = 1;
	if (key == KEY_UP)
		cub->settings.key[KP_R_UP] = 1;
	if (key == KEY_DOWN)
		cub->settings.key[KP_R_DOWN] = 1;
	if (key == KEY_CTRL)
		cub->settings.key[KP_CTRL] = 1;
	key_pressed_2(key, cub);
	key_pressed_3(key, cub);
	return (0);
}

int	key_released(int key, t_cub3d *cub)
{
	if (key == KEY_W)
		cub->settings.key[KP_UP] = 0;
	if (key == KEY_S)
		cub->settings.key[KP_DOWN] = 0;
	if (key == KEY_A)
		cub->settings.key[KP_LEFT] = 0;
	if (key == KEY_D)
		cub->settings.key[KP_RIGHT] = 0;
	if (key == KEY_RIGHT)
		cub->settings.key[KP_R_RIGHT] = 0;
	if (key == KEY_LEFT)
		cub->settings.key[KP_R_LEFT] = 0;
	if (key == KEY_UP)
		cub->settings.key[KP_R_UP] = 0;
	if (key == KEY_DOWN)
		cub->settings.key[KP_R_DOWN] = 0;
	if (key == KEY_CTRL)
		cub->settings.key[KP_CTRL] = 0;
	if (key == KEY_SPACE)
		cub->settings.key[KP_SPACE] = 0;
	if (key == KEY_PLUS)
		cub->settings.key[KP_PLUS] = 0;
	if (key == KEY_MINUS)
		cub->settings.key[KP_MINUS] = 0;
	return (0);
}
