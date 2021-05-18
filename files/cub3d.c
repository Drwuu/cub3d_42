/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 10:52:48 by lwourms           #+#    #+#             */
/*   Updated: 2021/05/12 20:08:35 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	init_tetxures(t_cub3d *cub)
{
	cub->engine.texture[T_NORTH] = get_texture(cub, cub->map.texture[T_NORTH]);
	cub->engine.texture[T_SOUTH] = get_texture(cub, cub->map.texture[T_SOUTH]);
	cub->engine.texture[T_EAST] = get_texture(cub, cub->map.texture[T_EAST]);
	cub->engine.texture[T_WEST] = get_texture(cub, cub->map.texture[T_WEST]);
	if (cub->map.texture[T_FLOOR])
		cub->engine.texture[T_FLOOR] = \
			get_texture(cub, cub->map.texture[T_FLOOR]);
	if (cub->map.texture[T_CEIL])
		cub->engine.texture[T_CEIL] = \
			get_texture(cub, cub->map.texture[T_CEIL]);
	cub->engine.texture[T_SPRITE1] = \
		get_texture(cub, cub->map.texture[T_SPRITE1]);
}

static t_player	init_player(int life, int amos, float speed)
{
	t_player	player;

	player.pos.x = 0;
	player.pos.y = 0;
	player.pos.z = 0.5f;
	player.yaw = -1;
	player.pitch = 0;
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
	while (++i < KEY_USED_NB)
		settings.key[i] = 0;
	settings.fov = 60;
	settings.multi_thread = FALSE;
	settings.screen_shot = FALSE;
	settings.fly = FALSE;
	settings.collide = TRUE;
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
	init_tetxures(&cub);
	if (argc == 3 && (ft_strncmp(argv[2], "--save", 6) == 0))
		cub.settings.screen_shot = TRUE;
	start(&cub);
	free_cub(&cub);
	return (0);
}
