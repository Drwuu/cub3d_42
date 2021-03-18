/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 10:45:10 by lwourms           #+#    #+#             */
/*   Updated: 2021/03/18 15:58:02 by lwourms          ###   ########.fr       */
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

typedef enum		e_direction
{
	DIR_NO = 1,
	DIR_SO,
	DIR_WE,
	DIR_EA
}					t_direction;

typedef struct		s_vec3
{
	int				x;
	int				y;
	int				z;
}					t_vec3;

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

typedef struct		s_player
{
	t_vec3			position;
	t_direction		direction;
	int				fov;
	int				speed;
	int				life;
	int				amos;
}					t_player;

typedef struct		s_enemy
{
	t_vec3			position;
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

typedef struct		s_map
{
	int				**map;
	t_vec3			size;
	t_ceiling		ceiling;
	t_floor			floor;
	t_enemy			*enemy;
	int				enemy_nb;
	char			*wall_tex[4];
	char			*sprite_tex;
	t_list			*garbage_maplines;
	t_list			*garbage_idlines;
}					t_map;

typedef struct		s_cub3d
{
	t_map			map;
	t_player		player;
	t_window		window;
	t_enemy			*enemy;
}					t_cub3d;

t_cub3d				*parse_map(const char *file);
int					is_valid_mapline(char *line);
int					is_valid_next(char *line, int i);
void				check_id_lines(t_cub3d *cub, t_list *id_lines);
int					is_id(const char *line);
void				get_resolution(t_cub3d *cub, char *line);
char				*get_tex_path(t_cub3d *cub, char *line);
t_color				get_color(t_cub3d *cub, char *line);
void				get_map_info(t_cub3d *cub);

void				error_manager(int type, t_cub3d *cub, \
					void *data, void **dbl_str);
t_cub3d				*init_cub(t_cub3d *cub, int size);
void				free_cub(t_cub3d *cub);

#endif
