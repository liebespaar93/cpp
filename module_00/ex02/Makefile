# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/28 13:18:04 by kyoulee           #+#    #+#              #
#    Updated: 2022/12/17 13:49:17 by kyoulee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = account

CC = clang++

CFLAGS = -Wall -Wextra -Werror -std=c++98

IFLAGS = -I ./

SRC =	Account.cpp	\
		tests.cpp	


OBJS = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(IFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) $(IFLAGS) -c $<

clean:
	rm -f $(OBJS)

fclean: OBJS+=$(NAME)
fclean: clean

re: fclean all

.PHONY: all re clean fclean