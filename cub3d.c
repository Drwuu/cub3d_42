/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 10:52:48 by lwourms           #+#    #+#             */
/*   Updated: 2021/04/13 12:33:44 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

static t_player	init_player(int life, int amos, float speed)
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

static t_settings	set_settings(t_cub3d *cub)
{
	t_settings	settings;
	int			i;

	i = -1;
	while (++i < 6)
		settings.key[i] = 0;
	settings.fov = 120;
	settings.multi_thread = FALSE;
	if (mlx_get_screen_size(cub->mlx, &settings.user_screen_size.width, \
	&settings.user_screen_size.height) < 0)
		error_manager(-1, cub, NULL, NULL);
	return (settings);
}

int	main(int argc, char **argv)
{
	t_cub3d	cub;

	if (argc < 2)
		error_manager(-4, NULL, NULL, NULL);
	ft_bzero(&cub, sizeof(cub));
	cub.mlx = mlx_init();
	if (!cub.mlx)
		error_manager(-1, &cub, NULL, NULL);
	cub.settings = set_settings(&cub);
	cub.player = init_player(100, 50, 0.2f);
	parse_map(argv[1], &cub);
	cub.engine.texture[0] = get_texture(&cub, cub.map.wall_tex[0]);
	cub.engine.texture[1] = get_texture(&cub, cub.map.wall_tex[1]);
	cub.engine.texture[2] = get_texture(&cub, cub.map.wall_tex[2]);
	cub.engine.texture[3] = get_texture(&cub, cub.map.wall_tex[3]);
	start(&cub);
	free_cub(&cub);
	return (0);
}
