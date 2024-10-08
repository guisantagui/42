#!/bin/bash

NAME="libft.a"

MY_SOURCES="ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c"

MY_OBJECTS=$(echo "$MY_SOURCES" | sed 's/\.c/\.o/g')

gcc -Werror -Wextra -Wall -c $MY_SOURCES
ar rcs $NAME $MY_OBJECTS
