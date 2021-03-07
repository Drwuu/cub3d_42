/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ids.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 15:37:57 by lwourms           #+#    #+#             */
/*   Updated: 2021/03/07 14:25:21 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int		is_id(t_ids *ids, int id)
{
	int i;

	i = 0;
	while (i < 8)
	{
		dprintf(1, "goku\n");
		if (ids[i].id != 0 && ids[i].id == id)
		{
			dprintf(1, "id %d = %d\n", i, ids[i].id);
			return (1);
		}
		i++;
	}
	return (0);
}

static int		find_id_one(int i, const char *line)
{
	int id;

	id = 0;
	if (line[i] == 'R' && ft_iswhitespace(line[i + 1]))
		id = R;
	else if (line[i] == 'N')
	{
		if (line[i + 1] == 'O' && ft_iswhitespace(line[i + 2]))
			id = NO;
	}
	else if (line[i] == 'S')
	{
		if (line[i + 1] == 'O' && ft_iswhitespace(line[i + 2]))
			id = SO;
		else if (line[i + 1] && ft_iswhitespace(line[i + 1]))
			id = S;
		dprintf(1, "line = %c\n", line[i]);
	}
	else if (line[i] == 'W')
		if (line[i + 1] == 'E' && ft_iswhitespace(line[i + 2]))
			id = WE;
	return (id);
}

static int		find_id_two(int i, const char *line, int id)
{
	if (line[i] == 'E')
	{
		if (line[i + 1] == 'A' && ft_iswhitespace(line[i + 2]))
			id = EA;
	}
	else if (line[i] == 'F' && ft_iswhitespace(line[i + 1]))
		id = F;
	else if (line[i] == 'C' && ft_iswhitespace(line[i + 1]))
		id = C;
	return (id);
}

static t_ids	set_id(t_ids *ids, char *line, t_cub3d *cub)
{
	int		i;
	t_ids	id;
	
	i = 0;
	while (line[i] && ft_iswhitespace(line[i]))
		i++;
	id.id = find_id_one(i, line);
	id.id = find_id_two(i, line, id.id);
	dprintf(1, "vegeta\n");
	if (is_id(ids, id.id))
		error_manager(2, cub, NULL);
	return (id);
}

t_ids			*get_ids(int fd, char *line, t_cub3d *cub)
{
	t_ids	*ids;
	int 	line_nb;
	int		i;

	ids = init_data(ids, cub, sizeof(*ids), 9);
	i = 0;
	line_nb = 1;
	while (get_next_line(fd, &line))
	{
		ids[i] = set_id(ids, line, cub);
		if (ids[i].id)
		{
			ids[i].line_nb = line_nb;
			ids[i].line = ft_strdup(line);
			if (!ids[i].line)
				error_manager(-1, cub, NULL);
			i++;
		}
		free(line);
		line_nb++;
	}
	free(line);
	return (ids);
}
