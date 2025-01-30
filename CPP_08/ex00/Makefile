CC = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
Header = easyfind.hpp
RM = rm -f
SRCS = main.cpp
NAME = easyfind
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS) $(Header)
	$(CC) $(CPPFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re