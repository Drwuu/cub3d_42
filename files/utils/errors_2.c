/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 18:36:42 by drwuu             #+#    #+#             */
/*   Updated: 2021/05/12 20:51:20 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	global_errors(int type)
{	
	if (type == -1 || type == -2 || type == -3 || type == -4)
	{
		if (type == -1)
			printf("an allocation failed\n");
		else if (type == -2)
			printf("there was an error creating a thread\n");
		else if (type == -3)
			printf("failed to open the map\n");
		else if (type == -4)
			printf("please specify a map name\n");
		exit(0);
	}
}
