NAME		= cub3D

SRCS		= cub3d.c \
$(addprefix $(INPUTS)/, input.c input_2.c input_3.c) \
$(addprefix $(ENGINE)/, calculations.c draw.c engine.c \
texture.c check_intersections.c draw_textures.c draw_textures_2.c \
rays.c multi_thread.c sprites.c sprites_2.c) \
$(addprefix $(GAME_UTILS)/, fps.c screenshot.c) \
$(addprefix $(PARSER)/, get_colors.c get_ids.c get_map_infos.c \
get_resolution.c get_tex_path.c parse_map.c planes.c planes_2.c) \
$(addprefix $(UTILS)/, errors_2.c errors.c free.c utils.c)

FLAGS			= -g -Wall -Wextra -Werror
OPT				= -O3 -flto -Ofast -ffast-math -march=native
LIBFT			= -L libft -lft
MLX				= -L minilibx -lmlx
OBJS			= $(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))

OBJS_DIR		= objects
INCLUDES		= includes
LIBFT_PATH		= libft
MLX_PATH		= minilibx

FILES			= files
INPUTS			= game/inputs
ENGINE			= game/engine
GAME_UTILS		= game/utils
PARSER			= parser
UTILS			= utils
FOLDERS			= objects game game/engine game/inputs game/utils parser utils

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

$(OBJS_DIR)/%.o:	$(FILES)/%.c $(addprefix $(INCLUDES)/, cub3d.h enums.h event.h inputs.h tools.h) $(MLX_PATH)/mlx.h $(LIBFT_PATH)/libft.a
						@mkdir -p $(addprefix $(OBJS_DIR)/, $(FOLDERS))
						@gcc $(FLAGS) $(OPT) -I$(INCLUDES) -I$(LIBFT_PATH)/$(INCLUDES) \
						-I$(MLX_PATH) -c $< -o $@
						@printf "\033[2K\r$(BLUE)$(NAME)$(RESET)$(BLUE): $(PURPLE)$<$(RESET)"

lldb:				libs $(OBJS)
						@gcc -g $(FLAGS) $(MLX) $(LIBFT) $(OBJS) -o $(NAME)
						@printf "\033[2K\r$(BLUE)$(NAME)$(RESET)$(BLUE): $(GREEN)Compiled [√]$(RESET)\n"

fsanitize:			libs $(OBJS)
						@gcc -fsanitize=address $(FLAGS) $(MLX) $(LIBFT) $(OBJS) -o $(NAME)
						@printf "\033[2K\r$(BLUE)$(NAME)$(RESET)$(BLUE): $(GREEN)Compiled [√]$(RESET)\n"

clean:
						@rm -f $(OBJS)
						@rm -rf $(addprefix ./, $(FOLDERS))
						@make -C $(LIBFT_PATH) clean

fclean:				clean
						@rm -f $(NAME)
						@make -C $(LIBFT_PATH) fclean 

re:					fclean all

.PHONY:				all clean fclean re libs
