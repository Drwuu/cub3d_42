/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 19:01:43 by lwourms           #+#    #+#             */
/*   Updated: 2021/05/16 20:14:27 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	find_newline(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int	copy_line(const char *buf, char **str)
{
	char	*tmp;

	if (!*str)
	{
		*str = ft_strdup(buf);
		if (!*str)
			return (-1);
	}
	else
	{
		tmp = ft_strjoin(*str, buf);
		if (!tmp)
			return (-1);
		free(*str);
		*str = tmp;
	}
	return (1);
}
