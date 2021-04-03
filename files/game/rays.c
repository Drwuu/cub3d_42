/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 18:46:54 by lwourms           #+#    #+#             */
/*   Updated: 2021/04/03 18:30:12 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static float	get_ray_interval(t_cub3d *cub, int is_interval)
{
	float	interval[2];
	float	rad;

	rad = ft_radian(cub->settings.fov);
	interval[0] = (2 * tanf(rad / 2)) / cub->settings.window.width;
	interval[1] = (2 * tanf(rad * cub->settings.window.height / \
	cub->settings.window.width / 2)) / cub->settings.window.height;
	if (!is_interval)
		return (interval[0]);
	else
		return (interval[1]);
}

static t_vec3	get_ray(t_cub3d *cub, float interval[2], int x, int y)
{
	t_vec3	ray;

	ray.x = (x - (cub->settings.window.width / 2)) * interval[0];
	ray.y = -1;
	ray.z = -(y - (cub->settings.window.height / 2)) * interval[1];
	return (ray);
}

void	init_rays(t_cub3d **cub)
{
	int			i;
	int			j;

	(*cub)->rays.ray_interval[0] = get_ray_interval(*cub, 0);
	(*cub)->rays.ray_interval[1] = get_ray_interval(*cub, 1);
	(*cub)->rays.vector = ft_calloc(sizeof(*(*cub)->rays.vector), \
	(*cub)->settings.window.height);
	if (!(*cub)->rays.vector)
		error_manager(-1, *cub, NULL, NULL);
	i = -1;
	while (++i < (*cub)->settings.window.height)
	{
		(*cub)->rays.vector[i] = ft_calloc(sizeof(**(*cub)->rays.vector), \
		(*cub)->settings.window.width);
		if (!(*cub)->rays.vector[i])
			error_manager(-1, *cub, NULL, NULL);
		j = -1;
		while (++j < (*cub)->settings.window.width)
		{
			(*cub)->rays.vector[i][j] = get_ray(*cub, \
			(*cub)->rays.ray_interval, j, i);
		}
	}
}