/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 14:13:17 by ludwuu            #+#    #+#             */
/*   Updated: 2021/05/16 20:30:08 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*str;
	int		i;

	str = malloc(sizeof(*str) * ((int)ft_strlen(s1) + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!s)
		return (NULL);
	str = malloc(sizeof(*str) * (len + 1));
	if (!str)
		return (NULL);
	if ((size_t)start >= ft_strlen((char *)s))
	{
		str[0] = '\0';
		return ((char *)str);
	}
	i = 0;
	j = start;
	while (j < start + (unsigned int)len && s[j])
		str[i++] = s[j++];
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	str = malloc((sizeof(*str) * (ft_strlen((char *)s1) \
		+ ft_strlen((char *)s2)) + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		str[j++] = s1[i++];
	i = 0;
	while (s2[i])
		str[j++] = s2[i++];
	str[j] = '\0';
	return (str);
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
