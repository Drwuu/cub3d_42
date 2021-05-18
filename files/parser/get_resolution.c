/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_resolution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 15:29:23 by lwourms           #+#    #+#             */
/*   Updated: 2021/05/12 20:41:37 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	resolution_errors(char **s_line, t_cub3d *cub)
{
	if (!s_line[1] || !s_line[2] || s_line[3])
		error_manager(20, cub, NULL, (void **)s_line);
}

static int	get_size(t_cub3d *cub, char **s_line, int index, int screen_size)
{
	int			i;
	long long	size;

	i = 0;
	size = 0;
	while (ft_isdigit(s_line[index][i]))
	{
		size = (size * 10) + (s_line[index][i++] - '0');
		if (size > screen_size)
			return (screen_size);
		else if (size <= 0)
			error_manager(21, cub, NULL, (void **)s_line);
	}
	if (s_line[index][i])
		error_manager(20, cub, NULL, (void **)s_line);
	return (size);
}

void	get_resolution(t_cub3d *cub, char *line)
{
	char	**s_line;

	s_line = ft_split(line, " \t");
	if (!s_line)
		error_manager(-1, cub, NULL, NULL);
	resolution_errors(s_line, cub);
	cub->settings.window.width = get_size(cub, s_line, 1, \
	cub->settings.user_screen_size.width);
	cub->settings.window.height = get_size(cub, s_line, 2, \
	cub->settings.user_screen_size.height);
	ft_free_dbl_array((void **)s_line, 0);
	if (!cub->settings.window.width || !cub->settings.window.height)
		error_manager(20, cub, NULL, NULL);
}
