NAME_C = client
NAME_S = server

NAME_CBONUS = client_bonus
NAME_SBONUS = server_bonus

PRINTF_PATH = ./ft_printf
NAMEPRINTF = $(PRINTF_PATH)/libftprintf.a

SRCS_PATH = ./srcs

SRC_C = $(SRCS_PATH)/client.c
SRC_S = $(SRCS_PATH)/server.c
SRC_CBONUS = $(SRCS_PATH)/client_bonus.c
SRC_SBONUS = $(SRCS_PATH)/server_bonus.c

CC = cc

RM = rm -f

CFLAGS = -Wall -Werror -Wextra
LDFLAGS = -L$(PRINTF_PATH) -lftprintf

SRCS_PRINTF := $(wildcard $(PRINTF_PATH)/*.c)

OBJS_PRINTF = ${SRCS_PRINTF:.c=.o}
OBJ_C = ${SRC_C:.c=.o}
OBJ_S = ${SRC_S:.c=.o}
OBJ_CBONUS = ${SRC_CBONUS:.c=.o}
OBJ_SBONUS = ${SRC_SBONUS:.c=.o}


all:		$(NAME_C) $(NAME_S)

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

$(NAME_C): $(OBJ_C) $(NAMEPRINTF)
	$(CC) $(OBJ_C) $(CFLAGS) $(LDFLAGS) -o $(NAME_C)

$(NAME_S): $(OBJ_S) $(NAMEPRINTF)
	$(CC) $(OBJ_S) $(CFLAGS) $(LDFLAGS) -o $(NAME_S)

$(NAMEPRINTF):
	@make -C $(PRINTF_PATH)

bonus:		all $(NAME_CBONUS) $(NAME_SBONUS)

$(NAME_CBONUS): $(OBJ_CBONUS) $(NAMEPRINTF)
	$(CC) $(OBJ_CBONUS) $(CFLAGS) $(LDFLAGS) -o $(NAME_CBONUS)

$(NAME_SBONUS): $(OBJ_SBONUS) $(NAMEPRINTF)
	$(CC) $(OBJ_SBONUS) $(CFLAGS) $(LDFLAGS) -o $(NAME_SBONUS)

clean:
	${RM} ${OBJS}
	@cd $(PRINTF_PATH) && make clean

fclean: clean
	${RM} ${OBJ_C} ${OBJ_S} ${OBJ_CBONUS} ${OBJ_SBONUS} ${NAME_C} ${NAME_S} ${NAME_CBONUS} ${NAME_SBONUS} 
	@cd $(PRINTF_PATH) && make fclean

re: fclean all

.PHONY: all clean fclean re
