/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 16:14:46 by lwourms           #+#    #+#             */
/*   Updated: 2021/03/26 18:47:31 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	get_input(int key, t_cub3d *cub)
{
	if (key == KEY_ESCAPE)
	{
		mlx_clear_window(cub->mlx, cub->win);
		mlx_destroy_window(cub->mlx, cub->win);
		free_cub(cub);
		exit(0);
	}
	if (key == KEY_RIGHT)
		cub->player.yaw += 0.02;
	if (key == KEY_LEFT)
		cub->player.yaw -= 0.02;
	return (0);
}

static int	loop_game(t_cub3d *cub)
{
	draw(cub);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->image.image, 0, 0);
	return (0);
}

void		launch_game(t_cub3d *cub)
{
	cub->mlx = mlx_init();
	if (!cub->mlx)
		error_manager(-1, cub, NULL, NULL);
	cub->win = mlx_new_window(cub->mlx, cub->settings.window.width, \
	cub->settings.window.height, "CUB3D");
	if (!cub->win)
		error_manager(-1, cub, NULL, NULL);
	init_rays(&cub);
	cub->image = init_image(cub);
	mlx_key_hook(cub->win, get_input, cub);
	mlx_loop_hook(cub->mlx, loop_game, cub);
	mlx_loop(cub->mlx);
}
