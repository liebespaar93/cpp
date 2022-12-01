# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/28 13:18:04 by kyoulee           #+#    #+#              #
#    Updated: 2022/12/01 21:58:20 by kyoulee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = phonebook

CC = clang++

CFLAGS = -Wall -Wextra -Werror -std=c++98

IFLAGS = -I ./

SRC =	main.cpp	\
		Contact.cpp	\
		PhoneBook.cpp

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