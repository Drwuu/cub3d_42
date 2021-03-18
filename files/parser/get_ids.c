/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ids.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 15:37:57 by lwourms           #+#    #+#             */
/*   Updated: 2021/03/18 15:03:11 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void		get_ids_info(t_cub3d *cub, char *line, int ret)
{
	if (ret == 1)
		get_resolution(cub, line);
	if (ret == 2)
		cub->map.floor.color =  get_color(cub, line);
	if (ret == 3)
		cub->map.ceiling.color = get_color(cub, line);
	if (ret == 4)
		cub->map.sprite_tex = get_tex_path(cub, line);
	if (ret == 5)
		cub->map.wall_tex[0] = get_tex_path(cub, line);
	if (ret == 6)
		cub->map.wall_tex[1] = get_tex_path(cub, line);
	if (ret == 7)
		cub->map.wall_tex[2] = get_tex_path(cub, line);
	if (ret == 8)
		cub->map.wall_tex[3] = get_tex_path(cub, line);
}

int		is_id(const char *line)
{
	int i;

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

void		check_id_lines(t_cub3d *cub, t_list *id_lines)
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
	if (id > 8)
		error_manager(2, cub, NULL, NULL);
}
