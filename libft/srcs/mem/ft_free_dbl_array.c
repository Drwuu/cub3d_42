/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_dbl_array.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 14:22:19 by lwourms           #+#    #+#             */
/*   Updated: 2021/10/22 16:10:50 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	**ft_free_dbl_array(void **datas, int size_nullable)
{
	int	i;

	i = 0;
	if (size_nullable)
	{
		while (i < size_nullable)
		{
			if (datas[i])
				wrfree(datas[i]);
			i++;
		}
	}
	else
		while (datas[i])
			wrfree(datas[i++]);
	wrfree(datas);
	return (NULL);
}
