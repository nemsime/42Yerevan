CC = cc
SRCS = src/so_long.c src/player_move.c src/mlx.c src/map_validation2.c src/map_validation.c src/map_copying.c src/init_and_creat.c src/errors.c src/frees.c
OBJ = $(SRCS:%.c=%.o)
CFLGS = -Wall -Wextra -Werror
MLXFLAGS = -lmlx -Lmlx -Imlx -lXext -lX11 -lm -lz
LIBFT = libft/libft.a
NAME = so_long
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft
	@$(CC) -o $(NAME) $(OBJ) $(LIBFT) $(MLXFLAGS)

%.o: %.c
	@$(CC) $(CFLGS) -c $< -o $@

clean:
	@make clean -C libft
	@$(RM) $(OBJ)

fclean: clean
	@make fclean -C libft
	@$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
