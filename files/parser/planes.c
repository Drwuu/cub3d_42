/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   planes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 12:40:08 by lwourms           #+#    #+#             */
/*   Updated: 2021/03/31 21:14:18 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static t_plane	fill_plane(int A, int B, int C, int D)
{
	t_plane	plane;

	plane.A = A;
	plane.B = B;
	plane.C = C;
	plane.D = D;
	return (plane);
}

static void	fill_planes_with_zeros(t_plane ***planes, int width, int height)
{
	int	i;
	int	j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		if (i < 2)
			while (++j < height)
			{
				(*planes)[i][j].A = -1;
				(*planes)[i][j].B = -1;
				(*planes)[i][j].C = -1;
				(*planes)[i][j].D = -1;
			}
		else
			while (++j < width)
			{
				(*planes)[i][j].A = -1;
				(*planes)[i][j].B = -1;
				(*planes)[i][j].C = -1;
				(*planes)[i][j].D = -1;
			}
	}
}

t_plane	**init_planes(t_cub3d *cub)
{
	t_plane	**planes;
	
	planes = ft_calloc(sizeof(*planes), 4);
	planes[0] = ft_calloc(sizeof(**planes), cub->settings.window.height + 1);
	planes[1] = ft_calloc(sizeof(**planes), cub->settings.window.height + 1);
	planes[2] = ft_calloc(sizeof(**planes), cub->settings.window.width + 1);
	planes[3] = ft_calloc(sizeof(**planes), cub->settings.window.width + 1);
	if (!planes[0] || !planes[1] || !planes[2] || !planes[3])
	{
		if (planes[0])
			free(planes[0]);
		if (planes[1])
			free(planes[1]);
		if (planes[2])
			free(planes[2]);
		if (planes[3])
			free(planes[3]);
		error_manager(-1, cub, NULL, NULL);
	}
	fill_planes_with_zeros(&planes, cub->settings.window.width, \
	cub->settings.window.height);
	return (planes);
}

static void	get_extra_planes(t_cub3d *cub, t_plane	***planes, int j, int i)
{
	if (i == cub->map.size.y)
		(*planes)[0][i] = fill_plane(0, 1, 0, i);
	else if (i == 0)
		(*planes)[1][0] = fill_plane(0, 1, 0, 0);
	if (j == 0 && (*planes)[2][0].A < 0)
		(*planes)[2][0] = fill_plane(1, 0, 0, 0);
	else if (j == cub->map.size.x && (*planes)[3][j].A < 0)
		(*planes)[3][j] = fill_plane(1, 0, 0, j);
}

void	get_planes(t_cub3d *cub, t_plane ***planes, int **map, int i)
{
	int	j;

	j = -1;
	while (++j < cub->map.size.x)
	{
		get_extra_planes(cub, planes, j, i);
		if (map[i][j] == 0)
		{
			if (i > 0 && map[i - 1][j] == 1)
				if ((*planes)[0][i].B < 0)
					(*planes)[0][i] = fill_plane(0, 1, 0, i);
			if (i < cub->map.size.y - 1 && map[i + 1][j] == 1)
				if ((*planes)[1][i + 1].B < 0)
					(*planes)[1][i + 1] = fill_plane(0, 1, 0, i + 1);
			if (j > 0 && map[i][j - 1] == 1)
				if ((*planes)[3][j].A < 0)
					(*planes)[3][j] = fill_plane(1, 0, 0, j);
			if (j < cub->map.size.x - 1 && map[i][j + 1] == 1)
				if ((*planes)[2][j].A < 0)
					(*planes)[2][j] = fill_plane(1, 0, 0, j);
		}
	}
}
