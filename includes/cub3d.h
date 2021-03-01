/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drwuu <drwuu@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 17:40:55 by lwourms           #+#    #+#             */
/*   Updated: 2021/03/01 01:15:00 by drwuu            ###   ########lyon.fr   */
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
	char			*str;
}					t_dictionary;

t_list				*g_alloc_lst;
int					parse_map(const char *file);
t_dictionary		*get_ids(int fd);
t_window_size		get_resolution(t_list *lst);

void				error_manager(int type, t_list *lst);

const char 			*get_enum_name(t_map_value map_val);
t_type 				get_type(t_type type);
void				alloc_to_lst(void **content, t_type type, int alloc_size, int size);
void				check_allocation(void *alloc, t_list *lst_to_free);
#endif
