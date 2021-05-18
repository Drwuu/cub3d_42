/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_dbl_array.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 14:22:19 by lwourms           #+#    #+#             */
/*   Updated: 2021/05/16 19:08:04 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	**ft_free_dbl_array(void **datas, int size)
{
	int	i;

	i = 0;
	if (size)
	{
		while (i < size)
		{
			if (datas[i])
				free(datas[i]);
			i++;
		}
	}
	else
		while (datas[i])
			free(datas[i++]);
	free(datas);
	return (NULL);
}
