/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tex_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 14:00:44 by drwuu             #+#    #+#             */
/*   Updated: 2021/03/12 22:17:36 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void static	tex_path_errors(char **s_line, t_cub3d *cub)
{
	if (!s_line[1] || s_line[2])
		error_manager(30, cub, s_line);
}

void static	get_enemies(char **s_line, t_cub3d *cub)
{
	t_enemy		*enemy;
	int			j;

	j = 0;
	enemy = ft_calloc(sizeof(*enemy), cub->map.enemy_nb);
	if (!enemy)
		error_manager(-1, cub, s_line);
	ft_bzero(enemy, sizeof(*enemy));
	while (j < cub->map.enemy_nb)
	{
		enemy[j].texture = ft_strdup(s_line[1]);
		if (!enemy[j].texture)
			error_manager(-1, cub, s_line);
		j++;
	}
	cub->map.enemy = enemy;
}

void		get_tex_path(t_cub3d *cub)
{
	int		i;
	char	**s_line;

	i = -1;
	while (++i < 5)
	{
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
			get_enemies(s_line, cub);
		ft_free_dbl_array(s_line);
	}
}
