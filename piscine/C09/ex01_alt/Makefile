CC = cc
CFLAGS = -Wall -Wextra -Werror -c
AR = ar
ARFLAGS = rcs
RM = rm -f
SRC_DIR = srcs
INC_DIR = includes
SRC_FILES = $(SRC_DIR)/ft_putchar.c $(SRC_DIR)/ft_swap.c $(SRC_DIR)/ft_putstr.c $(SRC_DIR)/ft_strlen.c $(SRC_DIR)/ft_strcmp.c
OBJ_FILES = $(SRC_FILES:.c=.o)
LIB_NAME = libft.a

all: $(LIB_NAME)

%.o: %.c $(INC_DIR)/ft.h
	$(CC) $(CFLAGS) $< -o $@ -I $(INC_DIR)

$(LIB_NAME): $(OBJ_FILES)
	$(AR) $(ARFLAGS) $@ $(OBJ_FILES)

clean:
	$(RM) $(OBJ_FILES)

fclean: clean
	$(RM) $(LIB_NAME)

re: fclean all

.PHONY: all clean fclean re
