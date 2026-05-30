CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = megaphone.cpp 
OBJS = $(SRCS:.cpp=.o)
NAME = megaphone

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re