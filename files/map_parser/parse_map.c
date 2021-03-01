/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drwuu <drwuu@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 17:40:18 by lwourms           #+#    #+#             */
/*   Updated: 2021/03/01 02:08:38 by drwuu            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int		parse_map(const char *file)
{
	int				fd;
	t_dictionary	*ids;
	t_window_size	window;

	fd = open(file, O_RDONLY);
	ids = get_ids(fd);
	window = get_resolution(g_alloc_lst);
	printf("w = %d || h = %d\n", window.width, window.height);
	ft_lstclear(&g_alloc_lst, free);
	close(fd);
	return (1);
}


