/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 12:54:14 by lwourms           #+#    #+#             */
/*   Updated: 2021/04/10 18:11:47 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

unsigned int	get_pixel_color(t_cub3d *cub, t_image texture, \
t_vec3 intersect, int is_depth)
{
	float	depth_percent;
	float	h_percent;
	float	w_percent;

	if (intersect.z > 1)
		return (0x0000AA);
	else if (intersect.z < 0)
		return (0x8800AA);
	depth_percent = intersect.y - (int)intersect.y;
	w_percent = intersect.x - (int)intersect.x;
	h_percent = intersect.z;
	if (h_percent >= 0 && h_percent < 1)
	{
		if (is_depth && depth_percent > 0 && depth_percent < 1)
			return (texture.addr[(int)(depth_percent * texture.width) \
			+ (int)(h_percent * texture.height) * texture.width]);
		else if (w_percent > 0 && w_percent < 1)
			return (texture.addr[(int)(w_percent * texture.width) \
			+ (int)(h_percent * texture.height) * texture.width]);
	}
	return (0);
}

void	draw_pixel(t_image game_image, int i, int j, unsigned int color)
{
	char			*dst;

	dst = (char *)game_image.addr + (i * game_image.line_size + j * \
	(game_image.bits_per_pixel / 8));
	((unsigned int *)dst)[0] = color;
}

void	draw(t_cub3d *cub)
{
	t_vec3	ray_origin;
	int		y;
	int		x;

	y = -1;
	while (++y < cub->settings.window.height)
	{
		x = -1;
		while (++x < cub->settings.window.width)
		{
			cub->engine.rays.dist_save[y][x] = INFINITY;
			ray_origin = rotate_z(cub->player, cub->engine.rays.vector[y][x]);
			if (ray_origin.y < 0)
				draw_north(cub, ray_origin, y, x);
			else
				draw_south(cub, ray_origin, y, x);
			if (ray_origin.x > 0)
				draw_east(cub, ray_origin, y, x);
			else
				draw_west(cub, ray_origin, y, x);
		}
	}
}

void	*draw_thread(void *datas)
{
	t_thread	*thread;
	t_vec3		ray_origin;
	int			y;
	int			x;

	thread = datas;
	y = thread->start - 1;
	while (++y < thread->end)
	{
		x = -1;
		while (++x < thread->cub->settings.window.width)
		{
			thread->cub->engine.rays.dist_save[y][x] = INFINITY;
			ray_origin = rotate_z(thread->cub->player, thread->cub->engine.rays.vector[y][x]);
			if (ray_origin.y < 0)
				draw_north(thread->cub, ray_origin, y, x);
			else
				draw_south(thread->cub, ray_origin, y, x);
			if (ray_origin.x > 0)
				draw_east(thread->cub, ray_origin, y, x);
			else
				draw_west(thread->cub, ray_origin, y, x);
		}
	}
	return (NULL);
}
