/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 10:45:10 by lwourms           #+#    #+#             */
/*   Updated: 2021/04/24 18:30:28 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <fcntl.h>
# include <time.h>
# include <pthread.h>
# include "event.h"
# include "../libft/libft.h"
# include "../libft/gnl/get_next_line.h"
# include "../minilibx/mlx.h"

typedef struct	s_image
{
	void			*image;
	unsigned int	*addr;
	int				bits_per_pixel;
	int				line_size;
	int				endian;
	int				width;
	int				height;
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

typedef struct	s_plane
{
	float	A;
	float	B;
	float	C;
	float	D;
}	t_plane;

typedef struct	s_player
{
	t_vec3	start_pos;
	t_vec3	pos;
	float	yaw;
	float	cos_yaw;
	float	sin_yaw;
	float	speed;
	int		life;
	int		amos;
}	t_player;

typedef struct	s_sprite
{
	t_plane	plane;
	t_vec3	pos;
	t_vec3	v;
	t_image	texture;
}	t_sprite;

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
	t_sprite	*sprites;
	int			sprites_nb;
	char		*wall_tex[4];
	char		*sprite_tex;
	t_list		*maplines;
	t_list		*idlines;
}	t_map;


typedef struct	s_rays
{
	t_vec3	**vector;
	t_vec3	inters;
	float	**dist_save;
	float	ratio[2];
}	t_rays;


typedef struct	s_settings
{
	t_window	user_screen_size;
	t_window	window;
	t_bool		multi_thread;
	int			fov;
	int			key[6];
}	t_settings;

typedef struct	s_fps
{
	float		frame;
	char		*fps;
	char		*join;
	time_t		start;
	time_t		current;
}	t_fps;

typedef struct	s_engine
{
	t_image		game_image;
	t_image		texture[4];
	t_rays		rays;
	t_plane		**planes;
	t_fps		fps;
}	t_engine;


typedef struct	s_cub3d
{
	t_settings	settings;
	t_player	player;
	t_map		map;
	t_engine	engine;
	t_sprite	*sprite;
	void		*mlx;
	void		*win;
}	t_cub3d;

typedef struct	s_thread
{
	t_cub3d		*cub;
	int			start;
	int			end;
}	t_thread;

void			parse_map(const char *file, t_cub3d *cub);
int				is_valid_mapline(char *line);
int				is_valid_next(char *line, int i);
void			check_id_lines(t_cub3d *cub, t_list *id_lines);
int				is_id(const char *line);
void			get_resolution(t_cub3d *cub, char *line);
char			*get_tex_path(t_cub3d *cub, char *line);
t_color			get_color(t_cub3d *cub, char *line);
void			get_map_info(t_cub3d *cub);
t_plane			**init_planes(t_cub3d *cub);
void			get_planes(t_cub3d *cub, t_plane ***planes, int **map, int i);
t_sprite		get_sprite_info(t_cub3d *cub);
t_image			get_texture(t_cub3d *cub, char *text_path);
t_sprite		*set_sprites(t_cub3d *cub);

void			init_rays(t_cub3d **cub);
t_vec3			get_intersect(t_cub3d *cub, t_vec3 origin, float distance);
t_bool			is_intersect_north(t_cub3d *cub, t_vec3 intersect, int y);
t_bool			is_intersect_south(t_cub3d *cub, t_vec3 intersect, int y);
t_bool			is_intersect_east(t_cub3d *cub, t_vec3 intersect, int x);
t_bool			is_intersect_west(t_cub3d *cub, t_vec3 intersect, int x);
t_vec3			rotate_x(t_player player, t_vec3 vector);
t_vec3			rotate_z(t_player player, t_vec3 vector);
t_vec3			move_player_x(t_player player, int direction);
t_vec3			move_player_y(t_player player, int direction);

void			start(t_cub3d *cub);
void			update_sprite(t_cub3d *cub);
float			get_sprite_ratio(t_vec3 intrsct, t_sprite sprite, \
				t_player player);
unsigned int	get_sprt_pixel(t_cub3d *cub, t_image texture, \
				t_vec3 intersect, float ratio);
t_bool			is_sprt_intrsct(t_cub3d *cub, t_sprite sprt, t_vec3 intrsct);

void			draw(t_cub3d *cub);
void			*draw_thread(void *datas);
void			draw_pixel(t_image game_image, int i, int j, \
				unsigned int color);
void			draw_north(t_cub3d *cub, t_vec3 ray_origin, int i, int j);
void			draw_south(t_cub3d *cub, t_vec3 ray_origin, int i, int j);
void			draw_east(t_cub3d *cub, t_vec3 ray_origin, int i, int j);
void			draw_west(t_cub3d *cub, t_vec3 ray_origin, int i, int j);
void			draw_sprites(t_cub3d *cub, t_vec3 ray_origin, int i, int j);
unsigned int	get_pixel_color(t_image texture, t_vec3 intersect, \
				int is_depth);

void			show_fps(t_cub3d *cub);

void			error_manager(int type, t_cub3d *cub, void *data, \
				void **dbl_str);
void			global_errors(int type);
void			free_cub(t_cub3d *cub);

#endif
