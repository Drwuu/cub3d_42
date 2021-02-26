/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 11:55:15 by lwourms           #+#    #+#             */
/*   Updated: 2021/02/26 17:25:27 by lwourms          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	error_manager(int type)
{
	if (type == 1)
		printf("Map error of type %d : you should use a correct ID, \
		please refer to the subject", type);
	exit(0);
}