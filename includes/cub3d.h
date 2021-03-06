/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drwuu <drwuu@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 10:45:10 by lwourms           #+#    #+#             */
/*   Updated: 2021/03/05 19:43:48 by drwuu            ###   ########lyon.fr   */
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
	t_color			color[2];
	char			*tex_path[5];
}					t_cub3d;

t_cub3d				*parse_map(char *file);
t_ids				*get_ids(int fd, char *line, t_cub3d *cub);
t_window			get_resolution(t_cub3d *cub);
char				*get_tex_path(t_cub3d *cub, int i);
t_color				get_color(t_cub3d *cub, int i);

void				error_manager(int type, t_cub3d *cub, char **dbl_array);
void				*init_data(void *element, t_cub3d *cub, int size_of, int size);
const char 			*get_enum_name(t_id_name id);
void				free_dbl_array(char **str);
void				free_cub(t_cub3d *cub);

#endif
