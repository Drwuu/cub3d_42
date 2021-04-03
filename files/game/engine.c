/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 19:42:53 by lwourms           #+#    #+#             */
/*   Updated: 2021/04/03 18:48:17 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_vec3	rotate_z(t_vec3 vector, float angle_rad)
{
	t_vec3	new_vector;

	new_vector.x = vector.x * cosf(angle_rad) - vector.y * sinf(angle_rad);
	new_vector.y = vector.x * sinf(angle_rad) + vector.y * cosf(angle_rad);
	new_vector.z = vector.z;
	return (new_vector);
}

t_vec3	rotate_x(t_vec3 vector, float angle_rad)
{
	t_vec3	new_vector;

	new_vector.x = vector.x;
	new_vector.y = vector.y * cosf(angle_rad) - vector.z * sinf(angle_rad);
	new_vector.z = vector.y * sinf(angle_rad) +  vector.z * cosf(angle_rad);
	return (new_vector);
}
