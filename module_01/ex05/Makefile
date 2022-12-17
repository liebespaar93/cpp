# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/02 18:06:45 by kyoulee           #+#    #+#              #
#    Updated: 2022/12/17 14:47:06 by kyoulee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = harlFilter

CC = clang++

CFLAGS = -Wall -Wextra -Werror -std=c++98

IFLAGS = -I ./

DFLAGS = 

CXXFLAGS = 

SRC =	main.cpp	\
		Harl.cpp

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