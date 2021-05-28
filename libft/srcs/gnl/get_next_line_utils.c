/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 14:13:17 by ludwuu            #+#    #+#             */
/*   Updated: 2021/05/26 20:56:49 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/get_next_line.h"

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

int	free_str_error(char *str, char *buf)
{
	if (buf)
		free(buf);
	if (str)
	{
		free(str);
		str = NULL;
	}
	return (-1);
}
