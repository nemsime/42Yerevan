CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
NAME = pipex
SRCS = pipex.c utils.c errors.c

OBJS = $(SRCS:.c=.o)

LIBFT = libft/libft.a

HEADER = pipex.h

all: $(NAME)
	@$(MAKE) all -C libft
$(NAME): $(OBJS)
	@$(MAKE) -C libft
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@
	

clean:
	$(RM) $(OBJS)
	@$(MAKE) clean -C libft

fclean: clean
	$(RM) $(NAME) 
	@$(MAKE) fclean -C libft

re: fclean all
	@$(MAKE) re -C libft

.PHONY: all clean fclean re