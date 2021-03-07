/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ids.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 15:37:57 by lwourms           #+#    #+#             */
/*   Updated: 2021/03/07 18:26:12 by lwourms          ###   ########.fr       */
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
		{
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

static t_ids	set_id(char *line, t_cub3d *cub)
{
	int		i;
	t_ids	id;
	
	i = 0;
	while (line[i] && ft_iswhitespace(line[i]))
		i++;
	id.id = find_id_one(i, line);
	id.id = find_id_two(i, line, id.id);
	if (is_id(cub->ids, id.id))
	{
		free_ids(cub->ids);
		error_manager(2, cub, NULL);
	}
	return (id);
}

t_ids			get_ids(t_cub3d *cub, char *line, int line_nb, int *i)
{
	t_ids ids;

	ids = set_id(line, cub);
	if (ids.id)
	{
		ids.line_nb = line_nb;
		ids.line = ft_strdup(line);
		if (!ids.line)
		{
			free_ids(cub->ids);
			error_manager(-1, cub, NULL);
		}
		*i += 1;
	}
	return (ids);
}
