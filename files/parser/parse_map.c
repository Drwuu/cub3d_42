/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 10:51:40 by lwourms           #+#    #+#             */
/*   Updated: 2021/03/07 18:31:26 by lwourms          ###   ########.fr       */
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
		cub->ids[i] = get_ids(cub, line, line_nb, &i);
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
		if (cub->ids[i].id == id)
		{
			save = cub->ids[j];
			cub->ids[j++] = cub->ids[i];
			cub->ids[i] = save;
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
	cub->window = get_resolution(cub);
	i = 0;
	while (++i < 6)
	{
		cub->tex_path[i - 1] = get_tex_path(cub, i);
		dprintf(1, "texture = %s\n", cub->tex_path[i - 1]);
	}
	i = 5;
	while (++i < 8)
		cub->color[i - 6] = get_color(cub, i);
	i = 0;
	dprintf(1, "color = %d\n", cub->color[0].red);
	free_cub(cub);
	return (cub);
}
