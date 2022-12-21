# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/28 13:18:04 by kyoulee           #+#    #+#              #
#    Updated: 2022/12/21 10:23:03 by kyoulee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = account

CC = c++

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