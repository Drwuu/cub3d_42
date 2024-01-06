/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 15:16:22 by lwourms           #+#    #+#             */
/*   Updated: 2021/05/12 20:55:23 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	is_valid_mapline(char *line)
{
	if (!ft_ischar(line, " 102NSWE"))
		return (0);
	return (1);
}

int	is_valid_next(char *line, int i)
{
	if (!line[i - 1] || !line[i + 1])
		return (0);
	if (ft_char_ischars(line[i - 1], " ") || \
	ft_char_ischars(line[i + 1], " "))
		return (0);
	else
		return (1);
}
