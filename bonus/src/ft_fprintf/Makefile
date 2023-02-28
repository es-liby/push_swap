CC := cc
CFLAGS := -Wall -Werror -Wextra
AR := ar rc
RM := rm -f

NAME := ../../lib/libftfprintf.a
INCLUDE := -I ../../includes/
HEADER := ../../includes/ft_fprintf.h
OBJ_DIR := ../../obj/

SRCS := ft_fprintf.c	\
		ft_handle.c	\
		ft_sublibft.c
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