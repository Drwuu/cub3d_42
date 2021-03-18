/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 10:51:40 by lwourms           #+#    #+#             */
/*   Updated: 2021/03/18 15:23:26 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void		get_map_lines(t_cub3d *cub, char **line, int fd)
{
	t_list		*new;
	int			ret;

	new = ft_lstnew(*line, STRING);
	if (!new)
		error_manager(-1, cub, *line, NULL);
	ft_lstadd_back(&cub->map.garbage_maplines, new);
	ret = 1;
	while (ret)
	{
		ret = get_next_line(fd, line);
		if (ret == -1)
			error_manager(-1, cub, *line, NULL);
		if (**line && !is_valid_mapline(*line))
			error_manager(50, cub, *line, NULL);
		if (!**line)
		{
			free(*line);
			break ;
		}
		new = ft_lstnew(*line, STRING);
		if (!new)
			error_manager(-1, cub, *line, NULL);
		ft_lstadd_back(&cub->map.garbage_maplines, new);
	}
}

static void		get_lines_to_parse(t_cub3d *cub, char **line, int fd)
{
	t_list		*new;
	int			ret;

	ret = 1;
	while (ret)
	{
		ret = get_next_line(fd, line);
		new = ft_lstnew(*line, STRING);
		if (!new || ret == -1)
			error_manager(-1, cub, *line, NULL);
		ft_lstadd_back(&cub->map.garbage_idlines, new);
		if (**line && !is_id(*line))
		{
			if (new->previous)
			{
				new->previous->next = NULL;
				free(new);
			}
			break ;
		}
	}
	if (**line && is_valid_mapline(*line))
		get_map_lines(cub, line, fd);
	else
		error_manager(3, cub, NULL, NULL);
}

t_cub3d			*parse_map(const char *file)
{
	t_cub3d		*cub;
	char		*line;
	t_list		*first_id;
	t_list		*first_map;
	int			fd;

	cub = init_cub(cub, 1);
	fd = open(file, O_RDONLY);
	get_lines_to_parse(cub, &line, fd);
	get_map_info(cub);
	check_id_lines(cub, cub->map.garbage_idlines);
	first_id = cub->map.garbage_idlines;
	first_map = cub->map.garbage_maplines;
	while (cub->map.garbage_idlines)
	{
		dprintf(1, "id line = %s\n", cub->map.garbage_idlines->content);
		cub->map.garbage_idlines = cub->map.garbage_idlines->next;
	}
	while (cub->map.garbage_maplines)
	{
		dprintf(1, "map line = %s\n", cub->map.garbage_maplines->content);
		cub->map.garbage_maplines = cub->map.garbage_maplines->next;
	}
	cub->map.garbage_idlines = first_id;
	cub->map.garbage_maplines = first_map;
	dprintf(1, "floor red color = %d\n", cub->map.floor.color.red);
	dprintf(1, "ceiling red color = %d\n", cub->map.ceiling.color.red);
	dprintf(1, "NO wall texture = %s\n", cub->map.wall_tex[0]);
	dprintf(1, "SO wall texture = %s\n", cub->map.wall_tex[1]);
	dprintf(1, "EA wall texture = %s\n", cub->map.wall_tex[2]);
	dprintf(1, "WE wall texture = %s\n", cub->map.wall_tex[3]);
	dprintf(1, "sprite texture = %s\n", cub->map.sprite_tex);
	dprintf(1, "size x = %d\n", cub->map.size.x);
	dprintf(1, "size y = %d\n", cub->map.size.y);
	dprintf(1, "player x pos = %d\n", cub->player.position.x);
	dprintf(1, "player y pos = %d\n", cub->player.position.y);
	dprintf(1, "player direction = %d\n", cub->player.direction);
	dprintf(1, "enemies = %d\n", cub->map.enemy_nb);
	free_cub(cub);
	close(fd);
	return (cub);
}
