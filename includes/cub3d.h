/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drwuu <drwuu@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 10:45:10 by lwourms           #+#    #+#             */
/*   Updated: 2021/03/05 01:00:59 by drwuu            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include "../tools/libft/libft.h"
# include "../tools/gnl/get_next_line.h"
# include "../tools/minilibx/mlx.h"

typedef enum		e_id_name
{
	R = 1,
	NO,
	SO,
	WE,
	EA,
	S,
	F,
	C
}					t_id_name;

typedef struct		s_ids
{
	t_id_name		id;
	int				line_nb;
	char			*line;
}					t_ids;

typedef struct		s_window
{
	int				width;
	int				height;
}					t_window;

typedef	struct		s_color
{
	unsigned char	red;
	unsigned char	green;
	unsigned char	blue;
	unsigned char	alpha;
}					t_color;

typedef struct		s_cub3d
{
	t_ids			*ids;
	t_window		window;
	t_color			color;
	char			*tex_path;
}					t_cub3d;

t_cub3d				*parse_map(char *file);
t_ids				*get_ids(int fd, char *line);
t_window			get_resolution(char *line);
char				*get_texture(char *line);
char				*get_texture(char *line);
t_color				get_color(char *line);

void				error_manager(int type, void *to_free);
void				*init_data(void **element, int size_of, int size);
const char 			*get_enum_name(t_id_name id);
void				free_dbl_array(char **str);

#endif
