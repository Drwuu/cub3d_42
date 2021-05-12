/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enums.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 10:45:10 by lwourms           #+#    #+#             */
/*   Updated: 2021/05/11 15:52:31 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ENUMS_H
# define ENUMS_H

# define TEXTURE_NB 7

# include "cub3d.h"

typedef enum	e_texture
{
	T_NORTH,
	T_SOUTH,
	T_EAST,
	T_WEST,
	T_FLOOR,
	T_CEIL,
	T_SPRITE1,
}	t_texture;

#endif
