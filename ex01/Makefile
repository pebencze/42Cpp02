NAME 			= 	fixed
CXX 			= 	c++
CXXFLAGS 		= 	-Wall -Wextra -Werror -std=c++98

OBJS = ${SRCS:.cpp=.o}
SRCS = main.cpp Fixed.cpp
INCL = Fixed.hpp

all: $(NAME)

%.o: %.cpp $(INCL)
	$(CXX) $(CXXFLAGS)  -c $< -o $@

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
