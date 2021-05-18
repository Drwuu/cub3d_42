/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ischar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 14:33:27 by lwourms           #+#    #+#             */
/*   Updated: 2021/05/16 19:08:04 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	process(const char *s, const char *c)
{
	int	ret;
	int	i;
	int	j;

	i = 0;
	j = 0;
	ret = 0;
	while (s[i])
	{
		while (c[j])
		{
			if (s[i] == c[j++])
			{
				ret = 1;
				j = 0;
				break ;
			}
		}
		if (!ret)
			return (0);
		ret = 0;
		i++;
	}
	return (1);
}

int	ft_ischar(const char *s, const char *c)
{
	if (!s)
		return (-1);
	return (process(s, c));
}
