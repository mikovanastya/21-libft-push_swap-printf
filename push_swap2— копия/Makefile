# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rtwitch <rtwitch@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/13 12:20:02 by rtwitch           #+#    #+#              #
#    Updated: 2021/12/24 16:53:23 by rtwitch          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = 	sources/push_swap.c\
		sources/count_flag.c\
		sources/push_b.c\
		sources/sort_index.c\
		sources/sort_min.c\
		sources/sort_max.c\
		sources/sorts_push.c\
		sources/sorts_rr.c\
		sources/sorts_rrr.c\
		sources/sorts_ss.c\
		sources/two_three.c\
		sources/check.c\
		sources/last_rotate.c\

CC = GCC

CFLAGS = -Wall -Wextra -Werror -I.
		
OBJS = $(SRC:.c=.o)

HEADER = includes/push_swap.h

RM = rm -rf

.PHONY: all clean fclean re

all: $(NAME)

%.o: %.c $(HEADER)
		$(CC) $(CFLAG) -c $< -o $@

$(NAME): $(OBJS)
	${CC} $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
