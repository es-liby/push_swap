CC := cc
CFLAGS := -Wall -Wextra -Werror
RM := rm -rf

NAME := ../checker
INCLUDE := -I ./includes/
HEADERS := ./includes/push_swap_bonus.h	\
			./includes/libft.h	\
			./includes/ft_fprintf.h	\
			./includes/get_next_line.h

OBJ_DIR := ./obj/
SRC_DIR := ./src/
LIB_DIR := ./lib/

LIBS = $(LIB_DIR)*.a

SRCS := checker.c	\
		swap_push.c	\
		rotate.c	\
		reverse_rotate.c	\
		split_args.c	\
		parse_bonus.c
LIBFT_SRCS = $(SRC_DIR)libft/*.c
FPRINTF_SRCS = $(SRC_DIR)ft_fprintf/*.c
GET_NEXT_LINE_SRCS = $(SRC_DIR)get_next_line/*.c

OBJS = $(addprefix $(OBJ_DIR),$(SRCS:%.c=%.o))

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(SRC_DIR)libft
	@make -C $(SRC_DIR)ft_fprintf
	@make -C $(SRC_DIR)get_next_line
	$(CC) $^ $(LIBS) -o $@

$(OBJ_DIR)%.o: %.c $(LIBFT_SRCS) $(FPRINTF_SRCS) $(GET_NEXT_LINE_SRCS) $(HEADERS)
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(LIB_DIR)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	$(RM) $(OBJ_DIR)
fclean: clean
	$(RM) $(LIB_DIR)
	$(RM) $(NAME)
re: fclean all