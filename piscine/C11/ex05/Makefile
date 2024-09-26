NAME = do-op
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
SRCS = srcs/ft_atoi.c \
       srcs/ft_sum.c \
       srcs/ft_rest.c \
       srcs/ft_mult.c \
       srcs/ft_div.c \
       srcs/ft_mod.c \
       srcs/ft_putchar.c \
       srcs/ft_putstr.c \
       srcs/ft_putnbr.c \
       srcs/ft_strlen.c \
       srcs/ft_strcpy.c \
       srcs/op_is_val.c \
       srcs/ft_get_op.c \
       srcs/do_op.c \
       srcs/main.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

.c.o:
	$(CC) $(CFLAGS) -I includes -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
