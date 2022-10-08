# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbraga <bruno.braga.design@gmail.com>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/22 16:47:46 by bbraga            #+#    #+#              #
#    Updated: 2022/10/08 12:23:20 by bbraga           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBFT_DIR = libft
INCLUDE_DIR = includes

MLX_DIR = minilibx
MLX_FLAGS = -L$(MLX_DIR) -lmlx -framework Opengl \
			-framework AppKit
INCLUDES = -I$(INCLUDE_DIR) -I$(LIBFT_DIR) -I$(MLX_DIR)
LIBS = -L$(LIBFT_DIR) -lft

BUILD_DIR = build
SRC_DIR = ./src
SRCS = enemy_props.c event_handler.c files_utils.c game_init.c \
		game_props.c game_utils.c img_handler.c interface.c main.c \
		map_init.c map_props.c map_validation.c move_handler.c \
		player_handler.c player_handler2.c player_props.c  

OBJS = $(SRCS:%.c=$(BUILD_DIR)/%.o)

all: $(NAME)

restart: cbuild $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(INCLUDES) $(LIBS) \
	$(MLX_FLAGS) -o $(NAME)

$(NAME): $(OBJS) libs
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) $(MLX_FLAGS) -o $(NAME)

$(OBJS): $(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	@$(CC) -g $(CFLAGS) $(INCLUDES) -c $< -o $@

libs: 
	@make -C $(LIBFT_DIR)
	@make -C $(MLX_DIR)

bonus: all

re: fclean all

cbuild:
	@rm -rf $(BUILD_DIR)

clean:
	make clean -C $(LIBFT_DIR)
	make clean -C $(MLX_DIR)
	@rm -rf $(BUILD_DIR)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	make fclean -C $(MLX_DIR)
	@rm -rf $(NAME)

.PHONY: all clean fclean re
