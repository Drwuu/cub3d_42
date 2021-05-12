/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 12:54:14 by lwourms           #+#    #+#             */
/*   Updated: 2021/05/12 18:54:32 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

static void	draw_process(t_cub3d *cub, t_vec3 ray_origin, int x, int y)
{
	draw_ceil(cub, ray_origin, y, x);
	draw_floor(cub, ray_origin, y, x);
	if (ray_origin.y < 0)
		draw_north(cub, ray_origin, y, x);
	else
		draw_south(cub, ray_origin, y, x);
	if (ray_origin.x > 0)
		draw_east(cub, ray_origin, y, x);
	else
		draw_west(cub, ray_origin, y, x);
	draw_sprites(cub, ray_origin, y, x);
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
			ray_origin = rotate_vector_x(thread->cub->player, thread->cub->engine.rays.vector[y][x]);
			ray_origin = rotate_vector_z(thread->cub->player, ray_origin);
			draw_process(thread->cub, ray_origin, x, y);
		}
	}
	return (NULL);
}
