# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wayden <wayden@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/14 12:12:31 by wayden            #+#    #+#              #
#    Updated: 2023/03/19 11:03:01 by wayden           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3 

FILES = main singleton fractal color utils hooker

LIBFT_DIR = ./Libs/Libft/
LIBFTFILES = libft
DIR = ./src/

LIBFT_SRC = $(addprefix $(LIBFT_DIR), $(addsuffix .a, $(LIBFTFILES)))
SRCS   = $(addprefix $(DIR), $(addsuffix .c, $(FILES)))
OBJ	   = $(addprefix $(DIR), $(addsuffix .o, $(FILES)))

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT_SRC)
	$(CC) $(OBJ) $(LIBFT_SRC) -Lmlx_linux -lmlx_Linux -L/Libs/ -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

$(LIBFT_SRC):
	$(MAKE) -C $(LIBFT_DIR)
	
%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

clean:
	rm -rf ${OBJ}
	$(MAKE) -C $(LIBFT_DIR) clean
	
fclean: clean
	rm -rf $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	
re: fclean all
.PHONY: