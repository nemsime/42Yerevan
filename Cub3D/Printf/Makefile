CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
LIBC = ar -rcs
NAME = libftprintf.a

SRCS = ft_printf.c ft_utils.c ft_hex.c ft_handle_format.c

OBJS = $(SRCS:.c=.o)

HEADER = ft_printf.h

%.o: %.c $(HEADER) 
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS) 
	$(LIBC) $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
