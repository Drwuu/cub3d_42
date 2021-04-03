/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 10:52:48 by lwourms           #+#    #+#             */
/*   Updated: 2021/04/03 10:31:57 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static t_cub3d	*init_cub(t_cub3d *cub)
{
	cub = ft_calloc(sizeof(*cub), 1);
	if (!cub)
		error_manager(-1, cub, NULL, NULL);
	ft_bzero(cub, sizeof(*cub));
	return (cub);
}


static t_settings set_settings(void)
{
	t_settings	settings;

	settings.fov = 60;
	return (settings);
}

int		main()
{

	t_cub3d		*cub;

	cub = init_cub(cub);
	cub->settings = set_settings();
	cub->player = init_player(100, 50, 1);
	parse_map("map.cub", cub);

	// t_list	*first_id;
	// t_list	*first_map;
	// first_id = cub->map.idlines;
	// first_map = cub->map.maplines;
	// while (cub->map.idlines)
	// {
	// 	dprintf(1, "id line = %s\n", cub->map.idlines->content);
	// 	cub->map.idlines = cub->map.idlines->next;
	// }
	// while (cub->map.maplines)
	// {
	// 	dprintf(1, "map line = %s\n", cub->map.maplines->content);
	// 	cub->map.maplines = cub->map.maplines->next;
	// }
	// cub->map.idlines = first_id;
	// cub->map.maplines = first_map;
	// dprintf(1, "floor red color = %d\n", cub->map.floor.color.r);
	// dprintf(1, "ceiling red color = %d\n", cub->map.ceiling.color.r);
	// dprintf(1, "NO wall texture = %s\n", cub->map.wall_tex[0]);
	// dprintf(1, "SO wall texture = %s\n", cub->map.wall_tex[1]);
	// dprintf(1, "EA wall texture = %s\n", cub->map.wall_tex[2]);
	// dprintf(1, "WE wall texture = %s\n", cub->map.wall_tex[3]);
	// dprintf(1, "sprite texture = %s\n", cub->map.sprite_tex);
	// dprintf(1, "size x = %f\n", cub->map.size.x);
	// dprintf(1, "size y = %f\n", cub->map.size.y);
	// dprintf(1, "player x pos = %f\n", cub->player.pos.x);
	// dprintf(1, "player y pos = %f\n", cub->player.pos.y);
	// dprintf(1, "player yaw = %f\n", cub->player.yaw);
	// dprintf(1, "enemies = %d\n", cub->map.enemy_nb);
	int i = 0;
	while (i <= cub->map.size.y)
	{
		dprintf(1, "north plane in %d = %f, %f, %f, %f\n", i, cub->planes[0][i].A, cub->planes[0][i].B, cub->planes[0][i].C, cub->planes[0][i].D);
		dprintf(1, "south plane in %d = %f, %f, %f, %f\n", i, cub->planes[1][i].A, cub->planes[1][i].B, cub->planes[1][i].C, cub->planes[1][i].D);
		i++;
	}
	i = 0;
	while (i <= cub->map.size.x)
	{
		dprintf(1, "east plane in %d = %f, %f, %f, %f\n", i, cub->planes[2][i].A, cub->planes[2][i].B,cub->planes[2][i].C, cub->planes[2][i].D);
		dprintf(1, "west plane in %d = %f, %f, %f, %f\n", i, cub->planes[3][i].A, cub->planes[3][i].B, cub->planes[3][i].C, cub->planes[3][i].D);
		i++;
	}
	launch_game(cub);
	free_cub(cub);
	return (0);
}
