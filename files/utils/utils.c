/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drwuu <drwuu@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 15:16:22 by lwourms           #+#    #+#             */
/*   Updated: 2021/03/11 17:36:29 by drwuu            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

const char 	*get_id_enum_name(t_id_name id)
{
    const char	*enum_name[9];
	
	enum_name[0] = NULL;
	enum_name[1] = "R";
	enum_name[2] = "NO";
	enum_name[3] = "SO";
	enum_name[4] = "WE";
	enum_name[5] = "EA";
	enum_name[6] = "S";
	enum_name[7] = "F";
	enum_name[8] = "C";
    return (enum_name[id]);
}

int				is_valid_mapline(char *line)
{
	int i;

	i = 0;
	if (!ft_ischar(line, " 102NSOE"))
		return (0);
	return (1);
}

int				is_valid_next(char *line, int i)
{
	if (!line[i - 1] || !line[i + 1])
		return (0);
	if (ft_char_ischars(line[i - 1], " ") || \
	ft_char_ischars(line[i + 1], " "))
		return (0);
	else
		return (1);
}

t_cub3d		*init_cub(t_cub3d *cub, int size)
{
	cub = ft_calloc(sizeof(*cub), size);
	if (!cub)
		error_manager(-1, cub, NULL);
	ft_bzero(cub, sizeof(*cub));
	return (cub);
}
