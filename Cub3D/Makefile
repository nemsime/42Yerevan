CC = cc
SRCS = src/error_handling.c src/game.c src/parser.c 
CFLGS = -Wall -Wextra -Werror
#MLXFLAGS = -lmlx -Lmlx -Imlx -lXext -lX11 -lm -lz
LIBFT = libft/libft.a
NAME = cub3D
RM = rm -rf
HEADER = include/cub3d.h

OBJ = $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C libft
	$(CC) -o $(NAME) $(OBJ) $(LIBFT) 
#$(MLXFLAGS)

%.o: %.c Makefile 
	$(CC) $(CFLGS) -c $< -o $@

clean:
	$(MAKE) clean -C libft
	$(RM) $(OBJ)

fclean: 
	$(MAKE) fclean -C libft
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re