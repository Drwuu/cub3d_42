/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 16:14:46 by lwourms           #+#    #+#             */
/*   Updated: 2021/03/21 18:38:35 by lwourms          ###   ########.fr       */
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

static void truc(t_cub3d *cub)
{
	t_vec3	ray_coord[600][800];
	t_plane plane[4];
	plane[0] = (t_plane){0, 1, 0, 1};
	plane[1] = (t_plane){0, 1, 0, -1};
	plane[2] = (t_plane){1, 0, 0, 1};
	plane[3] = (t_plane){1, 0, 0, -1};
	t_vec3 test;
	int		i;
	int		j;
	float	t[4];
	float	de;
	float	ratio[2];

	ratio[0] = (2 * tanf(cub->settings.FOV / 2)) / cub->window.width;
	ratio[1] = (ratio[0] * cub->window.height) / cub->window.width;
	i = 0;
	while (i < cub->window.height)
	{
		j = 0;
		while (j < cub->window.width)
		{
			ray_coord[i][j].x = (j - (cub->window.width / 2)) * ratio[0];
			ray_coord[i][j].y = -1;
			ray_coord[i][j].z = (i - (cub->window.height / 2)) * ratio[1];
			int k = -1;
			while (++k < 4)
			{
				de = plane[k].A * ray_coord[i][j].x + plane[k].B * ray_coord[i][j].y + plane[k].C * ray_coord[i][j].z;
				if (de != 0)
					t[k] = -(plane[k].A * 0 + plane[k].B * 0 + plane[k].C * 0.5f + plane[k].D) / de;
				else
					t[k] = -1;
			}
			if ((k = ft_max_t(t)) > -1)
			{
				test.x = 0 + ray_coord[i][j].x * t[k];
				test.y = 0 + ray_coord[i][j].y * t[k];
				test.z = 0.5f + ray_coord[i][j].z * t[k];
			}
			if (test.z >= 0 && test.z <= 1 && t > 0 && k > -1)
				mlx_pixel_put(cub->mlx, cub->win, j, i, 0xFFFFFF);
			else
				mlx_pixel_put(cub->mlx, cub->win, j, i, 0x000000);
			j++;
		}
		i++;
	}
}

static int	loop_game(int key, t_cub3d *cub)
{
	if (key == KEY_ESCAPE)
	{
		mlx_clear_window(cub->mlx, cub->win);
		mlx_destroy_window(cub->mlx, cub->win);
		free_cub(cub);
		exit(0);
	}
	truc(cub);
	return (0);
}

void		launch_game(t_cub3d *cub)
{
	cub->mlx = mlx_init();
	if (!cub->mlx)
		error_manager(-1, cub, NULL, NULL);
	cub->win = mlx_new_window(cub->mlx, cub->window.width, \
	cub->window.height, "CUB3D");
	if (!cub->win)
		error_manager(-1, cub, NULL, NULL);
	//create_frame(cub);
	//mlx_pixel_put(cub->mlx, cub->win, cub->window.width / 2, cub->window.height / 2, 0x00FF0000);
	mlx_key_hook(cub->win, loop_game, cub);
	mlx_loop(cub->mlx);
}
