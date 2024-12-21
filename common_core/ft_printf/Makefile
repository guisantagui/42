NAME = libftprintf.a
NAMELIBFT = libft.a
LIBFT_PATH = ./libft

SRCS = ft_printf.c \
	   ft_putchar.c \
	   ft_putstr.c \
	   ft_putnbr_base.c \
	   ft_putptr.c

OBJS = ${SRCS:.c=.o}

all:		$(NAME)

makelibft:
	@make -C $(LIBFT_PATH) bonus
	@cp $(LIBFT_PATH)/$(NAMELIBFT) .
	@mv $(NAMELIBFT) $(NAME)

$(NAME): makelibft $(OBJS)
	@ar -r $(NAME) $(OBJS)

clean:
	@rm -f $(OBJS)
	@cd $(LIBFT_PATH) && make clean

fclean: clean
	@rm -f $(OBJS) $(NAME)
	@cd $(LIBFT_PATH) && make fclean

re: fclean all

.PHONY: all clean fclean re
