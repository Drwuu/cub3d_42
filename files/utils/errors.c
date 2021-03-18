/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 18:36:42 by drwuu             #+#    #+#             */
/*   Updated: 2021/03/18 16:48:47 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void		window_errors(int type)
{	
	if (type == 20)
		printf("you should use a correct window size, ");
	else if (type == 21)
		printf("your window size is too big, ");
}

static void		texture_errors(int type)
{	
	if (type == 30)
		printf("you should use a correct texture path, ");
	else if (type == 40)
		printf("you should use a correct color, ");
}

static void		ids_errors(int type)
{	
	if (type == 1)
		printf("you should use a correct ID, ");
	else if (type == 2)
		printf("duplicate IDs detected, ");
	else if (type == 3)
		printf("wrong IDs format, ");
}

static void		map_errors(int type)
{	
	if (type == 50)
		printf("your map is not well formated, ");
	else if (type == 51)
		printf("your map has an issue in a line, ");
	else if (type == 52)
		printf("you have too much players in the scene, ");
}

void			error_manager(int type, t_cub3d *cub, void *data, \
				void **data2)
{
	if (data2)
		ft_free_dbl_array(data2, 0);
	if (data)
		free(data);
	free_cub(cub);
	printf("Error\n");
	if (type == -1)
	{
		printf("the size you malloced broke down\n");
		exit(0);
	}
	ids_errors(type);
	window_errors(type);
	texture_errors(type);
	map_errors(type);
	printf("please refer to the subject\n");
	//while(1);
	exit(0);
}
