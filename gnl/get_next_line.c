/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 19:01:43 by lwourms           #+#    #+#             */
/*   Updated: 2021/01/09 16:54:04 by lwourms          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	int		find_newline(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

static	int		copy_line(const char *buf, char **str)
{
	char	*tmp;

	if (!*str)
	{
		if (!(*str = ft_strdup(buf)))
			return (-1);
	}
	else
	{
		if (!(tmp = ft_strjoin(*str, buf)))
			return (-1);
		free(*str);
		*str = tmp;
	}
	return (1);
}

static	int		read_line(char **str, int fd)
{
	int		head;
	char	*buf;

	if (!(buf = malloc(sizeof(*buf) * (BUFFER_SIZE + 1))))
		return (free_str_error(*str, buf));
	while ((head = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[head] = '\0';
		if (copy_line(buf, str) < 0)
			return (free_str_error(*str, buf));
		if (find_newline(*str) >= 0)
			break ;
	}
	if (head < 0)
		return (free_str_error(*str, buf));
	if (!*str)
		if (!(*str = ft_strdup("")))
			return (free_str_error(*str, buf));
	free(buf);
	return (1);
}

static	int		build_line(char **str, char **line)
{
	int		i;
	char	*tmp;

	tmp = NULL;
	i = find_newline(*str);
	if (i >= 0)
	{
		if (!(*line = ft_substr(*str, 0, i)))
			return (free_str_error(*str, tmp));
		if (!(tmp = ft_strdup(&(*str)[i + 1])))
			return (free_str_error(*str, tmp));
		free(*str);
		*str = tmp;
		return (1);
	}
	else
	{
		if (!(*line = ft_substr(*str, 0, ft_strlen(*str))))
			return (free_str_error(*str, tmp));
		free(*str);
		*str = NULL;
		return (0);
	}
}

int				get_next_line(const int fd, char **line)
{
	static char	*str[OPEN_MAX];

	if (!line || fd < 0 || BUFFER_SIZE <= 0)
		return (-1);
	if (read_line(&str[fd], fd) > 0)
		return (build_line(&str[fd], line));
	else
		return (-1);
}
