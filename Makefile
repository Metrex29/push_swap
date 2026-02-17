# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cpicon-m <cpicon-m@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/17 15:00:00 by cpicon-m          #+#    #+#              #
#    Updated: 2026/02/17 15:02:03 by cpicon-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = push_swap
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -I. # Flags obligatorios y búsqueda de cabeceras en el directorio actual

# Directorios
LIBFT_DIR   = libft
LIBFT       = $(LIBFT_DIR)/libft.a

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
              checkers.c

OBJ         = $(SRC:.c=.o)

# Colores para la terminal
GREEN       = \033[0;32m
RESET       = \033[0m

all: $(LIBFT) $(NAME)

# Regla para compilar la libft llamando a su propio Makefile
$(LIBFT):
	@make -C $(LIBFT_DIR)

# Regla para compilar el ejecutable final
$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)
	@echo "$(GREEN)Push_swap compilado con éxito.$(RESET)"

# Compilación de objetos individuales
%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

# Limpieza de archivos objeto
clean:
	@rm -f $(OBJ)
	@make -C $(LIBFT_DIR) clean
	@echo "Objetos eliminados."

# Limpieza total
fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@echo "Ejecutable y librerías eliminados."

# Recompilación total
re: fclean all

.PHONY: all clean fclean re