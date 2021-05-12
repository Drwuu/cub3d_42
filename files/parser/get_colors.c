/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 19:13:06 by drwuu             #+#    #+#             */
/*   Updated: 2021/04/29 15:47:55 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void static	color_errors(char **s_lines, char **red_lines, t_cub3d *cub)
{
	if (!s_lines[1] || s_lines[3])
		error_manager(30, cub, NULL, (void **)s_lines);
	if (red_lines)
	{
		if (!red_lines[0] || !red_lines[1] || red_lines[2] || \
		ft_iswhitespace(s_lines[0][ft_strlen(s_lines[0]) - 1]))
		{
			ft_free_dbl_array((void **)red_lines, 0);
			error_manager(40, cub, NULL, (void **)s_lines);
		}
	}
}

int static	get_red_color(char **s_lines, t_cub3d *cub)
{
	char **red_lines;
	int red;
	int i;

	red_lines = ft_split(s_lines[0], " \t");
	if (!red_lines)
		error_manager(-1, cub, NULL, (void **)s_lines);
	color_errors(s_lines, red_lines, cub);
	red = -1;
	i = 0;
	while (red_lines[1][i] && ft_isdigit(red_lines[1][i]))
	{
		if (red == -1)
			red = 0;
		red = (red * 10) + (red_lines[1][i++] - '0');
	}
	if (red_lines[1][i] || red < 0 || red > 255)
	{
		ft_free_dbl_array((void **)red_lines, 0);
		error_manager(40, cub, NULL, (void **)s_lines);
	}
	ft_free_dbl_array((void **)red_lines, 0);
	return (red);
}

static int	get_size(t_cub3d *cub, char **s_lines, int index)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (ft_isdigit(s_lines[index][i]))
		size = (size * 10) + (s_lines[index][i++] - '0');
	if (s_lines[index][i] || size > 255)
		error_manager(40, cub, NULL, (void **)s_lines);
	return (size);
}

t_color	get_color(t_cub3d *cub, char *line)
{
	t_color		color;
	char		**s_lines;
	int			i;
	int			count;

	i = 0;
	count = 0;
	while (line[i])
		if (line[i++] == ',')
			count++;
	if (count != 2)
		error_manager(30, cub, NULL, NULL);
	s_lines = ft_split(line, ",");
	if (!s_lines)
		error_manager(-1, cub, NULL, NULL);
	color_errors(s_lines, NULL, cub);
	color.a = 0;
	color.r = get_red_color(s_lines, cub);
	color.g = get_size(cub, s_lines, 1);
	color.b = get_size(cub, s_lines, 2);
	ft_free_dbl_array((void **)s_lines, 0);
	return (color);
}
