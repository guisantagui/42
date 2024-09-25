NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
SRCS = srcs/ft_putchar.c \
       srcs/ft_putstr.c \
       srcs/ft_swap.c \
       srcs/ft_strlen.c \
       srcs/ft_strcmp.c
OBJS = $(SRCS:.c=.o)
LIBC = ar rcs
HEADERS = -I includes

all: $(NAME)

$(NAME): $(OBJS)
	$(LIBC) $(NAME) $(OBJS)

.c.o:
	$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
