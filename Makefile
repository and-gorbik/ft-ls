NAME = ft_ls
SRCS = srcs/*.c
LIBFT = libft/
INCS = -I ./includes/ -I ./$(LIBFT)
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@make -C $(LIBFT)
	@gcc $(FLAGS) $(SRCS) $(INCS) -lft -L $(LIBFT) -o $(NAME)

clean:
	@make -C $(LIBFT) clean

fclean: clean
	@make -C $(LIBFT) fclean
	@/bin/rm -rf $(NAME)

re: fclean all


