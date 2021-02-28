/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drwuu <drwuu@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 11:55:15 by lwourms           #+#    #+#             */
/*   Updated: 2021/02/28 17:00:24 by drwuu            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	error_manager(int type, t_list *lst)
{
	if (lst)
		ft_lstclear(&lst, free);
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