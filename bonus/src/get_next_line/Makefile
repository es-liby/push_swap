CC := cc
CFLAGS := -Wall -Werror -Wextra
AR := ar rc
RM := rm -f

NAME := ../../lib/libgetnextline.a
INCLUDE := -I ../../includes/
HEADER := ../../includes/get_next_line.h
OBJ_DIR := ../../obj/

SRCS := get_next_line.c	\
		get_next_line_utils.c
OBJS = $(addprefix $(OBJ_DIR),$(SRCS:%.c=%.o))

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $@ $^

$(OBJ_DIR)%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	$(RM) $(OBJS)
fclean: clean
	$(RM) $(NAME)
re: fclean all