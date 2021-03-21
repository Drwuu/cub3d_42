/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_plane.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 16:08:59 by lwourms           #+#    #+#             */
/*   Updated: 2021/03/20 19:42:36 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

float	find_T(t_plane plane, t_vec3 origin, float vector)
{
	float	T;
	float	eq1;
	float	eq2;

	eq1 = (plane.A * origin.x) + (plane.B * origin.y) + (plane.C * origin.z) + \
	plane.D;
//	eq2 = (plane.A * vector) + 
}

t_plane	create_plane(int points[4])
{
	t_plane	plane;

	plane.A = points[0];
	plane.B = points[1];
	plane.C = points[2];
	plane.D = points[3];
}
