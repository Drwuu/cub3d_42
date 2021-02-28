/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 11:55:15 by lwourms           #+#    #+#             */
/*   Updated: 2021/02/27 18:26:33 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	error_manager(int type)
{
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