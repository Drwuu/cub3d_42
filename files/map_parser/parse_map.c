/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drwuu <drwuu@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 17:40:18 by lwourms           #+#    #+#             */
/*   Updated: 2021/02/28 20:20:31 by drwuu            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	get_line_mapinfos(const char *line)
{
	int		i;

	i = 0;
	if (!line[i] || !line)
		error_manager(1, NULL);
	while (ft_iswhitespace(line[i]))
		i++;
	if (!line[i])
		error_manager(1, g_alloc_lst);
	//if ()
	get_resolution(line, &i);
}

int		parse_map(const char *file)
{
	t_dictionary	*ids;
	int				fd;
	int				i;

	fd = open(file, O_RDONLY);
	ids = get_ids(fd);
	i = 0;
	while (i < 8)
	{
		printf("id %s line %d\n", get_enum_name(ids[i].key), ids[i].value);
		i++;
	}
	ft_lstclear(&g_alloc_lst, free);
	close(fd);
	return (1);
}


