/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drwuu <drwuu@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 15:16:22 by lwourms           #+#    #+#             */
/*   Updated: 2021/03/05 18:37:05 by drwuu            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

const char 	*get_enum_name(t_id_name id)
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

void	*init_data(void *element, t_cub3d *cub, int size_of, int size)
{

	element = ft_calloc(size_of, size);
	if (!element)
		error_manager(-1, cub, NULL);
	ft_bzero(element, size_of);
	return (element);
}
