/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 15:16:22 by lwourms           #+#    #+#             */
/*   Updated: 2021/03/04 18:01:49 by lwourms          ###   ########.fr       */
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

void	error_manager(int type, void *to_free)
{
	if (to_free)
		free(to_free);
	if (type == -1)
		printf("Map error of type %d : the size you malloced broke down\n", type);
	else if (type == 1)
		printf("Map error of type %d : you should use a correct ID, \
		please refer to the subject\n", type);
	else if (type == 2)
		printf("Map error of type %d : duplicate IDs detected, \
		please refer to the subject\n", type);
	else if (type == 20)
		printf("Map error of type %d : you should use a correct window size, \
		please refer to the subject\n", type);
	exit(0);
}

void	*init_data(void **element, int size_of, int size)
{

	*element = ft_calloc(size_of, size);
	if (!*element)
		error_manager(-1, NULL);
	ft_bzero(*element, size_of);
	return (*element);
}
