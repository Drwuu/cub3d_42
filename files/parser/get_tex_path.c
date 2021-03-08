/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tex_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drwuu <drwuu@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 14:00:44 by drwuu             #+#    #+#             */
/*   Updated: 2021/03/08 01:25:38 by drwuu            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void static	tex_path_errors(char **s_line, t_cub3d *cub)
{
	if (!s_line[1] || s_line[2])
		error_manager(30, cub, s_line);
}

char	*get_tex_path(t_cub3d *cub)
{
	int		i;
	char	**s_line;

	i = -1;
	while (++i < 5)
	{
		cub->map.wall[i].face = i;
		s_line = ft_split(cub->map.ids[i + 1].line, " \t");
		if (!s_line)
			error_manager(-1, cub, NULL);
		tex_path_errors(s_line, cub);
		if (i < 4)
		{
			cub->map.wall[i].texture = ft_strdup(s_line[1]);
			if (!cub->map.wall[i].texture)
				error_manager(-1, cub, s_line);
		}
		else
		{
			cub->map.enemy.texture = ft_strdup(s_line[1]);
			if (!cub->map.enemy.texture)
				error_manager(-1, cub, s_line);
		}
		ft_free_dbl_array(s_line);
	}
}
