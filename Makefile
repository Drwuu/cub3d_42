NAME		= Cub3D

SRCS		= cub3d.c \
$(addprefix ./files/game/, input.c) \
$(addprefix ./files/game/engine/, calculations.c draw.c engine.c \
texture.c check_intersections.c draw_walls.c rays.c) \
$(addprefix ./files/game/utils/, fps.c) \
$(addprefix ./files/parser/, get_colors.c get_ids.c get_map_info.c \
get_resolution.c get_tex_path.c parse_map.c planes.c) \
$(addprefix ./files/utils/, errors_2.c errors.c free.c utils.c) \
$(addprefix ./tools/gnl/, get_next_line.c get_next_line_utils.c)

FLAGS		= -Wall -Wextra -Werror
MLX			= -L ./tools/minilibx -lmlx
OPT			= -O3 -ffast-math -march=native
INCLUDES	= ./includes
LIBFT_PATH	= ./tools/libft
GNL_PATH	= ./tools/gnl
OBJS		= $(SRCS:.c=.o)

all:		libs $(NAME)

libs:		
				make -C ./tools/libft

$(NAME):	$(OBJS)
				cp $(LIBFT_PATH)/libft.a $(NAME)

%.o:		%.c $(INCLUDES)/cub3d.h $(INCLUDES)/event.h \
			$(GNL_PATH)/get_next_line.h $(LIBFT_PATH)/libft.a
				@echo "\033[33m[Compiling Cub3D...]"
				gcc $(MLX) -I$(INCLUDES) -I$(LIBFT_PATH) -I$(GNL_PATH) -c $< -o $@
				@echo "\033[32m[Done !]"
clean:
				rm -f $(OBJS)
				make -C $(LIBFT_PATH) clean

fclean:		clean
				rm -f $(NAME)
				make -C $(LIBFT_PATH) fclean 

re:			fclean all

.PHONY:		all clean fclean re libs
