# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/10 17:15:49 by bebrandt          #+#    #+#              #
#    Updated: 2024/01/21 18:25:13 by bebrandt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	libft.a

OBJ_DIR			=	objs/

LIBFT_DIR		=	libft_srcs/

LIBFT_SRCS		=	ft_atoi.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
					ft_isdigit.c ft_isprint.c ft_strchr.c ft_strlcpy.c ft_strlen.c ft_strncmp.c \
					ft_strnstr.c ft_strrchr.c ft_tolower.c ft_toupper.c ft_strlcat.c \
					ft_memset.c ft_memcpy.c ft_memmove.c ft_memcmp.c ft_memchr.c \
					ft_bzero.c ft_strdup.c ft_calloc.c ft_substr.c ft_strjoin.c \
					ft_strtrim.c ft_split.c ft_itoa.c ft_itoa_hex.c ft_itoa_uint.c \
					ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
					ft_putnbr_hex_fd.c ft_putnbr_uint_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
					ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
					ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c \
					ft_atoli.c
					
LIBFT_OBJ		=	$(LIBFT_SRCS:.c=.o)

LIBFT_OBJS		= 	$(addprefix $(OBJ_DIR),$(LIBFT_OBJ))

GNL_DIR			=	gnl_srcs/

GNL_SRCS		=	ft_get_next_line.c ft_get_next_line_utils.c

GNL_OBJ			=	$(GNL_SRCS:.c=.o)

GNL_OBJS		= 	$(addprefix $(OBJ_DIR),$(GNL_OBJ))

FT_PRINTF_DIR	=	ft_printf_srcs/

FT_PRINTF_SRCS	=	ft_printf.c flag_utils.c ft_is_specifier.c \
					ft_print_char.c ft_print_str.c ft_print_int.c ft_print_uint.c \
					ft_print_arg.c ft_print_hex.c ft_print_ptr.c ft_print_percent.c \
					ft_print_decimal.c ft_print_width_fd.c ft_print_precision_fd.c \
					ft_print_hex_format.c set_lst.c

FT_PRINTF_OBJ	=	$(FT_PRINTF_SRCS:.c=.o)

FT_PRINTF_OBJS	= 	$(addprefix $(OBJ_DIR),$(FT_PRINTF_OBJ))

HDRS			=	-Iincludes/.

CC				=	gcc $(HDRS)

CFLAGS			=	-Wall -Wextra -Werror

AR				=	ar rcs

RM				=	rm -f


RED			=	\033[0;31m

GREEN		=	\033[0;32m

NONE		=	\033[0m

all:	$(NAME)

$(OBJ_DIR)%.o:	$(LIBFT_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@echo "$(GREEN)##### Creating" [ $@ ] " #####$(NONE)"
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)%.o:	$(GNL_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@echo "$(GREEN)##### Creating" [ $@ ] " #####$(NONE)"
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)%.o:	$(FT_PRINTF_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@echo "$(GREEN)##### Creating" [ $@ ] " #####$(NONE)"
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME):	$(LIBFT_OBJS) $(GNL_OBJS) $(FT_PRINTF_OBJS)
	@$(AR) $(NAME) $^

clean:
	@$(RM) $(LIBFT_OBJS)
	@$(RM) $(GNL_OBJS)
	@$(RM) $(FT_PRINTF_OBJS)
	@echo "$(RED)##### Removed libft object files #####$(NONE)"

fclean:	clean
	@$(RM) $(NAME)
	@echo "$(RED)##### Removed libft binary file #####$(NONE)"

re:	fclean all

.PHONY: all clean fclean re
