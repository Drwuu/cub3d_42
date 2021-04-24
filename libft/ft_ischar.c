/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ischar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 14:33:27 by lwourms           #+#    #+#             */
/*   Updated: 2021/03/17 16:03:54 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_ischar(const char *s, const char *c)
{
	int i;
	int j;
	int ret;

	i = 0;
	j = 0;
	ret = 0;
	if (!s)
		return (-1);
	while (s[i])
	{
		while (c[j])
			if (s[i] == c[j++])
			{
				ret = 1;
				j = 0;
				break ;
			}
		if (!ret)
			return (0);
		ret = 0;
		i++;
	}
	return (1);
}
