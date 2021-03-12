/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 11:11:00 by lwourms           #+#    #+#             */
/*   Updated: 2021/03/12 22:24:23 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	get_info(int i, char c, t_cub3d *cub)
{
	if (i > cub->map.size.x) 
		cub->map.size.x = i;
	if (c == 'N')
		cub->player.direction = DIR_NO;
	else if (c == 'S')
		cub->player.direction = DIR_SO;
	else if (c == 'E')
		cub->player.direction = DIR_EA;
	else if (c == 'W')
		cub->player.direction = DIR_WE;
	if (cub->player.direction)
	{
		cub->player.position.x = i;
		cub->player.position.y = cub->map.size.y;
	}
	if (c == '2')
		cub->map.enemy_nb++;
}

static int	check_maplines(char *previous, char *current, char *next, \
t_cub3d *cub)
{
	int i;

	i = -1;
	while (current[++i])
	{
		if (!ft_char_ischars(current[i], " 1"))
		{
			if (is_valid_next(current, i))
			{
				if (previous)
					if (!is_valid_next(previous, i))
						return (0);
				if (next)
					if (!is_valid_next(next, i))
						return (0);
			}
			else
				return (0);
		}
		get_info(i, current[i], cub);
	}
	return (1);
}

void		get_map_info(t_cub3d *cub, t_list *mapline)
{
	char	*previous;
	char	*current;
	char	*next;

	while (mapline)
	{
		previous = ((t_dictionary *)mapline->previous->content)->value;
		next = ((t_dictionary *)mapline->next->content)->value;
		current = ((t_dictionary *)mapline->content)->value;
		if (!check_maplines(previous, current, next, cub))
		{
			cub->map.map_lines = ft_lstfirst(cub->map.map_lines);
			error_manager(51, cub, NULL);
		}
		cub->map.size.y++;
		if (((t_dictionary *)mapline->content)->key == 0)
		{
			dprintf(1, "map size = x%d y%d\n", cub->map.size.x, cub->map.size.y);
			break ;
		}
		mapline = mapline->next;
	}
}