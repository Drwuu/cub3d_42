/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_ischars.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drwuu <drwuu@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 14:33:27 by lwourms           #+#    #+#             */
/*   Updated: 2021/03/11 14:41:15 by drwuu            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_char_ischars(char c, const char *chars)
{
	int i;

	i = 0;
	while (*chars)
		if (c == *chars++)
			return (1);
	return (0);
}
