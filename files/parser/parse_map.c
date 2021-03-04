/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 10:51:40 by lwourms           #+#    #+#             */
/*   Updated: 2021/03/04 18:20:20 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static t_ids	*sort_ids(t_ids *ids)
{
	int			i;
	int			j;
	int			save;

	i = 0;
	j = 1;
	while (i < 9)
	{
		if (ids[i].id == j)
		{
			save = i;
			ids[j++] = ids[i];
			ids[i++] = ids[save]; 
		}	
	}
}

t_cub3d			*parse_map(char *file)
{
	t_cub3d		*cub;
	char		*line;
	int			fd;

	fd = open("map.cub", O_RDONLY);
	cub = init_data((void *)&cub, sizeof(*cub), 1);
	cub->ids = get_ids(fd, line);
	cub->window = get_resolution(cub->ids[0].line);
	dprintf(1, "id = %s\n", get_enum_name(cub->ids[2].id));
	dprintf(1, "id str = %s\n", cub->ids[2].line);
	//cub->window = get_resolution(cub->ids->line);
	return (cub);
}