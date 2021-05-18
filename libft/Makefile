NAME		= libft.a

SRCS		= \
ft_iswhitespace.c ft_isalnum.c ft_isprint.c ft_memcmp.c \
ft_putstr_at_fd.c ft_putchar_fd.c ft_split.c ft_split_utils.c ft_char_ischars.c \
ft_strlcat.c ft_strncmp.c ft_substr.c ft_atoi.c ft_isalpha.c ft_ischar.c \
ft_itoa.c ft_free_dbl_array.c ft_char_ischars.c ft_lstfirst.c \
ft_itoa_ui.c ft_itoa_base.c ft_memcpy.c ft_putendl_fd.c ft_strchr.c ft_strlcpy.c \
ft_strnstr.c ft_tolower.c ft_bzero.c ft_isascii.c ft_memccpy.c ft_memmove.c \
ft_putnbr_fd.c ft_strdup.c ft_strlen.c ft_strrchr.c ft_toupper.c ft_calloc.c \
ft_isdigit.c ft_memchr.c ft_memset.c ft_putstr_fd.c ft_strjoin.c ft_strmapi.c \
ft_strtrim.c ft_chr_index.c ft_char_to_str.c ft_lstnew.c ft_lstadd_front.c \
ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstclear.c ft_lstdelone.c \
ft_lstiter.c ft_lstmap.c ft_lstnew_addback.c \
ft_math.c ft_vec3_sub.c ft_vec3_create.c ft_vec3_normalize.c \
ft_color.c ft_get_time.c \

VPATH			= srcs includes $(MATH) $(GRAPHIC) $(TIME)

MATH			= ./srcs/math
GRAPHIC			= ./srcs/graphic
TIME			= ./srcs/time
INCLUDES		= ./includes
OBJS_DIR		= ./objects

FLAGS			= -Wall -Wextra -Werror
OPT				= -O3 -flto -Ofast -ffast-math -march=native 
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

all:				$(NAME)

$(NAME):			$(OBJS)
						@ar rc $@ $^
						@printf "\033[2K\r$(BLUE)$(NAME)$(RESET)$(BLUEE): $(GREEN)Compiled [√]$(RESET)\n"

$(OBJS_DIR)/%.o:	%.c libft.h split_utils.h
						@gcc $(FLAGS) $(OPT) -I$(INCLUDES) -c $< -o $@
						@printf "\033[2K\r$(BLUE)$(NAME)$(RESET)$(BLUE): $(PURPLE)$<$(RESET)"

clean:
						@rm -f $(OBJS)

fclean:				clean
						@rm -f $(NAME)

re:					fclean all

.PHONY:				all clean fclean re
