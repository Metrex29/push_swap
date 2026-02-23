# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cpicon-m <cpicon-m@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/17 15:00:00 by cpicon-m          #+#    #+#              #
#    Updated: 2026/02/18 21:24:09 by cpicon-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = push_swap
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -I.

SRC           = push_swap.c \
                init_stack.c \
                nodes.c \
                push.c \
                swap.c \
                rotate.c \
                rrotate.c \
                quick_sort.c \
                ksort.c \
                utils.c \
                checkers.c \
                split.c

OBJ         = $(SRC:.c=.o)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re