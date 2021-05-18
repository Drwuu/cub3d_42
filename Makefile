NAME		= Cub3D

SRCS		= \
input.c input_2.c input_3.c \
cub3d.c calculations.c draw.c engine.c \
texture.c check_intersections.c draw_textures.c draw_textures_2.c \
rays.c multi_thread.c sprites.c sprites_2.c \
fps.c screenshot.c \
get_colors.c get_ids.c get_map_infos.c \
get_resolution.c get_tex_path.c parse_map.c planes.c planes_2.c \
errors_2.c errors.c free.c utils.c \
get_next_line.c get_next_line_utils.c get_next_line_utils_2.c

VPATH		= minilibx $(GNL_PATH) $(INCLUDES) $(LIBFT_PATH) $(FILES) $(GAME) $(ENGINE) \
			$(GAME_UTILS) $(INPUTS) $(PARSER) $(UTILS) $(OBJS_DIR)

FLAGS			= -g -Wall -Wextra -Werror
MLX				= -L ./minilibx/ -lmlx
OPT				= -O3 -flto -Ofast -ffast-math -march=native 
INCLUDES		= ./includes
LIBFT			= -L ./libft -lft
FILES			= ./files
GAME			= ./files/game
ENGINE			= ./files/game/engine
INPUTS			= ./files/game/inputs
GAME_UTILS		= ./files/game/utils
PARSER			= ./files/parser
UTILS			= ./files/utils
GNL				= ./libft/gnl
LIBFT_PATH		= ./libft
MLX_PATH		= ./minilibx
GNL_PATH		= ./libft/gnl
OBJS_DIR		= ./objects
OBJS			= $(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))

BLACK			=	\033[0;30m
RED				=	\033[0;31m
GREEN			=	\033[0;32m
ORANGE			=	\033[0;33m
BLUE			=	\033[0;34m
PURPLE			=	\033[0;35m
CYAN			=	\033[0;36m
LIGHT_GRAY		=	\033[0;37m
DARK_GRAY		=	\033[1;30m
LIGHT_RED		=	\033[1;31m
LIGHT_GREEN		=	\033[1;32m
YELLOW			=	\033[1;33m
LIGHT_BLUE		=	\033[1;34m
LIGHT_PURPLE	=	\033[1;35m
LIGHT_CYAN		=	\033[1;36m
WHITE			=	\033[1;37m
NO_COLOR		=	\033[0m

all:				libs $(NAME)

libs:		
						@make -C ./libft

$(NAME):			$(OBJS)
						@gcc $(FLAGS) $(MLX) $(LIBFT) $^ -o $@
						@printf "\033[2K\r$(BLUE)$(NAME)$(RESET)$(BLUE): $(GREEN)Compiled [√]$(RESET)\n"

$(OBJS_DIR)/%.o:	%.c mlx.h cub3d.h event.h inputs.h get_next_line.h libft.a
						@gcc $(FLAGS) $(OPT) -I$(INCLUDES) -I$(LIBFT_PATH)/includes \
						-I$(GNL_PATH) -I$(MLX_PATH) -c $< -o $@
						@printf "\033[2K\r$(BLUE)$(NAME)$(RESET)$(BLUE): $(PURPLE)$<$(RESET)"

lldb:				$(OBJS)
						@gcc -g $(FLAGS) $(MLX) $(LIBFT) $^ -o $(NAME)
						@printf "\033[2K\r$(BLUE)$(NAME)$(RESET)$(BLUE): $(GREEN)Compiled [√]$(RESET)\n"

fsanitize:			$(OBJS)
						@gcc -fsanitize=address $(FLAGS) $(MLX) $(LIBFT) $^ -o $(NAME)
						@printf "\033[2K\r$(BLUE)$(NAME)$(RESET)$(BLUE): $(GREEN)Compiled [√]$(RESET)\n"

clean:
						@rm -f $(OBJS)
						@make -C $(LIBFT_PATH) clean

fclean:				clean
						@rm -f $(NAME)
						@make -C $(LIBFT_PATH) fclean 

re:					fclean all

.PHONY:				all clean fclean re libs
