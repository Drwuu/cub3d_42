/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 17:20:52 by lwourms           #+#    #+#             */
/*   Updated: 2021/05/16 19:57:06 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"
#include "../../../includes/inputs.h"

int	leave_window(t_cub3d *cub)
{
	mlx_clear_window(cub->mlx, cub->win);
	mlx_destroy_window(cub->mlx, cub->win);
	free_cub(cub);
	exit(0);
	return (0);
}

static void	fly(t_cub3d *cub)
{
	if (cub->settings.key[KP_MINUS])
		cub->player.pos.z -= 0.1f;
	if (cub->settings.key[KP_PLUS])
		cub->player.pos.z += 0.1f;
}

static void	crouch(t_cub3d *cub)
{
	if (cub->settings.key[KP_CTRL])
		cub->player.pos.z = 0.2f;
	else if (!cub->settings.fly)
		cub->player.pos.z = 0.5f;
}

static void	jump(t_cub3d *cub)
{
	if (cub->settings.key[KP_SPACE])
	{
		cub->player.pos.z = 0.8f;
		if (!cub->settings.fly && ft_get_time() - cub->engine.time.start >= 150)
			cub->player.pos.z = 0.5f;
	}
}

int	get_input(t_cub3d *cub)
{
	move_player(cub);
	rotate_player(cub);
	crouch(cub);
	jump(cub);
	fly(cub);
	return (0);
}
