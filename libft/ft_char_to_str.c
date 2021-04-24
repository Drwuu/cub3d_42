/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 14:33:27 by lwourms           #+#    #+#             */
/*   Updated: 2021/01/17 14:41:35 by lwourms          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_char_to_str(char c)
{
	char *str;

	if (!(str = malloc(sizeof(*str) + 1)))
		return (NULL);
	str[0] = c;
	str[1] = '\0';
	return (str);
}
