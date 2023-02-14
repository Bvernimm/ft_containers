NAME		= containers

OBJS		= ${SRCS:.cpp=.o}
SRCS		= main.cpp 

CXXFLAGS	= -Wall -Wextra -Werror -std=c++98
CXX			= c++

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME): $(OBJS)
		$(CXX) $(OBJS) $(CXXFLAGS) -o $(NAME)

all: $(NAME)

clean:
		rm -rf $(OBJS)

fclean: clean
		rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re