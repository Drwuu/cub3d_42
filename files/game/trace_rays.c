/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_rays.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 18:46:54 by lwourms           #+#    #+#             */
/*   Updated: 2021/04/03 20:47:24 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static t_vec3	get_intersect(t_cub3d *cub, t_vec3 origin, float distance)
{
	t_vec3	intersect;

	intersect.x = cub->player.pos.x + (origin.x * distance);
	intersect.y = cub->player.pos.y + (origin.y * distance);
	intersect.z = cub->player.pos.z + (origin.z * distance);
	return (intersect);
}

void	trace_north_ray(t_cub3d *cub, t_vec3 ray_origin, int i, int j)
{
	float	dist;
	int		y;

	y = cub->player.pos.y + 1;
	while (--y > 0)
	{
		if (cub->planes[0][y].D == -1)
			continue ;
		dist = -(cub->player.pos.y - cub->planes[0][y].D) / ray_origin.y;
		if (dist < 0)
			continue ;
		cub->rays.inters = get_intersect(cub, ray_origin, dist);
		if (cub->rays.inters.y > 0 && cub->rays.inters.y <= cub->player.pos.y \
		&& cub->rays.inters.x >= 0 && cub->rays.inters.x < cub->map.size.x - 1 \
		&& cub->map.map[(int)cub->planes[0][y].D - 1] \
		[(int)(cub->rays.inters.x)] == 1 && dist < \
		cub->rays.dist_save)
		{
			cub->rays.dist_save = dist;
			draw_pixel(cub, i, j, 0xFFFF00);
			break ;
		}
	}
}

void	trace_south_ray(t_cub3d *cub, t_vec3 ray_origin, int i, int j)
{
	float	dist;
	int		y;

	y = cub->player.pos.y - 1;
	while (++y < cub->map.size.y)
	{
		if (cub->planes[1][y].D == -1)
			continue ;
		dist = -(cub->player.pos.y - cub->planes[1][y].D) / ray_origin.y;
		if (dist < 0)
			continue ;
		cub->rays.inters = get_intersect(cub, ray_origin, dist);
		if (cub->rays.inters.y >= cub->player.pos.y && \
		cub->rays.inters.y < cub->map.size.y \
		&& cub->rays.inters.x > 0 && cub->rays.inters.x < cub->map.size.x - 1 \
		&& cub->map.map[(int)cub->planes[1][y].D] \
		[(int)(cub->rays.inters.x)] == 1 && dist < \
		cub->rays.dist_save)
		{
			cub->rays.dist_save = dist;
			draw_pixel(cub, i, j, 0xFFFFFF);
			break ;
		}
	}
}

void	trace_east_ray(t_cub3d *cub, t_vec3 ray_origin, int i, int j)
{
	float	dist;
	int		x;

	x = cub->player.pos.x - 1;
	while (++x < cub->map.size.x)
	{
		if (cub->planes[2][x].D == -1)
			continue ;
		dist = -(cub->player.pos.x - cub->planes[2][x].D) / ray_origin.x;
		if (dist < 0)
			continue ;
		cub->rays.inters = get_intersect(cub, ray_origin, dist);
		if (cub->rays.inters.y > 0 && cub->rays.inters.y < cub->map.size.y - 1 \
		&& cub->rays.inters.x >= cub->player.pos.x && \
		cub->rays.inters.x < cub->map.size.x && \
		cub->map.map[(int)(cub->rays.inters.y)] \
		[(int)cub->planes[2][x].D] == 1 && dist < \
		cub->rays.dist_save)
		{
			cub->rays.dist_save = dist;
			draw_pixel(cub, i, j, 0x00FFFF);
			break ;
		}
	}
}

void	trace_west_ray(t_cub3d *cub, t_vec3 ray_origin, int i, int j)
{
	float	dist;
	int		x;

	x = cub->player.pos.x + 1;
	while (--x > 0)
	{
		if (cub->planes[3][x].D == -1)
			continue ;
		dist = -(cub->player.pos.x - cub->planes[3][x].D) / ray_origin.x;
		if (dist < 0)
			continue ;
		cub->rays.inters = get_intersect(cub, ray_origin, dist);
		if (cub->rays.inters.y > 0 && cub->rays.inters.y < cub->map.size.y \
		&& cub->rays.inters.x > 0 &&  cub->rays.inters.x <= cub->player.pos.x \
		&& cub->map.map[(int)(cub->rays.inters.y)] \
		[(int)cub->planes[3][x].D - 1] == 1 && dist < \
		cub->rays.dist_save)
		{
			cub->rays.dist_save = dist;
			draw_pixel(cub, i, j, 0xFF00FF);
			//dprintf(1, "yaw = %f\n", cub->player.yaw);
			//dprintf(1, "pixel i = %d, j = %d\n", i, j);
			break ;
		}
	}
}
