/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_resolution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drwuu <drwuu@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 15:29:23 by lwourms           #+#    #+#             */
/*   Updated: 2021/03/05 01:56:11 by drwuu            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void static	resolution_errors(char **s_line, char *line)
{
	if (s_line[0][0] != 'R' || s_line[0][1])
	{
		free_dbl_array(s_line);
		error_manager(1, line); // need to free all lines
	}
	else if (!s_line[1] || !s_line[2] || s_line[3])
	{
		free_dbl_array(s_line);
		error_manager(20, line); // need to free all lines
	}
}

t_window	get_resolution(char *line)
{
	t_window	window;
	char		**s_line;
	int			i;

	window.width = 0;
	window.height = 0;
	s_line = ft_split(line, ' ');
	resolution_errors(s_line, line);
	i = 0;
	while (ft_isdigit(s_line[1][i]))
		window.width = (window.width * 10) + (s_line[1][i++] - '0');
	if (s_line[1][i])
		error_manager(20, line);
	i = 0;
	while (ft_isdigit(s_line[2][i]))
		window.height = (window.height * 10) + (s_line[2][i++] - '0');
	if (s_line[2][i])
		error_manager(20, line);
	free_dbl_array(s_line);
	if (!window.width || !window.height)
		error_manager(20, line);
	return (window);
}