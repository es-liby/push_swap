# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iabkadri <iabkadri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/05 11:59:17 by iabkadri          #+#    #+#              #
#    Updated: 2023/01/14 12:07:17 by iabkadri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := cc
CFLAGS := -Wall -Werror -Wextra
RM := rm -rf

INCLUDE := -I includes/
HEADERS := includes/push_swap.h		\
			includes/libft.h		\
			includes/ft_fprintf.h

OBJ_DIR := ./obj/
SRC_DIR := ./src/
LIB_DIR := ./lib/

SRCS := main.c	\
		swap_push.c	\
		parse.c	\
		rotate.c	\
		reverse_rotate.c	\
		sort.c	\
		sort_small_stacks.c	\
		lis.c	\
		lis2.c	\
		index.c	\
		best_element.c	\
		rotate_tmp.c	\
		is_sorted.c	\
		calc.c	\
		machines.c	\
		push_to_a.c	\
		error.c
LIBFT_SRCS = $(SRC_DIR)libft/*.c
FPRINTF_SRCS = $(SRC_DIR)ft_fprintf/*.c

OBJS = $(addprefix $(OBJ_DIR),$(SRCS:%.c=%.o))

NAME := push_swap
LIBS = $(LIB_DIR)*.a

.PHONY: all bonus clean fclean re

all: $(NAME)

bonus:
	@make -C bonus

$(NAME): $(OBJS)
	@make -C $(SRC_DIR)libft
	@make -C $(SRC_DIR)ft_fprintf
	$(CC) $^ $(LIBS) -o $@

$(OBJ_DIR)%.o: %.c $(LIBFT_SRCS) $(FPRINTF_SRCS) $(HEADERS)
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(LIB_DIR)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	$(RM) $(OBJ_DIR)
fclean: clean
	$(RM) $(LIB_DIR)
	$(RM) $(NAME)
	@make fclean -C bonus
re: fclean all
