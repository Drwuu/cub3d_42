/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 11:48:32 by lwourms           #+#    #+#             */
/*   Updated: 2021/03/26 18:58:20 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_player	init_player(int life, int amos, int speed)
{
	t_player player;

	player.pos.x = 0;
	player.pos.y = 0;
	player.pos.z = 0.5f;
	player.yaw = -1;
	player.speed = speed;
	player.life = life;
	player.amos = amos;
	return (player);
}
