/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 19:42:53 by lwourms           #+#    #+#             */
/*   Updated: 2021/03/21 17:08:27 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/* static t_plane	create_plane(t_cub3d *cub)
{
	t_plane	plane;

	plane.A = 1;
	plane.B = 0;
	plane.C = 0;
	plane.D = 1;
}

static t_plane	**init_rays(t_cub3d *cub)
{
	t_ray	**rays;
	int		i;

	rays = ft_calloc(sizeof(*rays), cub->window.height);
	if (!rays)
		error_manager(-1, cub, NULL, NULL);
	while (i < cub->window.height)
	{
		rays[i] = ft_calloc(sizeof(**rays), cub->window.width);
		if (!rays[i])
		{
			i = -1;
			while (++i < cub->window.height)
				if (rays[i])
					free(rays[i]);
			error_manager(-1, cub, NULL, NULL);
		}
		i++;
	}
}

static t_vec3	**get_ray_coord(t_cub3d *cub, float ratio[2])
{
	t_vec3	**ray_coord;
	int		i;
	int		j;

	ray_coord = ft_calloc(sizeof(*ray_coord), cub->window.height);
	if (!ray_coord)
		error_manager(-1, cub, NULL, NULL);
	i = 0;
	while (i < cub->window.height)
	{
		ray_coord[i] = ft_calloc(sizeof(**ray_coord), cub->window.width);
		if (!ray_coord[i])
			error_manager(-1, cub, NULL, NULL);
		j = 0;
		while (j < cub->window.width)
		{
			ray_coord[i][j].x = (i - (cub->window.width / 2)) * ratio[0];
			ray_coord[i][j].y = -1;
			ray_coord[i][j].z = (j - (cub->window.height / 2)) * ratio[1];
			j++;
		}
		i++;
	}
	return (ray_coord);
}

static const float	*get_ray_ratio(t_cub3d *cub)
{
	float	ratio[2];

	ratio[0] = (2 * tanf(cub->settings.FOV / 2)) / cub->window.width;
	ratio[1] = (ratio[0] * cub->window.height) / cub->window.width;
	return (ratio);
}

static t_vec3	**get_distance_until_intersec(t_cub3d *cub, t_vec3 **ray)
{
	t_vec3	distance;
	int		i;
	
	i = 0;
	while (i < cub->window.height)
	{
		ra
	}
	return (distance);
}

void	build_screen(t_cub3d *cub)
{
	t_engine	engine;

	engine.ray_ratio = get_ray_ratio(cub);
	engine.ray_coord = get_ray_coord(cub, engine.ray_ratio);
} */
