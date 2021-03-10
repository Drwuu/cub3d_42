/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 11:11:00 by lwourms           #+#    #+#             */
/*   Updated: 2021/03/10 19:26:52 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	get_valid_map(t_list *maplines)
{
	t_dictionary	*line;
	t_list			*save;

	save = maplines;
	while(maplines)
	{
		line = maplines->content;
		if (!line->value)
		{
			free(line->value);
			free(line);
		}
		maplines = maplines->next;
	}
	maplines = save;
}

int		is_valid_mapline(char *line)
{
	int i;

	i = 0;
	if (!ft_ischar(line, " 102NSOE"))
		return (0);
	return (1);
}

void	get_map(t_cub3d *cub)
{


}