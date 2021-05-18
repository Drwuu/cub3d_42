/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ids.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 15:37:57 by lwourms           #+#    #+#             */
/*   Updated: 2021/05/18 16:58:31 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	is_color_info(char *line)
{
	int	i;

	i = 0;
	while (line[i] && ft_iswhitespace(line[i]))
		i++;
	i++;
	while (line[i] && ft_iswhitespace(line[i]))
		i++;
	if (line[i] && ft_isalnum(line[i]))
		return (1);
	return (0);
}

static void	get_ids_info_2(t_cub3d *cub, char *line, int ret)
{
	if (ret == 4 && !cub->map.texture[T_SPRITE1])
		cub->map.texture[T_SPRITE1] = get_tex_path(cub, line);
	if (ret == 5 && !cub->map.texture[T_NORTH])
		cub->map.texture[T_NORTH] = get_tex_path(cub, line);
	if (ret == 6 && !cub->map.texture[T_SOUTH])
		cub->map.texture[T_SOUTH] = get_tex_path(cub, line);
	if (ret == 7 && !cub->map.texture[T_EAST])
		cub->map.texture[T_EAST] = get_tex_path(cub, line);
	if (ret == 8 && !cub->map.texture[T_WEST])
		cub->map.texture[T_WEST] = get_tex_path(cub, line);
}

static void	get_ids_info(t_cub3d *cub, char *line, int ret)
{
	if (ret == 1)
		get_resolution(cub, line);
	if (ret == 2)
	{
		if (is_color_info(line))
			cub->map.floor.color = get_color(cub, line);
		else if (!cub->map.texture[T_FLOOR])
			cub->map.texture[T_FLOOR] = get_tex_path(cub, line);
	}
	if (ret == 3)
	{
		if (is_color_info(line))
			cub->map.ceiling.color = get_color(cub, line);
		else if (!cub->map.texture[T_CEIL])
			cub->map.texture[T_CEIL] = get_tex_path(cub, line);
	}
	get_ids_info_2(cub, line, ret);
}

int	is_id(const char *line)
{
	int	i;

	i = 0;
	while (line[i] && ft_iswhitespace(line[i]))
		i++;
	if (line[i + 2] && ft_iswhitespace(line[i + 2]))
	{
		if (line[i] == 'N' && line[i + 1] == 'O' )
			return (5);
		if (line[i] == 'S' && line[i + 1] == 'O')
			return (6);
		if (line[i] == 'E' && line[i + 1] == 'A')
			return (7);
		if (line[i] == 'W' && line[i + 1] == 'E')
			return (8);
	}
	if (line[i + 1] && line[i] == 'R' && ft_iswhitespace(line[i + 1]))
		return (1);
	if (line[i + 1] && line[i] == 'F' && ft_iswhitespace(line[i + 1]))
		return (2);
	if (line[i + 1] && line[i] == 'C' && ft_iswhitespace(line[i + 1]))
		return (3);
	if (line[i + 1] && line[i] == 'S' && ft_iswhitespace(line[i + 1]))
		return (4);
	return (0);
}

void	check_id_lines(t_cub3d *cub, t_list *id_lines)
{
	int		id;
	int		ret;
	char	*line;

	id = 0;
	while (id_lines)
	{
		line = id_lines->content;
		if (!line[0])
		{
			id_lines = id_lines->next;
			continue ;
		}
		ret = is_id(line);
		if (ret)
		{
			get_ids_info(cub, line, ret);
			id++;
		}
		id_lines = id_lines->next;
	}
	if (id != 8)
		error_manager(2, cub, NULL, NULL);
}
