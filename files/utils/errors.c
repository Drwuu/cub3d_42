/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drwuu <drwuu@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 18:36:42 by drwuu             #+#    #+#             */
/*   Updated: 2021/03/05 18:37:01 by drwuu            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	error_manager(int type, t_cub3d *cub, char **dbl_array)
{
	if (dbl_array)
		free_dbl_array(dbl_array);
	free_cub(cub);
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
	else if (type == 30)
		printf("Map error of type %d : you should use a correct texture path, \
		please refer to the subject\n", type);
	exit(0);
}
