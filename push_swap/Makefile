# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rtwitch <rtwitch@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/13 12:20:02 by rtwitch           #+#    #+#              #
#    Updated: 2021/12/16 17:40:29 by rtwitch          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = GCC
CFLAGS = -Wall -Wextra -Werror
SRC = 	./sources/push_swap.c\
		./sources/swap_rr.c\
		./sources/swap_rrr.c\
		./sources/swap_ss.c\
		
OBJ = $(SRC:.c=.o)

HEADER = push_swap.h

RM = rm -rf

.PONY: all clean fclean re

all: $(NAME)

%.o: %.c $(HEADER)
		$(CC) $(CFLAG) -c $< -o $@

$(NAME): $(OBJ)
	ar crs $(NAME) $?

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all