/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 17:40:55 by lwourms           #+#    #+#             */
/*   Updated: 2021/02/26 21:04:22 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include "../libft/libft.h"
# include "../gnl/get_next_line.h"

typedef enum		e_map_value
{
	R = 1,
	NO,
	SO,
	WE,
	EA,
	S,
	F,
	C
}					t_map_value;

typedef	struct		s_window_size
{
	int				width;
	int				height;
}					t_window_size;

typedef	struct		s_color
{
	unsigned char	red;
	unsigned char	green;
	unsigned char	blue;
	unsigned char	alpha;
}					t_color;

typedef	struct		s_dictionary
{
	int				key;
	int				value;
}					t_dictionary;

int					read_map(const char *file);
t_dictionary		get_id(const char *line);

void				error_manager(int type);

const char 			*get_enum_name(t_map_value map_val);

#endif
