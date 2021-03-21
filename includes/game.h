/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 10:45:10 by lwourms           #+#    #+#             */
/*   Updated: 2021/03/21 18:58:34 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

typedef struct s_engine
{
	t_ray	rays;
}	t_engine;

typedef struct s_ray
{
	const t_vec3	ray_coord;
}	t_ray;

typedef struct s_plane
{
	float	A;
	float	B;
	float	C;
	float	D;
}	t_plane;

typedef struct s_settings
{
	int	FOV;
}	t_settings;

#endif
