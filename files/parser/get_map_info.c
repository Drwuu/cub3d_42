/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 11:11:00 by lwourms           #+#    #+#             */
/*   Updated: 2021/03/21 12:05:00 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	*fill_map(t_cub3d *cub, char *line)
{
	int *map;
	int i;
	
	map = ft_calloc(sizeof(*map), ft_strlen(line));
	if (!map)
		return (NULL);
	i = 0;
	while (line[i])
	{
		if (line[i] == '1')
			map[i] = 1;
		else
			map[i] = 0;
		i++;
	}
	return (map);
}

static void	get_map(t_cub3d *cub, t_list *maplines)
{
	int		i;

	cub->map.map = ft_calloc(sizeof(*cub->map.map), cub->map.size.y);
	if (!cub->map.map)
		error_manager(-1, cub, NULL, NULL);
	i = 0;
	while (maplines)
	{
		cub->map.map[i] = fill_map(cub, maplines->content);
		if (!cub->map.map[i])
			error_manager(-1, cub, NULL, NULL);
		maplines = maplines->next;
		i++;
	}
}

static void	get_info(int i, char c, t_cub3d *cub)
{
	if (i >= cub->map.size.x) 
		cub->map.size.x = i + 1;
	if (cub->player.direction)
		if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
			error_manager(52, cub, NULL, NULL);
	if (!cub->player.direction)
	{
		if (c == 'N')
			cub->player.direction = DIR_NO;
		else if (c == 'S')
			cub->player.direction = DIR_SO;
		else if (c == 'E')
			cub->player.direction = DIR_EA;
		else if (c == 'W')
			cub->player.direction = DIR_WE;
		cub->player.position.x = i;
		cub->player.position.y = cub->map.size.y;
	}
	if (c == '2')
		cub->map.enemy_nb++;
}

static int	check_maplines(char *lines[3], t_cub3d *cub)
{
	int i;

	i = -1;
	while (lines[1][++i])
	{
		if (!ft_char_ischars(lines[1][i], " 1"))
		{
			if (is_valid_next(lines[1], i))
			{
				if (lines[0])
					if (!is_valid_next(lines[0], i))
						return (0);
				if (lines[2])
					if (!is_valid_next(lines[2], i))
						return (0);
			}
			else
				return (0);
		}
		get_info(i, lines[1][i], cub);
	}
	return (1);
}

void		get_map_info(t_cub3d *cub)
{
	t_list	*maplines;
	char	*lines[3];

	maplines = cub->map.garbage_maplines;
	cub->map.size.y = 0;
	while (maplines)
	{
		if (maplines->previous)
			lines[0] = maplines->previous->content;
		if (maplines->next)
			lines[2] = maplines->next->content;
		lines[1] = maplines->content;
		if (!check_maplines(lines, cub))
			error_manager(51, cub, NULL, NULL);
		cub->map.size.y++;
		maplines = maplines->next;
	}
	get_map(cub, cub->map.garbage_maplines);
}