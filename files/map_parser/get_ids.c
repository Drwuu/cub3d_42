/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ids.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drwuu <drwuu@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 17:40:18 by lwourms           #+#    #+#             */
/*   Updated: 2021/02/28 20:22:01 by drwuu            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int			is_id(t_dictionary *ids, int id_key)
{
	int i;

	i = 0;
	while (i < 8)
	{
		if (ids[i].key != 0 && ids[i].key == id_key)
			return (1);
		i++;
	}
	return (0);
}

static int			find_id_p1(int i, const char *line)
{
	int key;

	key = 0;
	if (line[i] == 'R')
		key = R;
	else if (line[i] == 'N')
	{
		if (line[i + 1] && line[i + 1] == 'O')
			key = NO;
	}
	else if (line[i] == 'S')
	{
		if (line[i + 1] && line[i + 1] == 'O')
			key = SO;
		else
			key = S;
	}
	else if (line[i] == 'W')
		if (line[i + 1] && line[i + 1] == 'E')
			key = WE;
	return (key);
}

static int			find_id_p2(int i, const char *line, int key)
{
	if (line[i] == 'E')
	{
		if (line[i + 1] && line[i + 1] == 'A')
			key = EA;
	}
	else if (line[i] == 'F')
		key = F;
	else if (line[i] == 'C')
		key = C;
	return (key);
}

static t_dictionary	set_id(t_dictionary *ids, char *line, int id_index)
{
	int				i;
	t_dictionary	id;
	
	i = 0;
	while (line[i] && ft_iswhitespace(line[i]))
		i++;
	id.key = find_id_p1(i, line);
	id.key = find_id_p2(i, line, id.key);
	if (is_id(ids, id.key))
		error_manager(2, g_alloc_lst);
	return (id);
}

t_dictionary		*get_ids(int fd)
{
	t_dictionary	*ids;
	char			*line;
	int 			line_nb;
	int				i;

	alloc_to_lst((void *)&ids, sizeof(*ids), 9);
	i = 0;
	line_nb = 1;
	while (get_next_line(fd, &line))
	{
		alloc_to_lst((void *)&line, 0, 0);
		ids[i] = set_id(ids, line, i);
		if (ids[i].key)
		{
			ids[i].value = line_nb;
			ids[i++].str = line;
		}
		line_nb++;
	}
	alloc_to_lst((void *)&line, 0, 0);
	return (ids);
}
