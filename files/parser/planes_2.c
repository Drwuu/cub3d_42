/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   planes_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 12:40:08 by lwourms           #+#    #+#             */
/*   Updated: 2021/05/12 20:50:30 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_plane	set_plane(int A, int B, int C, int D)
{
	t_plane	plane;

	plane.A = A;
	plane.B = B;
	plane.C = C;
	plane.D = D;
	return (plane);
}

static void	process_set_planes(t_plane ***planes, int i, int width, int hght)
{
	int	j;

	j = -1;
	if (i < 2)
	{
		while (++j < hght + 1)
		{
			(*planes)[i][j].A = -1;
			(*planes)[i][j].B = -1;
			(*planes)[i][j].C = -1;
			(*planes)[i][j].D = -1;
		}
	}
	else
	{
		while (++j < width + 1)
		{
			(*planes)[i][j].A = -1;
			(*planes)[i][j].B = -1;
			(*planes)[i][j].C = -1;
			(*planes)[i][j].D = -1;
		}
	}
}

static void	set_planes_with_zeros(t_plane ***planes, int width, int height)
{
	int	i;

	i = -1;
	while (++i < 4)
		process_set_planes(planes, i, width, height);
}

t_plane	**init_planes(t_cub3d *cub)
{
	t_plane	**planes;

	planes = ft_calloc(sizeof(*planes), 4);
	planes[0] = ft_calloc(sizeof(**planes), cub->map.size.y + 1);
	planes[1] = ft_calloc(sizeof(**planes), cub->map.size.y + 1);
	planes[2] = ft_calloc(sizeof(**planes), cub->map.size.x + 1);
	planes[3] = ft_calloc(sizeof(**planes), cub->map.size.x + 1);
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
	set_planes_with_zeros(&planes, cub->map.size.x, \
	cub->map.size.y);
	return (planes);
}
