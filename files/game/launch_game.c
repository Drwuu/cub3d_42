/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 16:14:46 by lwourms           #+#    #+#             */
/*   Updated: 2021/03/22 15:15:18 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	loop_game(int key, t_cub3d *cub)
{
	if (key == KEY_ESCAPE)
	{
		mlx_clear_window(cub->mlx, cub->win);
		mlx_destroy_window(cub->mlx, cub->win);
		free_cub(cub);
		exit(0);
	}
	draw(cub);
	return (0);
}

void		launch_game(t_cub3d *cub)
{
	cub->mlx = mlx_init();
	if (!cub->mlx)
		error_manager(-1, cub, NULL, NULL);
	cub->win = mlx_new_window(cub->mlx, cub->window.width, \
	cub->window.height, "CUB3D");
	if (!cub->win)
		error_manager(-1, cub, NULL, NULL);
	//create_frame(cub);
	//mlx_pixel_put(cub->mlx, cub->win, cub->window.width / 2, cub->window.height / 2, 0x00FF0000);
	mlx_key_hook(cub->win, loop_game, cub);
	mlx_loop(cub->mlx);
}
