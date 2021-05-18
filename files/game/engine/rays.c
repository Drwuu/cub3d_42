/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 18:46:54 by lwourms           #+#    #+#             */
/*   Updated: 2021/05/12 20:16:07 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

static float	get_ray_ratio(t_cub3d *cub, int is_ratio_1)
{
	float	ratio[2];
	float	rad;

	rad = ft_radian(cub->settings.fov);
	ratio[0] = (2 * tanf(rad / 2)) / cub->settings.window.width;
	ratio[1] = (2 * tanf(rad * cub->settings.window.height / \
	cub->settings.window.width / 2)) / cub->settings.window.height;
	if (!is_ratio_1)
		return (ratio[0]);
	else
		return (ratio[1]);
}

static t_vec3	get_ray(t_cub3d *cub, float interval[2], int x, int y)
{
	t_vec3	ray;

	ray.x = (x - (cub->settings.window.width / 2)) * interval[0];
	ray.y = -1;
	ray.z = -(y - (cub->settings.window.height / 2)) * interval[1];
	return (ray);
}

static void	init_rays_2(t_cub3d *cub, t_rays *ray, int width, int height)
{
	int		x;
	int		y;

	ray->dist_save = ft_calloc(sizeof(*ray->dist_save), height);
	ray->vector = ft_calloc(sizeof(*ray->vector), height);
	if (!ray->dist_save || !ray->vector)
		error_manager(-1, cub, NULL, NULL);
	y = -1;
	while (++y < height)
	{
		ray->vector[y] = ft_calloc(sizeof(**ray->vector), width);
		ray->dist_save[y] = ft_calloc(sizeof(**ray->dist_save), width);
		if (!ray->vector[y] || !ray->dist_save[y])
			error_manager(-1, cub, NULL, NULL);
		x = -1;
		while (++x < width)
		{
			ray->vector[y][x] = get_ray(cub, ray->ratio, x, y);
			ray->dist_save[y][x] = INFINITY;
		}
	}
}

void	init_rays(t_cub3d **cub)
{
	(*cub)->engine.rays.ratio[0] = get_ray_ratio(*cub, 0);
	(*cub)->engine.rays.ratio[1] = get_ray_ratio(*cub, 1);
	init_rays_2(*cub, &(*cub)->engine.rays, (*cub)->settings.window.width, \
	(*cub)->settings.window.height);
}
