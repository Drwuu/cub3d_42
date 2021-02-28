/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 17:40:18 by lwourms           #+#    #+#             */
/*   Updated: 2021/02/27 19:00:24 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	get_line_mapinfos(const char *line)
{
	int		i;

	i = 0;
	if (!line[i] || !line)
		error_manager(1);
	while (ft_iswhitespace(line[i]))
		i++;
	if (!line[i])
		error_manager(1);
	//if ()
	get_resolution(line, &i);
}

int		parse_map(const char *file)
{
	t_dictionary	*ids;
	char			*line;
	int				fd;
	int				i;

	fd = open(file, O_RDONLY);
	ids = get_ids(fd, line);
	i = 0;
	while (i < 8)
	{
		printf("id %s line %d\n", get_enum_name(ids[i].key), ids[i].value);
		i++;
	}
	/* while (get_next_line(fd, &line))
	{
		get_map_infos(line);
		free(line);
	} */
	//free(line);
	free(ids);
	close(fd);
	return (1);
}


