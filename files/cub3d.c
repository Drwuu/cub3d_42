/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 10:52:48 by lwourms           #+#    #+#             */
/*   Updated: 2021/03/21 12:44:35 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static t_settings set_settings(t_cub3d *cub)
{
	t_settings	settings;

	settings.FOV = 60;
	return (settings);
}

int		main()
{
	t_cub3d		*cub;

	cub = parse_map("map.cub");
	cub->settings = set_settings(cub);
	launch_game(cub);
	free_cub(cub);
	return (0);
}
