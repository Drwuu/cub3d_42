/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 10:51:40 by lwourms           #+#    #+#             */
/*   Updated: 2021/03/07 11:19:37 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static t_ids	*sort_ids(t_ids *ids, t_cub3d *cub)
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
	if (id != 9)
		error_manager(1, cub, NULL);
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
	cub->ids = sort_ids(cub->ids, cub);
	cub->window = get_resolution(cub);
	i = 0;
	while (++i < 6)
		cub->tex_path[i - 1] = get_tex_path(cub, i);
	i = 5;
	while (++i < 8)
		cub->color[i - 6] = get_color(cub, i);
	i = 0;
	free_cub(cub);
	return (cub);
}