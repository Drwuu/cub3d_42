/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 12:54:14 by lwourms           #+#    #+#             */
/*   Updated: 2021/03/31 20:46:02 by lwourms          ###   ########.fr       */
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

t_image	init_image(t_cub3d *cub)
{
	t_image	image;

	image.image = mlx_new_image(cub->mlx, cub->settings.window.width, \
	cub->settings.window.height);
	if (!image.image)
		error_manager(-1, cub, NULL, NULL);
	image.addr = mlx_get_data_addr(image.image, &image.bits_per_pixel, \
	&image.line_size, &image.endian);
	if (!image.addr)
		error_manager(-1, cub, NULL, NULL);
	return (image);
}

static void draw_wall(t_cub3d *cub)
{
	
}

void	draw(t_cub3d *cub)
{
	t_plane		plane[4];
	plane[0] = (t_plane){0, 1, 0, 1};
	plane[1] = (t_plane){0, 1, 0, -1};
	plane[2] = (t_plane){1, 0, 0, 1};
	plane[3] = (t_plane){1, 0, 0, -1};
	t_vec3 		intersect;
	t_vec3		ray;
	int		i;
	int		j;
	int 	k;
	float	tut[4];
	float	t;
	float	de;
	float	angle_rad;

	i = -1;
	float save;
	save = 0;
	while (++i < cub->settings.window.height)
	{
		j = -1;
		while (++j < cub->settings.window.width)
		{
			put_pixel(cub->image, j, i, 0x00FF00);
			ray = cub->rays.vector[i][j];
			ray = rotate_z(ray, cub->player.yaw);
			int x;
			int y;
			x = cub->player.pos.x;
			y = cub->player.pos.y;
			if (ray.x > 0)
			{
				//dprintf(1, "ray x = %f\n", ray.x);
				//dprintf(1, "ray y = %f\n", ray.y);
				while (x < cub->map.size.x)
				{
					if (cub->planes[2][x + 1].D != -1)
					{
						//dprintf(1, "East Plane in %d\n", cub->planes[2][x + 1].D);
						if (!save)
							save = -(cub->player.pos.x - cub->planes[2][x + 1].D) / ray.x; // egal = + x ? pas besoin de plan.D ?
						t = -(cub->player.pos.x - cub->planes[2][x + 1].D) / ray.x;
						if (t > 0)
						{
							save = t;
							intersect.x = cub->player.pos.x + (ray.x * save);
							intersect.y = cub->player.pos.y + (ray.y * save);
							intersect.z = cub->player.pos.z + (ray.z * save);
							if ((int)intersect.y > 0 && (int)intersect.y < cub->map.size.y && \
							intersect.z >= 0 && intersect.z <= 1)
							{
								if (cub->map.map[(int)intersect.y][(int)intersect.x] == 1)
								{
									if (intersect.z >= 0 && intersect.z <= 1)
									{
										//dprintf(1, "HIT in y = %d x = %d z = %f\n", (int)intersect.y, (int)intersect.x, intersect.z);
										put_pixel(cub->image, j, i, 0xFFFFFF);
									}
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
						//dprintf(1, "West Plane at %d in %d\n", y, cub->planes[3][x].D);
						if (!save)
							save = -(cub->player.pos.x - cub->planes[3][x].D) / ray.x; // egal = + x ? pas besoin de plan.D ?
						t = -(cub->player.pos.x - cub->planes[3][x].D) / ray.x;
						if (t > 0)
						{
							save = t;
							intersect.x = cub->player.pos.x + (ray.x * save);
							intersect.y = cub->player.pos.y + (ray.y * save);
							intersect.z = cub->player.pos.z + (ray.z * save);
							if ((int)intersect.y > 0 && (int)intersect.y < cub->map.size.y && \
							intersect.z >= 0 && intersect.z <= 1)
							{
								if (cub->map.map[(int)intersect.y][(int)intersect.x] == 1)
								{
									if (intersect.z >= 0 && intersect.z <= 1)
									{
										//dprintf(1, "HIT in y = %d x = %d z = %f\n", (int)intersect.y, (int)intersect.x, intersect.z);
										put_pixel(cub->image, j, i, 0xFFFFFF);
									}
								}
							}
						}
					}
					x--;
				}
			}
			if (ray.y < 0)
			{
				// dprintf(1, "ray x = %f\n", ray.x);
				// dprintf(1, "ray y = %f\n", ray.y);
				while (y >= 0)
				{
					if (cub->planes[0][(int)y].D != -1)
					{
						if (!save)
							save = -(cub->player.pos.y - cub->planes[0][(int)y].D) / ray.y; // egal = + x ? pas besoin de plan.D ?
						t = -(cub->player.pos.y - cub->planes[0][(int)y].D) / ray.y;
						if (t > 0)
						{
							//if (cub->planes[0][(int)y - 1].D == 0)
								//dprintf(1, "intersect in y = %f\n", intersect.y);
							save = t;
							intersect.x = cub->player.pos.x + (ray.x * save);
							intersect.y = cub->player.pos.y + (ray.y * save);
							intersect.z = cub->player.pos.z + (ray.z * save);
							if ((int)intersect.x > 0 && (int)intersect.x < cub->map.size.x && \
							intersect.z >= 0 && intersect.z <= 1)
							{
								if (cub->map.map[(int)intersect.y][(int)intersect.x] == 1)
								{
									if (intersect.z >= 0 && intersect.z <= 1)
									{
										//dprintf(1, "HIT in y = %d x = %d z = %f\n", (int)intersect.y, (int)intersect.x, intersect.z);
										put_pixel(cub->image, j, i, 0xFFFFFF);
									}
								}
							}
						}
					}
					y--;
				}
			}
			else
			{
				// dprintf(1, "ray x = %f\n", ray.x);
				// dprintf(1, "ray y = %f\n", ray.y);
				while (y < cub->map.size.y)
				{
					if (cub->planes[1][(int)y + 1].D != -1)
					{
						//dprintf(1, "East Plane in %d\n", cub->planes[2][x + 1].D);
						if (!save)
							save = -(cub->player.pos.y - cub->planes[1][(int)y + 1].D) / ray.y; // egal = + x ? pas besoin de plan.D ?
						t = -(cub->player.pos.y - cub->planes[1][(int)y + 1].D) / ray.y;
						if (t > 0)
						{
							save = t;
							intersect.x = cub->player.pos.x + (ray.x * save);
							intersect.y = cub->player.pos.y + (ray.y * save);
							intersect.z = cub->player.pos.z + (ray.z * save);
							if ((int)intersect.x > 0 && (int)intersect.x < cub->map.size.x && \
							intersect.z >= 0 && intersect.z <= 1)
							{
								if (cub->map.map[(int)intersect.y][(int)intersect.x] == 1)
								{
									if (intersect.z >= 0 && intersect.z <= 1)
									{
										//dprintf(1, "HIT in y = %d x = %d z = %f\n", (int)intersect.y, (int)intersect.x, intersect.z);
										put_pixel(cub->image, j, i, 0xFFFFFF);
									}
								}
							}
						}
					}
					y++;
				}
			}
			// k = -1;
			// while (++k < 4)
			// {
			// 	de = plane[k].A * rays.x + plane[k].B * rays.y + plane[k].C * rays.z;
			// 	tut[k] = -(plane[k].A *cub->player.pos.x + plane[k].B *cub->player.pos.y + plane[k].C *cub->player.pos.z + plane[k].D) / de;
			// 		intersect.x = cub->player.pos.x + (rays.x * tut[k]);
			// 		intersect.y =cub->player.pos.y + (rays.y * tut[k]);
			// 		intersect.z =cub->player.pos.z + (rays.z * tut[k]);
				
			// 		if (tut[k] > 0)
			// 		{
			// 			//if (intersect.z > 0)
			// 			if (intersect.z >= 0 && intersect.z <= 1)
			// 				put_pixel(cub->image, j, i, 0xFFFFFF);
			// 			//if (intersect.z < 0)
			// 				//put_pixel(cub->image, j, i, 0xFF0000);
			// 			dprintf(1, "west = %f %f %f at pixel j = %d i = %d\n", intersect.x, intersect.y, intersect.z, j, i);
			// 			dprintf(1, "A %d B %d C %d D %d\n", plane[k].A, plane[k].B, plane[k].C, plane[k].D);
			// 		}
			// }
		}
	}
}
