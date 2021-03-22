/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 19:42:53 by lwourms           #+#    #+#             */
/*   Updated: 2021/03/22 17:22:34 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int		ft_max_t(float *t)
{
	int i;
	int id;
	float mem;

	i = -1;
	mem = -1;
	while (++i < 4)
	{
		if (t[i] > mem || mem < 0)
		{
			mem = t[i];
			id = i;
		}
	}
	if (mem < 0)
		return (-1);
	else
		return (id);
}

static t_plane	create_plane(int a, int b, int c, int d)
{
	t_plane	plane;

	plane.A = a;
	plane.B = b;
	plane.C = c;
	plane.D = d;
	return (plane);
}

static float	get_ray_ratio(t_cub3d *cub, int is_ratio)
{
	float	ratio[2];
	float	rad;

	rad = ft_radian(cub->settings.FOV);
	ratio[0] = (2 * tanf(rad / 2)) / cub->window.width;
	ratio[1] = (ratio[0] * cub->window.height) / cub->window.width;
	if (!is_ratio)
		return (ratio[0]);
	else
		return (ratio[1]);
}

static t_vec3	get_ray(t_cub3d *cub, float ratio[2], int x, int y)
{
	t_vec3	ray;

	ray.x = (x - (cub->window.width / 2)) * ratio[0];
	ray.y = -1;
	ray.z = (y - (cub->window.height / 2)) * ratio[1];
	return (ray);
}

static void	init_rays(t_cub3d **cub)
{
	int			i;
	int			j;

	(*cub)->rays.ray_ratio[0] = get_ray_ratio(*cub, 0);
	(*cub)->rays.ray_ratio[1] = get_ray_ratio(*cub, 1);
	(*cub)->rays.vector = ft_calloc(sizeof(*(*cub)->rays.vector), (*cub)->window.height);
	if (!(*cub)->rays.vector)
		error_manager(-1, *cub, NULL, NULL);
	i = -1;
	while (++i < (*cub)->window.height)
	{
		(*cub)->rays.vector[i] = ft_calloc(sizeof(**(*cub)->rays.vector), \
		(*cub)->window.width);
		if (!(*cub)->rays.vector[i])
			error_manager(-1, *cub, NULL, NULL);
		j = -1;
		while (++j < (*cub)->window.width)
			(*cub)->rays.vector[i][j] = get_ray(*cub, (*cub)->rays.ray_ratio, j, i);
	}
}

void	draw(t_cub3d *cub)
{
	t_rays		rays;
	t_plane		plane[4];
	plane[0] = (t_plane){0, 1, 0, 4};
	plane[1] = (t_plane){0, 1, 0, -4};
	plane[2] = (t_plane){1, 0, 0, 1};
	plane[3] = (t_plane){1, 0, 0, -1};
	t_vec3 test;
	int		i;
	int		j;
	float	t[4];
	float	de;

	init_rays(&cub);
	rays = cub->rays;
	i = 0;
	while (i < cub->window.height)
	{
		j = 0;
		while (j < cub->window.width)
		{
			mlx_pixel_put(cub->mlx, cub->win, j, i, 0xFF0000);
			int k = -1;
			while (++k < 4)
			{
				de = plane[k].A * rays.vector[i][j].x + plane[k].B * rays.vector[i][j].y + plane[k].C * rays.vector[i][j].z;
				//if (de != 0)
					t[k] = -(plane[k].A * 0 + plane[k].B * 0 + plane[k].C * 0.5f + plane[k].D) / de;
				//else
				//	t[k] = -1;
				//if ((k = ft_max_t(t)) > -1)
				//{
					test.x = 0 + rays.vector[i][j].x * t[k];
					test.y = 0 + rays.vector[i][j].y * t[k];
					test.z = 0.5f + rays.vector[i][j].z * t[k];
				//}
				if (test.z >= 0 && test.z <= 1) //&& t[k] > 0) //&& k > -1)
					mlx_pixel_put(cub->mlx, cub->win, j, i, 0xFFFFFF);
			}
			j++;
		}
		i++;
	}
}
