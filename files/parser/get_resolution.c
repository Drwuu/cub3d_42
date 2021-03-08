/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_resolution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drwuu <drwuu@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 15:29:23 by lwourms           #+#    #+#             */
/*   Updated: 2021/03/07 21:08:43 by drwuu            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	resolution_errors(char **s_line, t_cub3d *cub)
{
	if (!s_line[1] || !s_line[2] || s_line[3])
		error_manager(20, cub, s_line);
}

static int	get_size(t_cub3d *cub, char **s_line, int index)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (ft_isdigit(s_line[index][i]))
		size = (size * 10) + (s_line[index][i++] - '0');
	if (s_line[index][i])
		error_manager(20, cub, s_line);
	return (size);
}

void		get_resolution(t_cub3d *cub)
{
	char		**s_line;

	s_line = ft_split(cub->map.ids[0].line, " \t");
	if (!s_line)
		error_manager(-1, cub, NULL);
	resolution_errors(s_line, cub);
	cub->window.width = get_size(cub, s_line, 1);
	cub->window.height = get_size(cub, s_line, 2);
	ft_free_dbl_array(s_line);
	if (!cub->window.width || !cub->window.height)
		error_manager(20, cub, NULL);
}
