/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 18:28:57 by lwourms           #+#    #+#             */
/*   Updated: 2021/01/03 16:35:12 by lwourms          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t i;

	i = -1;
	if (!src && !dst)
		return (0);
	if (dst < src)
		while (++i < len)
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
	else
		while (len--)
			((unsigned char *)dst)[len] = ((unsigned char *)src)[len];
	return (dst);
}
