/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ids.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 15:37:57 by lwourms           #+#    #+#             */
/*   Updated: 2021/03/04 18:09:30 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int		is_id(t_ids *ids, int id)
{
	int i;

	i = 0;
	while (i < 8)
	{
		if (ids[i].id != 0 && ids[i].id == id)
			return (1);
		i++;
	}
	return (0);
}

static int		find_id_one(int i, const char *line)
{
	int id;

	id = 0;
	if (line[i] == 'R')
		id = R;
	else if (line[i] == 'N')
	{
		if (line[i + 1] && line[i + 1] == 'O')
			id = NO;
	}
	else if (line[i] == 'S')
	{
		if (line[i + 1] && line[i + 1] == 'O')
			id = SO;
		else
			id = S;
	}
	else if (line[i] == 'W')
		if (line[i + 1] && line[i + 1] == 'E')
			id = WE;
	return (id);
}

static int		find_id_two(int i, const char *line, int id)
{
	if (line[i] == 'E')
	{
		if (line[i + 1] && line[i + 1] == 'A')
			id = EA;
	}
	else if (line[i] == 'F')
		id = F;
	else if (line[i] == 'C')
		id = C;
	return (id);
}

static t_ids	set_id(t_ids *ids, char *line)
{
	int		i;
	t_ids	id;
	
	i = 0;
	while (line[i] && ft_iswhitespace(line[i]))
		i++;
	id.id = find_id_one(i, line);
	id.id = find_id_two(i, line, id.id);
	if (is_id(ids, id.id))
		error_manager(2, line);
	return (id);
}

t_ids			*get_ids(int fd, char *line)
{
	t_ids	*ids;
	int 	line_nb;
	int		i;

	init_data((void *)&ids, sizeof(*ids), 9);
	i = 0;
	line_nb = 1;
	while (get_next_line(fd, &line))
	{
		ids[i] = set_id(ids, line);
		if (ids[i].id)
		{
			ids[i].line_nb = line_nb;
			ids[i].line = line;
			i++;
		}
		line_nb++;
	}
	return (ids);
}