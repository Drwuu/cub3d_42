/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drwuu <drwuu@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 19:13:06 by drwuu             #+#    #+#             */
/*   Updated: 2021/03/06 02:22:58 by drwuu            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void static	color_errors(char **s_line, t_cub3d *cub, t_id_name id)
{
	if (s_line[3][2] || s_line[0][0] != get_enum_name(id)[0] || \
		s_line[0][1] != get_enum_name(id)[1])
			error_manager(1, cub, s_line);
	if (id == S && s_line[0][1])
		error_manager(1, cub, s_line);
	if (!s_line[1] || s_line[2])
		error_manager(30, cub, s_line);
}

int static	get_red_color(char **s_line, t_cub3d *cub, t_id_name id)
{
	int red;
	int i;

	i = 0;
	red = -1;
	if (!s_line[0][i])
		error_manager(1, cub, s_line);
	while(s_line[0][i] && ft_iswhitespace(s_line[0][i]))
		i++;
	if (s_line[0][i] && s_line[0][i] == get_enum_name(id)[0])
		i++;
	else
		error_manager(1, cub, s_line);
	while(s_line[0][i] && ft_iswhitespace(s_line[0][i]))
		i++;
	while (s_line[0][i] && ft_isdigit(s_line[0][i]))
	{
		if (red == -1)
			red = 0;
		red = (red * 10) + (s_line[0][i++] - '0');
	}
	if (red < 0 || red > 255)
		error_manager(40, cub, s_line);
	return (red);
}

static int	get_size(t_cub3d *cub, char **s_line, int index)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (ft_isdigit(s_line[index][i]))
		size = (size * 10) + (s_line[index][i++] - '0');
	if (s_line[index][i] || size > 255)
		error_manager(40, cub, s_line);
	return (size);
}

t_color		get_color(t_cub3d *cub, int i)
{
	t_color		color;
	char		**s_line;

	s_line = ft_split(cub->ids[i].line, ',');
	if (!s_line)
		error_manager(-1, cub, NULL);
	color.alpha = 255;
	color.red = get_red_color(s_line, cub, cub->ids[i].id);
	color.green = get_size(cub, s_line, 1);
	color.blue = get_size(cub, s_line, 2);
	free_dbl_array(s_line);
	return (color);
}
