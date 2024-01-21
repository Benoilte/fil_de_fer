# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/04 11:59:35 by bebrandt          #+#    #+#              #
#    Updated: 2024/01/21 18:33:18 by bebrandt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	fdf

SRCS_DIR	=	srcs/

FDF_SRCS	=	fdf.c

FDF_OBJ 	= $(FDF_SRCS:.c=.o)

FDF_OBJS 	= $(addprefix $(OBJ_DIR),$(FDF_OBJ))

LIBFT_DIR	=	libft/

LIBFT_NAME	=	libft.a

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror -g

RM			=	rm -f

OBJ_DIR		=	objs/

UNAME 		= $(shell uname)

MLX_LIB 	= $(MLX_DIR)/libmlx.a

ifeq ($(UNAME), Linux)
	INCLUDES = -I/usr/include -Iminilibx-linux -Ilibft
	MLX_DIR = ./minilibx-linux
else
	INCLUDES = -Iminilibx_macos -Ilibft
	MLX_DIR = ./minilibx_macos
endif

ifeq ($(shell uname), Linux)
	MLX_FLAGS = -L$(MLX_DIR) -lmlx -L/usr/lib/X11 -lXext -lX11
else
	MLX_FLAGS = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
endif

RED			=	\033[0;31m
GREEN		=	\033[0;32m
NONE		=	\033[0m

all: $(MLX_LIB) $(LIBFT_DIR)$(LIBFT_NAME) $(NAME)

$(NAME): $(FDF_OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $@ -L$(LIBFT_DIR) -lft $(MLX_FLAGS)

$(LIBFT_DIR)$(LIBFT_NAME):
	@make -C $(LIBFT_DIR)

$(OBJ_DIR)%.o: $(SRCS_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@echo "$(GREEN)##### Creating" [ $@ ] " #####$(NONE)"
	@$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES)

$(MLX_LIB):
	@make -C $(MLX_DIR)

clean:
	@make -C $(LIBFT_DIR) clean
	@make -C $(MLX_DIR) clean
	@rm -f $(FDF_OBJS)
	@echo "$(RED)##### Removed object files #####$(NONE)"

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@make -C $(MLX_DIR) clean
	@rm -f $(NAME)
	@echo "$(RED)##### Removed binary files #####$(NONE)"

re: fclean all

.PHONY: all clean fclean re
