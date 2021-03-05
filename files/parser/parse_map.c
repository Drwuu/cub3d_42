/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drwuu <drwuu@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 10:51:40 by lwourms           #+#    #+#             */
/*   Updated: 2021/03/05 18:31:22 by drwuu            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static t_ids	*sort_ids(t_ids *ids)
{
	int			i;
	int			j;
	int			id;
	t_ids		save;

	i = 0;
	j = 0;
	id = 1;
	while (i < 8)
	{
		if (ids[i].id == id)
		{
			save = ids[j];
			ids[j++] = ids[i];
			ids[i] = save;
			id++;
			i = 0;
			continue ;
		}
		i++;
	}
	return (ids);
}

t_cub3d			*parse_map(char *file)
{
	t_cub3d		*cub;
	char		*line;
	int			fd;
	int			i;

	fd = open("map.cub", O_RDONLY);
	cub = init_data(cub, cub, sizeof(*cub), 1);
	cub->ids = get_ids(fd, line, cub);
	cub->ids = sort_ids(cub->ids);
	cub->window = get_resolution(cub);
	i = 0;
	while (++i < 6)
		cub->tex_path[i - 1] = get_tex_path(cub, i);
	dprintf(1, "height = %d\n", cub->window.height);
	dprintf(1, "width = %d\n", cub->window.width);
	i = 0;
	while (i < 8)
	{
		dprintf(1, "id = %s\n", get_enum_name(cub->ids[i].id));
		dprintf(1, "id str = %s\n", cub->ids[i++].line);
	}
	free_cub(cub);
	return (cub);
}