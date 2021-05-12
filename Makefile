NAME		= Cub3D

SRCS		= \
$(addprefix ./files/game/, input.c input_2.c input_3.c) \
$(addprefix ./files/, cub3d.c) \
$(addprefix ./files/game/engine/, calculations.c draw.c engine.c \
texture.c check_intersections.c draw_textures.c rays.c multi_thread.c sprites.c \
sprites_2.c) \
$(addprefix ./files/game/utils/, fps.c screenshot.c) \
$(addprefix ./files/parser/, get_colors.c get_ids.c get_map_infos.c \
get_resolution.c get_tex_path.c parse_map.c planes.c) \
$(addprefix ./files/utils/, errors_2.c errors.c free.c utils.c) \
$(addprefix ./libft/gnl/, get_next_line.c get_next_line_utils.c)

FLAGS		= -g -Wall -Wextra -Werror
MLX			= -L ./minilibx/ -lmlx
OPT			= -O3 -flto -Ofast -ffast-math -march=native 
INCLUDES	= ./includes
LIBFT		= -L ./libft -lft
LIBFT_PATH	= ./libft
MLX_PATH	= ./minilibx
GNL_PATH	= ./libft/gnl
OBJS_FOLDER	= ./objects
OBJS		= $(SRCS:.c=.o)

all:				libs $(NAME)

libs:		
						@make -C ./libft

$(NAME):			$(OBJS)
						@echo "\033[33m[Compiling Cub3D...]"
						@gcc $(FLAGS) $(MLX) $(LIBFT) $^ -o $@
						@echo "\033[32m[Cub3D compiled !]"

%.o:				%.c $(MLX_PATH)/mlx.h $(INCLUDES)/cub3d.h \
					$(INCLUDES)/event.h $(INCLUDES)/inputs.h \
					$(GNL_PATH)/get_next_line.h $(LIBFT_PATH)/libft.a
						@gcc $(FLAGS) $(OPT) -I$(INCLUDES) -I$(LIBFT_PATH) -I$(GNL_PATH) \
						-I$(MLX_PATH) -c $< -o $@

clean:
						@echo "\033[33m[Cleaning Cub3D...]"
						@rm -f $(OBJS)
						@echo "\033[33m[Cleaning Libft...]"
						@make -C $(LIBFT_PATH) clean

fclean:				clean
						@rm -f $(NAME)
						@make -C $(LIBFT_PATH) fclean 

re:					fclean all

.PHONY:				all clean fclean re libs
