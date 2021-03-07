/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tex_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 14:00:44 by drwuu             #+#    #+#             */
/*   Updated: 2021/03/07 17:26:41 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void static	tex_path_errors(char **s_line, t_cub3d *cub)
{
	if (!s_line[1] || s_line[2])
		error_manager(30, cub, s_line);
}

char	*get_tex_path(t_cub3d *cub, int i)
{
	char	*path;
	char	**s_line;

	s_line = ft_split(cub->ids[i].line, " \t");
	if (!s_line)
		error_manager(-1, cub, NULL);
	tex_path_errors(s_line, cub);
	path = ft_strdup(s_line[1]);
	if (!path)
		error_manager(-1, cub, s_line);
	ft_free_dbl_array(s_line);
	return (path);
}
