# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: intra42 <intra42@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/06 04:10:04 by intra42           #+#    #+#              #
#    Updated: 2022/12/07 19:19:29 by intra42          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = a.out

CC = clang++

CFLAGS = -Wall -Wextra -Werror -std=c++98  -Wshadow

IFLAGS = -I ./

DFLAGS = 

CXXFLAGS = 

SRC =	main.cpp	\
		AAnimal.cpp	\
		Cat.cpp		\
		Dog.cpp		\
		Brain.cpp

OBJS = $(SRC:.cpp=.o)

all: $(NAME)

play : DFLAGS+= -D PLAY
play : CXXFLAGS+= -pedantic -g3 -fsanitize=address -fsanitize=undefined -fsanitize=bounds -fsanitize=null
play : $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(IFLAGS) $(DFLAGS) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) $(IFLAGS) $(DFLAGS) $(CXXFLAGS) -c $<

clean:
	rm -f $(OBJS)

fclean: OBJS+=$(NAME)
fclean: clean

re: fclean all

.PHONY: all re clean fclean play