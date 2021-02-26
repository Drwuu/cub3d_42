/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 17:40:18 by lwourms           #+#    #+#             */
/*   Updated: 2021/02/26 21:08:04 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	read_map(const char *file)
{
	t_dictionary	ids[8];
	int				fd;
	int				i;
	int 			line_nb;
	char			*line;

	fd = open(file, O_RDONLY);
	line_nb = 1;
	i = 0;
	while (get_next_line(fd, &line))
	{
		ids[i] = get_id(line);
		if (ids[i].key)
		{
			ids[i].value = line_nb;
			printf("key %s, line %d\n", get_enum_name(ids[i].key), ids[i].value);
			i++;
		}
		//printf("line nb %d = %s\n", line_nb, line);
		line_nb++;
		free(line);
	}
	//printf("line nb %d = %s\n", line_nb, line);
	free(line);
	close(fd);
	return (1);
}
