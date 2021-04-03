/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 12:54:14 by lwourms           #+#    #+#             */
/*   Updated: 2021/04/03 20:21:58 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	put_pixel(t_image image, int x, int y, unsigned int color)
{
	char	*pixel;

	pixel = image.addr + (y * image.line_size + x * \
	(image.bits_per_pixel / 8));
	((unsigned int *)pixel)[0] = color;
}

void	init_user_mlx_image(t_cub3d *cub)
{
	cub->image.image = mlx_new_image(cub->mlx, cub->settings.window.width, \
	cub->settings.window.height);
	if (!cub->image.image)
		error_manager(-1, cub, NULL, NULL);
	cub->image.addr = mlx_get_data_addr(cub->image.image, \
	&cub->image.bits_per_pixel, &cub->image.line_size, &cub->image.endian);
	if (!cub->image.addr)
		error_manager(-1, cub, NULL, NULL);
}

void	draw_pixel(t_cub3d *cub, int i, int j, unsigned int wall_color)
{
	if (cub->rays.inters.z > 1)
		put_pixel(cub->image, j, i, 0x0000AA);
	else if (cub->rays.inters.z < 0)
		put_pixel(cub->image, j, i, 0x8800AA);
	else
		put_pixel(cub->image, j, i, wall_color);
}

void	draw(t_cub3d *cub)
{
	int		i;
	int		j;
	t_vec3	ray_origin;

	i = -1;
	while (++i < cub->settings.window.height)
	{
		j = -1;
		while (++j < cub->settings.window.width)
		{
			ray_origin = rotate_z(cub->rays.vector[i][j], cub->player.yaw);
			cub->rays.dist_save = INFINITY;
			if (ray_origin.y < 0)
				trace_north_ray(cub, ray_origin, i, j);
			else
				trace_south_ray(cub, ray_origin, i, j);
			if (ray_origin.x > 0)
				trace_east_ray(cub, ray_origin, i, j);
			else
				trace_west_ray(cub, ray_origin, i, j);
		}
	}
}

void	old_draw(t_cub3d *cub)
{
	t_vec3 	intersect;
	t_vec3	ray;
	int		i;
	int		j;
	float	t;
	float	save;
	int x;
	int y;
	
	i = -1;
	while (++i < cub->settings.window.height)
	{
		j = -1;
		while (++j < cub->settings.window.width)
		{
			ray = rotate_z(cub->rays.vector[i][j], cub->player.yaw);
			x = cub->player.pos.x;
			y = cub->player.pos.y;
			save = INFINITY;
			if (ray.y < 0) // verif quand c'est egal à zero
			{
				while (y > 0)
				{
					if (cub->planes[0][y].D != -1)
					{
						t = -(cub->player.pos.y - cub->planes[0][y].D) / ray.y;
						if (t >= 0)
						{
							intersect.x = cub->player.pos.x + (ray.x * t);
							intersect.y = cub->player.pos.y + (ray.y * t);
							intersect.z = cub->player.pos.z + (ray.z * t);
							if (intersect.y > 0 && intersect.y <= cub->map.size.y && \
							intersect.x >= 0 && intersect.x < cub->map.size.x - 1)
							{
								if (cub->map.map[(int)(intersect.y + .0001f) - 1][(int)(intersect.x + .0001f)] == 1 && t < save)
								{
									save = t;
									if (intersect.z > 1)
										put_pixel(cub->image, j, i, 0x0000AA);
									else if (intersect.z < 0)
										put_pixel(cub->image, j, i, 0x8800AA);
									else
										put_pixel(cub->image, j, i, 0xFFFF00);
								}
							}
						}
					}
					y--;
				}
			}
			else
			{
				while (y < cub->map.size.y)
				{
					if (cub->planes[1][y].D != -1)
					{
						t = -(cub->player.pos.y - cub->planes[1][y].D) / ray.y;
						if (t >= 0)
						{
							intersect.x = cub->player.pos.x + (ray.x * t);
							intersect.y = cub->player.pos.y + (ray.y * t);
							intersect.z = cub->player.pos.z + (ray.z * t);
							if (intersect.y >= cub->player.pos.y && intersect.y < cub->map.size.y && intersect.x > 0 && intersect.x < cub->map.size.x - 1)
							{
								if (cub->map.map[(int)(intersect.y + .0001f)][(int)(intersect.x + .0001f)] == 1 && t < save)
								{
									save = t;
									if (intersect.z > 1)
										put_pixel(cub->image, j, i, 0x0000AA);
									else if (intersect.z < 0)
										put_pixel(cub->image, j, i, 0x8800AA);
									else
										put_pixel(cub->image, j, i, 0xFFFFFF);
								}
							}
						}
					}
					y++;
				}
			}
			if (ray.x > 0)
			{
				while (x < cub->map.size.x)
				{
					if (cub->planes[2][x].D != -1)
					{
						t = -(cub->player.pos.x - cub->planes[2][x].D) / ray.x;
						if (t >= 0)
						{
							intersect.x = cub->player.pos.x + (ray.x * t);
							intersect.y = cub->player.pos.y + (ray.y * t);
							intersect.z = cub->player.pos.z + (ray.z * t);
							if (intersect.x >= cub->player.pos.x && intersect.x < cub->map.size.x && intersect.y > 0 && intersect.y < cub->map.size.y  - 1)
							{
								if (cub->map.map[(int)(intersect.y + .0001f)][(int)(intersect.x + .0001f)] == 1 && t < save)
								{
									save = t;
									if (intersect.z > 1)
										put_pixel(cub->image, j, i, 0x0000AA);
									else if (intersect.z < 0)
										put_pixel(cub->image, j, i, 0x8800AA);
									else
										put_pixel(cub->image, j, i, 0x00FFFF);
								}
							}
						}
					}
					x++;
				}
			}
			else
			{
				while (x > 0)
				{
					if (cub->planes[3][x].D != -1)
					{
						t = -(cub->player.pos.x - cub->planes[3][x].D) / ray.x;
						if (t >= 0)
						{
							intersect.x = cub->player.pos.x + (ray.x * t);
							intersect.y = cub->player.pos.y + (ray.y * t);
							intersect.z = cub->player.pos.z + (ray.z * t);
							if (intersect.x > 0 && intersect.x <= cub->player.pos.x && intersect.y > 0 && intersect.y < cub->map.size.y)
							{
								if (cub->map.map[(int)(intersect.y + .0001f)][(int)(intersect.x + .0001f) - 1] == 1 && t < save)
								{
									save = t;
									if (intersect.z > 1)
										put_pixel(cub->image, j, i, 0x0000AA);
									else if (intersect.z < 0)
										put_pixel(cub->image, j, i, 0x8800AA);
									else
										put_pixel(cub->image, j, i, 0xFF00FF);
								}
							}
						}
					}
					x--;
				}
			}
		}
	}
}
