/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 13:30:21 by lwourms           #+#    #+#             */
/*   Updated: 2021/03/21 13:33:24 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

float	ft_radian(float angle)
{
	float	radian;

	radian = angle * M_PI / 180;
	return (radian);
}
