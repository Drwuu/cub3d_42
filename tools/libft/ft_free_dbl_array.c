/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_dbl_array.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 14:22:19 by lwourms           #+#    #+#             */
/*   Updated: 2021/03/18 16:46:18 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	**ft_free_dbl_array(void **datas, int size)
{
	int i;

	i = 0;
	if (size)
		while (i < size)
			free(datas[i++]);
	else
		while (datas[i])
			free(datas[i++]);
	free(datas);
	return (NULL);
}
