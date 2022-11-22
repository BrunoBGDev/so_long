#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbraga <bruno.braga.design@gmail.com>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/22 16:47:46 by bbraga            #+#    #+#              #
#    Updated: 2022/11/22 10:47:33 by bbraga           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBFT_DIR = libft
INCLUDE_DIR = includes

SRCS_PLATFORM = game_mac.c
MLX_DIR		= minilibx_mac
MLX_FLAGS	= -L$(MLX_DIR) -lmlx -framework OpenGL \
			  -framework AppKit
INCLUDES 	= -I$(INCLUDE_DIR) -I$(LIBFT_DIR) -I$(MLX_DIR)
LIBS		= -L$(LIBFT_DIR) -lft

BUILD_DIR = build
SRC_DIR = ./src
SRCS = $(SRCS_PLATFORM) \
		 main.c interface.c map_init.c \
		 map_validation.c move_handler.c \

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
