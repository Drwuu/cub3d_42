/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 12:40:08 by lwourms           #+#    #+#             */
/*   Updated: 2021/03/27 17:35:56 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include "../../includes/cub3d.h"

static t_vec3	find_nw_wall(t_cub3d *cub, int **map)
{
	t_vec3	wall_pos;
	int		i;
	int		j;

	wall_pos.z = 0;
	i = cub->player.pos.y;
	while (i >= 0)
	{
		j = cub->player.pos.x;
		while (j >= 0)
		{
			if (map[i][j] == 1)
			{
				wall_pos.x = j;
				wall_pos.y = i;
				return (wall_pos);
			}
			j--;
		}
		i--;
	}
	return ;
}

static t_vec3	find_ne_wall(t_cub3d *cub, int **map)
{
	t_vec3	wall_pos;
	int		i;
	int		j;

	wall_pos.z = 0;
	i = cub->player.pos.y;
	while (i >= 0)
	{
		j = cub->player.pos.x;
		while (j < cub->map.size.x)
		{
			if (map[i][j] == 1)
			{
				wall_pos.x = j;
				wall_pos.y = i;
				return (wall_pos);
			}
			j++;
		}
		i--;
	}
	return ;
}

static t_vec3	find_sw_wall(t_cub3d *cub, int **map)
{
	t_vec3	wall_pos;
	int		i;
	int		j;

	wall_pos.z = 0;
	i = cub->player.pos.y;
	while (i < cub->map.size.y)
	{
		j = cub->player.pos.x;
		while (j >= 0)
		{
			if (map[i][j] == 1)
			{
				wall_pos.x = j;
				wall_pos.y = i;
				return (wall_pos);
			}
			j--;
		}
		i++;
	}
	return ;
}

static t_vec3	find_se_wall(t_cub3d *cub, int **map)
{
	t_vec3	wall_pos;
	int		i;
	int		j;

	wall_pos.z = 0;
	i = cub->player.pos.y;
	while (i < cub->map.size.y)
	{
		j = cub->player.pos.x;
		while (j < cub->map.size.x)
		{
			if (map[i][j] == 1)
			{
				wall_pos.x = j;
				wall_pos.y = i;
				return (wall_pos);
			}
			j++;
		}
		i++;
	}
	return ;
}

t_vec3	get_wall_intersection(t_cub3d *cub, float direction)
{
	t_vec3	wall; // problem with **map out of array when outside of the map if no walls detected

	if (direction >= 0 && direction <= M_PI_2)
		wall = find_ne_wall(cub, cub->map.map);
	else if (direction >= -M_PI_2 && direction <= 0)
		wall = find_nw_wall(cub, cub->map.map);
	else if (direction >= M_PI_2 && direction <= M_PI)
		wall = find_se_wall(cub, cub->map.map);
	else
		wall = find_sw_wall(cub, cub->map.map);
	return (wall);
}
 */