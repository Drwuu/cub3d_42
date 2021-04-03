/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 10:45:10 by lwourms           #+#    #+#             */
/*   Updated: 2021/04/03 20:11:36 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <fcntl.h>
# include "event.h"
# include "../tools/libft/libft.h"
# include "../tools/gnl/get_next_line.h"
# include "../tools/minilibx/mlx.h"

typedef struct	s_image
{
	void	*image;
	char	*addr;
	int		bits_per_pixel;
	int		line_size;
	int		endian;
}	t_image;

typedef struct	s_window
{
	int	width;
	int	height;
}	t_window;

typedef struct	s_color
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	unsigned char	a;
}	t_color;

typedef union	u_union
{
	t_color			color;
	unsigned int	c_color;
}	t_union;

typedef struct	s_vec3
{
	float	x;
	float	y;
	float	z;
}	t_vec3;

typedef struct	s_player
{
	t_vec3	pos;
	float	yaw;
	int		speed;
	int		life;
	int		amos;
}	t_player;

typedef struct	s_enemy
{
	t_vec3	position;
	int		speed;
	int		life;
	int		amos;
}	t_enemy;

typedef struct	s_ceiling
{
	t_color	color;
}	t_ceiling;

typedef struct	s_floor
{
	t_color	color;
}	t_floor;

typedef struct	s_map
{
	int			**map;
	t_vec3		size;
	t_ceiling	ceiling;
	t_floor		floor;
	t_enemy		*enemy;
	int			enemy_nb;
	char		*wall_tex[4];
	char		*sprite_tex;
	t_list		*maplines;
	t_list		*idlines;
}	t_map;


typedef struct	s_rays
{
	t_vec3			**vector;
	t_vec3			inters;
	float			dist_save;
	float			ray_interval[2];
}	t_rays;

typedef struct	s_plane
{
	float	A;
	float	B;
	float	C;
	float	D;
}	t_plane;

typedef struct	s_settings
{
	t_window	window;
	int			fov;
}	t_settings;

typedef struct	s_cub3d
{
	t_settings	settings;
	t_player	player;
	t_map		map;
	t_image		image;
	t_rays		rays;
	t_plane		**planes;
	t_enemy		*enemy;
	void		*mlx;
	void		*win;
}	t_cub3d;

void		parse_map(const char *file, t_cub3d *cub);
int			is_valid_mapline(char *line);
int			is_valid_next(char *line, int i);
void		check_id_lines(t_cub3d *cub, t_list *id_lines);
int			is_id(const char *line);
void		get_resolution(t_cub3d *cub, char *line);
char		*get_tex_path(t_cub3d *cub, char *line);
t_color		get_color(t_cub3d *cub, char *line);
void		get_map_info(t_cub3d *cub);
t_plane		**init_planes(t_cub3d *cub);
void		get_planes(t_cub3d *cub, t_plane ***planes, int **map, int i);

void		init_user_mlx_image(t_cub3d *cub);

void		init_rays(t_cub3d **cub);
t_player	init_player(int life, int amos, int speed);
void		launch_game(t_cub3d *cub);
t_vec3		rotate_x(t_vec3 vector, float angle_rad);
t_vec3		rotate_z(t_vec3 vector, float angle_rad);
void		trace_north_ray(t_cub3d *cub, t_vec3 ray_origin, int i, int j);
void		trace_south_ray(t_cub3d *cub, t_vec3 ray_origin, int i, int j);
void		trace_east_ray(t_cub3d *cub, t_vec3 ray_origin, int i, int j);
void		trace_west_ray(t_cub3d *cub, t_vec3 ray_origin, int i, int j);
void		draw(t_cub3d *cub);
void		draw_pixel(t_cub3d *cub, int i, int j, unsigned int wall_color);

void		error_manager(int type, t_cub3d *cub, \
			void *data, void **dbl_str);
void		free_cub(t_cub3d *cub);

#endif
