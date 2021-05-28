/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   planes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 12:40:08 by lwourms           #+#    #+#             */
/*   Updated: 2021/05/27 11:50:45 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	get_extra_planes(t_cub3d *cub, t_plane	***planes, int j, int i)
{
	if (i + 1 == cub->map.size.y)
		(*planes)[0][i + 1] = set_plane(0, 1, 0, i + 1);
	else if (i == 0)
		(*planes)[1][0] = set_plane(0, 1, 0, 0);
	if (j == 0 && (*planes)[2][0].A < 0)
		(*planes)[2][0] = set_plane(1, 0, 0, 0);
	else if (j + 1 == cub->map.size.x && (*planes)[3][j + 1].A < 0)
		(*planes)[3][j + 1] = set_plane(1, 0, 0, j + 1);
}

void	get_planes(t_cub3d *cub, t_plane ***planes, int **map, int i)
{
	int	j;

	j = -1;
	while (++j < cub->map.size.x)
	{
		get_extra_planes(cub, planes, j, i);
		if (map[i][j] == 0 || map[i][j] == 2)
		{
			if (i > 0 && map[i - 1][j] == 1)
				if ((*planes)[0][i].B < 0)
					(*planes)[0][i] = set_plane(0, 1, 0, i);
			if (i < cub->map.size.y - 1 && map[i + 1][j] == 1)
				if ((*planes)[1][i + 1].B < 0)
					(*planes)[1][i + 1] = set_plane(0, 1, 0, i + 1);
			if (j > 0 && map[i][j - 1] == 1)
				if ((*planes)[3][j].A < 0)
					(*planes)[3][j] = set_plane(1, 0, 0, j);
			if (j < cub->map.size.x - 1 && map[i][j + 1] == 1)
				if ((*planes)[2][j + 1].A < 0)
					(*planes)[2][j + 1] = set_plane(1, 0, 0, j + 1);
		}
	}
}
