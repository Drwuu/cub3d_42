/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_resolution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drwuu <drwuu@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 15:29:23 by lwourms           #+#    #+#             */
/*   Updated: 2021/03/05 18:25:49 by drwuu            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void static	resolution_errors(char **s_line, t_cub3d *cub)
{
	if (s_line[0][0] != 'R' || s_line[0][1])
		error_manager(1, cub, s_line);
	else if (!s_line[1] || !s_line[2] || s_line[3])
		error_manager(20, cub, s_line);
}

t_window	get_resolution(t_cub3d *cub)
{
	t_window	window;
	char		**s_line;
	int			i;

	window.width = 0;
	window.height = 0;
	s_line = ft_split(cub->ids[0].line, ' ');
	resolution_errors(s_line, cub);
	i = 0;
	while (ft_isdigit(s_line[1][i]))
		window.width = (window.width * 10) + (s_line[1][i++] - '0');
	if (s_line[1][i])
		error_manager(20, cub, s_line);
	i = 0;
	while (ft_isdigit(s_line[2][i]))
		window.height = (window.height * 10) + (s_line[2][i++] - '0');
	if (s_line[2][i])
		error_manager(20, cub, s_line);
	free_dbl_array(s_line);
	if (!window.width || !window.height)
		error_manager(20, cub, NULL);
	return (window);
}