NAME			= libftprintf.a

SRCS			= ft_printf.c ft_printf_utils.c \
ft_print_flags.c ft_print_process.c ft_treat_input.c ft_get_conv.c \
ft_get_flags.c

OBJS			= $(SRCS:.c=.o)

FLAGS			= -Wall -Wextra -Werror

all:			libs $(NAME)

libs:		
				make -C libft

$(NAME):		$(OBJS)
				cp libft/libft.a $(NAME)
				ar rc $@ $^

%.o:			%.c ft_printf.h libft/libft.a
				gcc $(FLAGS) -I . -I libft -c $< -o $@

clean:
				rm -f $(OBJS)
				make -C libft clean

fclean:			clean
				rm -f $(NAME)
				make -C libft fclean 

re:				fclean all

.PHONY:			all clean fclean re libs
