/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 18:38:57 by lwourms           #+#    #+#             */
/*   Updated: 2021/01/08 18:15:59 by lwourms          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		**free_malloc_error(char **finalstr)
{
	int i;

	i = 0;
	while (finalstr[i])
		free(finalstr[i++]);
	return (NULL);
}

static int		findstrlen(char const *s, char c, int i)
{
	int j;

	j = 0;
	while (s[i] && s[i++] != c)
		j++;
	return (j);
}

static int		countstr(char const *s, char c)
{
	int	i;
	int	j;
	int	new_word;

	i = 0;
	j = 0;
	new_word = 1;
	while (s[i])
	{
		if (s[i] == c)
			new_word = 1;
		if (s[i] != c && new_word)
		{
			j++;
			new_word = 0;
		}
		i++;
	}
	return (j);
}

static char		*buildstr(char const *s, char c, int i)
{
	char	*str;
	int		j;

	j = 0;
	if (!(str = malloc(sizeof(*str) * (findstrlen(s, c, i) + 1))))
		return (NULL);
	while (s[i] && s[i] != c)
		str[j++] = s[i++];
	str[j] = '\0';
	return (str);
}

char			**ft_split(char const *s, char c)
{
	char	**finalstr;
	int		i;
	int		j;
	int		new_word;

	if (!s || !(finalstr = malloc(sizeof(*finalstr) * (countstr(s, c) + 1))))
		return (NULL);
	i = 0;
	j = 0;
	new_word = 1;
	while (s[i])
	{
		if (s[i] == c)
			new_word = 1;
		if (s[i] != c && new_word)
		{
			if (!(finalstr[j++] = buildstr(s, c, i)))
				return (free_malloc_error(finalstr));
			new_word = 0;
		}
		i++;
	}
	finalstr[j] = NULL;
	return (finalstr);
}
