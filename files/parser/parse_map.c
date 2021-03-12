/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 10:51:40 by lwourms           #+#    #+#             */
/*   Updated: 2021/03/12 22:24:55 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void		get_map_lines(t_cub3d *cub, char *line, int line_nb)
{
	t_dictionary	*mapline;
	t_list			*new_el;

	mapline = ft_calloc(sizeof(*mapline), 1);
	if (!mapline)
	{
		free(line);
		error_manager(-1, cub, NULL);
	}
	ft_bzero(mapline, sizeof(*mapline));
	if (is_valid_mapline(line) || !*line) // problem here with end of file without \n ??
	{
		mapline->key = line_nb;
		mapline->value = ft_strdup(line);
		new_el = ft_lstnew(mapline);
		if (!mapline->value || !new_el)
		{
			free(line);
			error_manager(-1, cub, NULL);
		}
		ft_lstadd_back(&cub->map.map_lines, new_el);
	}
	else
		free(mapline);
}

static void		treat_lines(const char *file, t_cub3d *cub)
{
	char		*line;
	int 		line_nb;
	int			fd;
	int			i;

	fd = open(file, O_RDONLY);
	i = 0;
	line_nb = 1;
	while (get_next_line(fd, &line)) // check -1
	{
		if (i < 8)
			cub->map.ids[i] = get_ids(cub, line, line_nb, &i);
		if ((i - 1) >= 7 && cub->map.ids[7].id != 0)
			get_map_lines(cub, line, line_nb);
		else if ((i - 1) >= 7)
		{
			free(line);
			error_manager(1, cub, NULL);
		}
		line_nb++;
		free(line);
	}
	get_map_lines(cub, line, line_nb);
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
}

t_cub3d			*parse_map(const char *file)
{
	t_cub3d		*cub;
	int			i;

	cub = init_cub(cub, 1);
	treat_lines(file, cub);
	sort_ids(cub);
	get_map(cub);
	get_resolution(cub);
	get_tex_path(cub);
	i = 6;
	while (i < 8)
		cub->map.floor.color = get_color(cub, i++);
	dprintf(1, "enemy = %s\n", cub->map.enemy[0].texture);
	dprintf(1, "enemy = %s\n", cub->map.enemy[1].texture);
	dprintf(1, "player = %d\n", cub->player.direction);
	free_cub(cub);
	return (cub);
}
