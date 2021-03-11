/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drwuu <drwuu@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 11:11:00 by lwourms           #+#    #+#             */
/*   Updated: 2021/03/11 00:48:14 by drwuu            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	get_valid_map(t_list *maplines)
{
	t_dictionary	*line;
	t_list			*last;
	char			*str;
	int				index;

	last = ft_lstlast(maplines);
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
	get_valid_map(cub->map.map_lines);
}