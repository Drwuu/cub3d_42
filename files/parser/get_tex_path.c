/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tex_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drwuu <drwuu@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 14:00:44 by drwuu             #+#    #+#             */
/*   Updated: 2021/03/05 18:57:26 by drwuu            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void static	tex_path_errors(char **s_line, t_cub3d *cub, t_id_name id)
{
	if (id != S)
		if (s_line[0][2] || s_line[0][0] != get_enum_name(id)[0] || \
		s_line[0][1] != get_enum_name(id)[1])
			error_manager(1, cub, s_line);
	if (id == S && s_line[0][1])
		error_manager(1, cub, s_line);
	if (!s_line[1] || s_line[2])
		error_manager(30, cub, s_line);
}

char	*get_tex_path(t_cub3d *cub, int i)
{
	char	*path;
	char	**s_line;

	s_line = ft_split(cub->ids[i].line, ' ');
	tex_path_errors(s_line, cub, cub->ids[i].id);
	path = ft_strdup(s_line[1]);
	if (!path)
		error_manager(-1, cub, s_line);
	free_dbl_array(s_line);
	return (path);
}
