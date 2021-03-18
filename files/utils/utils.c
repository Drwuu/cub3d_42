/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 15:16:22 by lwourms           #+#    #+#             */
/*   Updated: 2021/03/18 16:33:31 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int				is_valid_mapline(char *line)
{
	int i;

	i = 0;
	if (!ft_ischar(line, " 102NSWE"))
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
		error_manager(-1, cub, NULL, NULL);
	ft_bzero(cub, sizeof(*cub));
	return (cub);
}
