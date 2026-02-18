# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cpicon-m <cpicon-m@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/17 15:00:00 by cpicon-m          #+#    #+#              #
#    Updated: 2026/02/18 19:03:04 by cpicon-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = push_swap
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -I. # Flags obligatorios y búsqueda de cabeceras en el directorio actual

# Fuentes (Detecta tus archivos actuales)
SRC         = push_swap.c \
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

# Regla para compilar el ejecutable final
$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "Push_swap compilado con éxito."
# Compilación de objetos individuales
%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

# Limpieza de archivos objeto
clean:
	@rm -f $(OBJ)
	@echo "Objetos eliminados."

# Limpieza total
fclean: clean
	@rm -f $(NAME)
	@echo "Ejecutable y librerías eliminados."

# Recompilación total
re: fclean all

.PHONY: all clean fclean re