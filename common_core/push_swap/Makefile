NAME = push_swap
PRINTF_PATH = ./ft_printf
NAMEPRINTF = $(PRINTF_PATH)/libftprintf.a
SRCS_PATH = ./srcs

CC = cc

RM = rm -f

CFLAGS = -Wall -Werror -Wextra
LDFLAGS = -L$(PRINTF_PATH) -lftprintf

SRCS_PRINTF := $(wildcard $(PRINTF_PATH)/*.c)
SRCS := $(wildcard $(SRCS_PATH)/*.c)

OBJS_PRINTF = ${SRCS_PRINTF:.c=.o}
OBJS = ${SRCS:.c=.o}

all:		$(NAME)

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

$(NAME): $(OBJS) $(NAMEPRINTF)
	$(CC) $(OBJS) $(CFLAGS) $(LDFLAGS) -o $(NAME)

$(NAMEPRINTF):
	@make -C $(PRINTF_PATH)

clean:
	${RM} ${OBJS}
	@cd $(PRINTF_PATH) && make clean

fclean: clean
	${RM} ${OBJS} ${NAME}
	@cd $(PRINTF_PATH) && make fclean

re: fclean all

.PHONY: all clean fclean re
