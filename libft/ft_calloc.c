/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 18:05:56 by lwourms           #+#    #+#             */
/*   Updated: 2021/03/18 15:34:23 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t size, size_t count)
{
	char	*tab;
	size_t	i;

	i = 0;
	if (!(tab = malloc(count * size)))
		return (NULL);
	while (i < count * size)
		tab[i++] = 0;
	return (tab);
}
