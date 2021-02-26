/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ids.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 17:40:18 by lwourms           #+#    #+#             */
/*   Updated: 2021/02/26 17:40:00 by lwourms          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static t_dictionary	check_first_ids(t_dictionary id, int i, const char *line)
{
	if (line[i] == 'R')
		id.key = R;
	else if (line[i] == 'N')
	{
		if (line[i + 1] && line[i + 1] == 'O')
			id.key = NO;
	}
	else if (line[i] == 'S')
	{
		if (line[i + 1] && line[i + 1] == 'O')
			id.key = SO;
		else
			id.key = S;
	}
	else if (line[i] == 'W')
	{
		if (line[i + 1] && line[i + 1] == 'E')
			id.key = WE;
	}
	return (id);
}

static t_dictionary	check_second_ids(t_dictionary id, int i, const char *line)
{
	if (line[i] == 'E')
	{
		if (line[i + 1] && line[i + 1] == 'A')
			id.key = EA;
	}
	else if (line[i] == 'F')
		id.key = F;
	else if (line[i] == 'C')
		id.key = C;
	return (id);
}

t_dictionary		get_id(const char *line)
{
	int				i;
	int				ret;
	t_dictionary	id;

	i = 0;
	id.key = 0;
	while (ft_iswhitespace(line[i]))
		i++;
	id = check_first_ids(id, i, line);
	id = check_second_ids(id, i, line);
	return (id);
}
