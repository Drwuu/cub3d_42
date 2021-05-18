/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 10:51:40 by lwourms           #+#    #+#             */
/*   Updated: 2021/05/12 20:42:10 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	get_map_lines(t_cub3d *cub, char **line, int fd)
{
	t_list		*new;
	int			ret;

	new = ft_lstnew(*line, STRING);
	if (!new)
		error_manager(-1, cub, *line, NULL);
	ft_lstadd_back(&cub->map.maplines, new);
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
		ft_lstadd_back(&cub->map.maplines, new);
	}
}

static void	get_lines_to_parse(t_cub3d *cub, char **line, int fd)
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
		ft_lstadd_back(&cub->map.idlines, new);
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

void	parse_map(const char *file, t_cub3d *cub)
{
	char	*line;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		error_manager(-3, cub, NULL, NULL);
	get_lines_to_parse(cub, &line, fd);
	close(fd);
	check_id_lines(cub, cub->map.idlines);
	get_map_info(cub);
}
