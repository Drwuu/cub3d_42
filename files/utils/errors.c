/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 18:36:42 by drwuu             #+#    #+#             */
/*   Updated: 2021/03/07 14:27:24 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	error_manager(int type, t_cub3d *cub, char **dbl_array)
{
	if (dbl_array)
		ft_free_dbl_array(dbl_array);
	free_cub(cub);
	printf("Error\n");
	printf("Map error of type %d : ", type);
	if (type == -1)
	{
		printf("the size you malloced broke down\n");
		exit(0);
	}
	else if (type == 1)
		printf("you should use a correct ID, ");
	else if (type == 2)
		printf("duplicate IDs detected, ");
	else if (type == 20)
		printf("you should use a correct window size, ");
	else if (type == 30)
		printf("you should use a correct texture path, ");
	else if (type == 40)
		printf("you should use a correct color, ");
	printf("please refer to the subject\n");
	while(1);
	exit(0);
}
