/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 18:46:54 by lwourms           #+#    #+#             */
/*   Updated: 2021/05/12 18:53:03 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

void	draw_ceil(t_cub3d *cub, t_vec3 ray_origin, int i, int j)
{
	t_vec3	intersect;
	float	dist;

		dist = -(cub->player.pos.z - 1) / ray_origin.z;
		if (dist < 0 || dist > cub->engine.rays.dist_save[i][j])
			return ;
		intersect = get_intersect(cub, ray_origin, dist);
		if (cub->map.texture[T_CEIL])
			draw_pixel(cub->engine.game_image, i, j, get_cf_color( \
				cub->engine.texture[T_CEIL], intersect));
		else
			draw_pixel(cub->engine.game_image, i, j, cub->map.ceiling.color);
		cub->engine.rays.dist_save[i][j] = dist;
}

void	draw_floor(t_cub3d *cub, t_vec3 ray_origin, int i, int j)
{
	t_vec3	intersect;
	float	dist;

		dist = -cub->player.pos.z / ray_origin.z;
		if (dist < 0 || dist > cub->engine.rays.dist_save[i][j])
			return ;
		intersect = get_intersect(cub, ray_origin, dist);
		if (cub->map.texture[T_FLOOR])
			draw_pixel(cub->engine.game_image, i, j, get_cf_color( \
				cub->engine.texture[T_FLOOR], intersect));
		else
			draw_pixel(cub->engine.game_image, i, j, cub->map.floor.color);
		cub->engine.rays.dist_save[i][j] = dist;
}

void	draw_north(t_cub3d *cub, t_vec3 ray_origin, int i, int j)
{
	t_vec3	intersect;
	float	dist;
	int		y;

	y = cub->player.pos.y + 1;
	while (--y > 0 && y < cub->map.size.y)
	{
		if (cub->engine.planes[0][y].D == -1)
			continue ;
		dist = -(cub->player.pos.y - cub->engine.planes[0][y].D) / ray_origin.y;
		if (dist < 0 || dist > cub->engine.rays.dist_save[i][j])
			continue ;
		intersect = get_intersect(cub, ray_origin, dist);
		if (intersect.z > 1 || intersect.z < 0)
			continue ;
		if (is_intersect_north(cub, intersect, \
			(int)cub->engine.planes[0][y].D - 1))
		{
			cub->engine.rays.dist_save[i][j] = dist;
			draw_pixel(cub->engine.game_image, i, j, \
			get_pixel_color(cub->engine.texture[T_NORTH], intersect, 0));
			break ;
		}
	}
}

void	draw_south(t_cub3d *cub, t_vec3 ray_origin, int i, int j)
{
	t_vec3	intersect;
	float	dist;
	int		y;

	y = cub->player.pos.y - 1;
	while (++y < cub->map.size.y && y > 0)
	{
		if (cub->engine.planes[1][y].D == -1)
			continue ;
		dist = -(cub->player.pos.y - cub->engine.planes[1][y].D) / ray_origin.y;
		if (dist < 0 || dist > cub->engine.rays.dist_save[i][j])
			continue ;
		intersect = get_intersect(cub, ray_origin, dist);
		if (intersect.z > 1 || intersect.z < 0)
			continue;
		if (is_intersect_south(cub, intersect, (int)cub->engine.planes[1][y].D))
		{
			cub->engine.rays.dist_save[i][j] = dist;
			draw_pixel(cub->engine.game_image, i, j, \
			get_pixel_color(cub->engine.texture[T_SOUTH], intersect, 0));
			break ;
		}
	}
}

void	draw_east(t_cub3d *cub, t_vec3 ray_origin, int i, int j)
{
	t_vec3	intersect;
	float	dist;
	int		x;

	x = cub->player.pos.x - 1;
	while (++x < cub->map.size.x && x > 0)
	{
		if (cub->engine.planes[2][x].D == -1)
			continue ;
		dist = -(cub->player.pos.x - cub->engine.planes[2][x].D) / ray_origin.x;
		if (dist < 0 || dist > cub->engine.rays.dist_save[i][j])
			continue ;
		intersect = get_intersect(cub, ray_origin, dist);
		if (intersect.z > 1 || intersect.z < 0)
			continue;
		if (is_intersect_east(cub, intersect, (int)cub->engine.planes[2][x].D))
		{
			cub->engine.rays.dist_save[i][j] = dist;
			draw_pixel(cub->engine.game_image, i, j, \
			get_pixel_color(cub->engine.texture[T_EAST], intersect, 1));
			break ;
		}
	}
}

void	draw_west(t_cub3d *cub, t_vec3 ray_origin, int i, int j)
{
	t_vec3	intersect;
	float	dist;
	int		x;

	x = cub->player.pos.x + 1;
	while (--x > 0 && x < cub->map.size.x)
	{
		if (cub->engine.planes[3][x].D == -1)
			continue ;
		dist = -(cub->player.pos.x - cub->engine.planes[3][x].D) / ray_origin.x;
		if (dist < 0 || dist > cub->engine.rays.dist_save[i][j])
			continue ;
		intersect = get_intersect(cub, ray_origin, dist);
		if (intersect.z > 1 || intersect.z < 0)
			continue;
		if (is_intersect_west(cub, intersect, \
			(int)cub->engine.planes[3][x].D - 1))
		{
			cub->engine.rays.dist_save[i][j] = dist;
			draw_pixel(cub->engine.game_image, i, j, \
			get_pixel_color(cub->engine.texture[T_WEST], intersect, 1));
			break ;
		}
	}
}
