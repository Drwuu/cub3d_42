/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_resolution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 14:26:34 by lwourms           #+#    #+#             */
/*   Updated: 2021/02/27 18:14:08 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int		get_size(int i, const char *line)
{
	int size;

	size = 0;
	if (line[i] && ft_isdigit(line[i]))
		while (line[i] && ft_isdigit(line[i]))
			size *= 10 + (line[i++] - '0');
	else
		error_manager(20);
	return (size);
}

t_window_size	get_resolution(const char *line, int *i)
{
	t_window_size	window;
	
	if (line[*i] == 'R')
	{
		while (line[*i] && ft_iswhitespace(line[*i]))
			i++;
		window.width = get_size(*i, line);
		if (line[*i])
		{
			while (line[*i] && ft_iswhitespace(line[*i]))
				i++;
		}
		//window.height = 
	}
	else if (!line[*i])
		error_manager(1);
}