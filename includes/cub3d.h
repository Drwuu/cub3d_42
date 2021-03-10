/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 10:45:10 by lwourms           #+#    #+#             */
/*   Updated: 2021/03/10 13:57:37 by lwourms          ###   ########.fr       */
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
	ID_R = 1,
	ID_NO,
	ID_SO,
	ID_WE,
	ID_EA,
	ID_S,
	ID_F,
	ID_C
}					t_id_name;

typedef enum		e_face
{
	WALL_NO,
	WALL_SO,
	WALL_WE,
	WALL_EA
}					t_face;

typedef struct		s_vector
{
	int				x;
	int				y;
	int				z;
}					t_vector;

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

typedef struct		s_wall
{
	t_face			face;
	t_vector		position;
	char			*texture;
}					t_wall;

typedef struct		s_player
{
	t_vector		position;
	int				speed;
	int				life;
	int				amos;
}					t_player;

typedef struct		s_enemy
{
	t_vector		position;
	char			*texture;
	int				speed;
	int				life;
	int				amos;
}					t_enemy;

typedef struct		s_ceiling
{
	t_color			color;
}					t_ceiling;

typedef struct		s_floor
{
	t_color			color;
}					t_floor;

typedef struct		s_ids
{
	t_id_name		id;
	int				line_nb;
	char			*line;
}					t_ids;

typedef struct		s_map
{
	t_ids			ids[8];
	t_wall			wall[4];
	t_ceiling		ceiling;
	t_floor			floor;
	t_enemy			enemy;
	t_list			*map_lines;
	
}					t_map;

typedef struct		s_cub3d
{
	t_map			map;
	t_player		player;
	t_window		window;
}					t_cub3d;

t_cub3d				*parse_map(const char *file);
t_ids				get_ids(t_cub3d *cub, char *line, int line_nb, int *i);
int					is_valid_mapline(char *line);
void				get_resolution(t_cub3d *cub);
void				get_tex_path(t_cub3d *cub);
t_color				get_color(t_cub3d *cub, int i);

void				error_manager(int type, t_cub3d *cub, char **dbl_array);
t_cub3d				*init_cub(t_cub3d *cub, int size);
const char 			*get_id_enum_name(t_id_name id);
void				free_cub(t_cub3d *cub);
void				free_ids(t_ids *ids);

#endif
