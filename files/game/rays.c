/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 19:42:53 by lwourms           #+#    #+#             */
/*   Updated: 2021/03/21 19:09:04 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static t_vec3	get_ray(t_cub3d *cub, int width, int height, float ratio[2])
{
	t_vec3	ray;

	ray.x = (width - (cub->window.width / 2)) * ratio[0];
	ray.y = -1;
	ray.z = (height - (cub->window.height / 2)) * ratio[1];
	return (ray);
}

static const float	*get_ratio(t_cub3d *cub)
{
	float	ratio[2];

	ratio[0] = (2 * tanf(cub->settings.FOV / 2)) / cub->window.width;
	ratio[1] = (ratio[0] * cub->window.height) / cub->window.width;
	return (ratio);
}

static t_plane	**init_rays(t_cub3d *cub)
{
	t_ray	**rays;
	float	ratio[2];
	int		i;

	rays = ft_calloc(sizeof(*rays), cub->window.height);
	ratio = get_ratio(cub);
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
		rays[i][j] = get_ray(cub, j, i, ratio)
		i++;
	}
}



static t_vec3	**get_intersec(t_cub3d *cub, t_vec3 **ray)
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

t_ray	**build_rays(t_cub3d *cub)
{
	t_ray	**rays;
	float	*ray_ratio;

	rays = init_rays(cub);
	ray_ratio = get_ray_ratio(cub);
	rays.ray_coord = get_ray_coord(cub, ray_ratio);
}
