# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agirona <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/25 10:38:50 by agirona           #+#    #+#              #
#    Updated: 2023/01/25 10:43:27 by agirona          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = Container

FT_NAME = FT_Container

STD_NAME = STD_Container

FT_SRC = main/ft_main.cpp

STD_SRC = main/std_main.cpp

INCLUDE_PATH = .

HEADER = vector.tpp vector.hpp ../iterator/random_access_iterator.tpp ../iterator/random_access_iterator.hpp \
		 ../iterator/reverse_iterator.tpp ../iterator/reverse_iterator.hpp ../other/enable_if.hpp \
		 ../other/is_integral.hpp ../other/equal.hpp ../other/lexicographical_compare.hpp \
		../iterator/iterator_traits.hpp ../iterator/random_access_iterator_tag.hpp

FT_OBJ = $(FT_SRC:.cpp=.o)

STD_OBJ = $(STD_SRC:.cpp=.o)

CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -I $(INCLUDE_PATH)

%.o: %.cpp $(HEADER)
	c++ $(CPPFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(FT_NAME) $(STD_NAME)

$(FT_NAME): $(FT_OBJ)
		c++ $(CPPFLAGS) $(FT_OBJ) -o $(FT_NAME)

$(STD_NAME): $(STD_OBJ)
		c++ $(CPPFLAGS) $(STD_OBJ) -o $(STD_NAME)

clean:
		rm -f $(STD_OBJ)
		rm -f $(FT_OBJ)

fclean : clean
	rm -f $(FT_NAME)
	rm -f $(STD_NAME)

re :	fclean all

.PHONY: all clean fclean re
