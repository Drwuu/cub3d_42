/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drwuu <drwuu@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 10:51:40 by lwourms           #+#    #+#             */
/*   Updated: 2021/03/08 01:59:59 by drwuu            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void		treat_lines(const char *file, t_cub3d *cub)
{
	char		*line;
	int			fd;
	int 		line_nb;
	int			i;

	fd = open(file, O_RDONLY);
	line_nb = 1;
	i = 0;
	while (get_next_line(fd, &line))
	{
		cub->map.ids[i] = get_ids(cub, line, line_nb, &i);
		line_nb++;
		free(line);
	}
	free(line);
	close(fd);
}

static void		sort_ids(t_cub3d *cub)
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
		if (cub->map.ids[i].id == id)
		{
			save = cub->map.ids[j];
			cub->map.ids[j++] = cub->map.ids[i];
			cub->map.ids[i] = save;
			id++;
			i = 0;
			continue ;
		}
		i++;
	}
	if (id != 9)
		error_manager(1, cub, NULL);
}

t_cub3d			*parse_map(const char *file)
{
	t_cub3d		*cub;
	int			i;

	cub = init_cub(cub, 1);
	treat_lines(file, cub);
	sort_ids(cub);
	get_resolution(cub);
	get_tex_path(cub);
	i = 6;
	while (i < 8)
		cub->map.floor.color = get_color(cub, i++);
	free_cub(cub);
	return (cub);
}
