NAME = ft_display_file
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
MY_SOURCES = $(shell find . -name '*.c')
MY_OBJECTS = $(MY_SOURCES:.c=.o)
HEADERS = -I includes
LIBC = ar rcs
LIBR = ranlib

.c.o:
	$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

$(NAME): $(MY_OBJECTS)
	$(LIBC) $(NAME) $(MY_OBJECTS)
	$(LIBR) $(NAME)

clean:
	$(RM) $(MY_OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
